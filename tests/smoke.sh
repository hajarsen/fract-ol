#!/usr/bin/env bash
# Non-graphical CLI checks for fract-ol.
# Run from anywhere: bash tests/smoke.sh
set -euo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")/.."

if [[ ! -x ./fractol || ! -x ./fractol_bonus ]]; then
  echo "Build both programs first: make && make bonus" >&2
  echo "For MiniLibX in ../minilibx-linux, see README.md." >&2
  exit 2
fi

passed=0
failed=0

expect_failure() {
  local label="$1" expected="$2"
  shift 2
  local output status
  if output=$("$@" 2>&1); then
    status=0
  else
    status=$?
  fi
  if (( status != 0 )) && [[ "$output" == *"$expected"* ]]; then
    printf 'PASS %s\n' "$label"
    ((passed+=1))
  else
    printf 'FAIL %s (exit: %d)\n' "$label" "$status"
    printf '  Actual: %s\n' "$output"
    ((failed+=1))
  fi
}

expect_failure "mandatory: no arguments" "Invalid usage" ./fractol
expect_failure "mandatory: unknown set" "Invalid usage" ./fractol unknown
expect_failure "mandatory: extra mandelbrot argument" "Invalid usage" ./fractol mandelbrot extra
expect_failure "mandatory: missing Julia values" "requires two numeric parameters" ./fractol julia
expect_failure "mandatory: missing Julia imaginary value" "requires two numeric parameters" ./fractol julia 0.2
expect_failure "mandatory: Julia real part out of range" "Julia constant must be in the range" ./fractol julia 3 0
expect_failure "mandatory: Julia imaginary part out of range" "Julia constant must be in the range" ./fractol julia 0 -3
expect_failure "bonus: no arguments" "Invalid usage" ./fractol_bonus
expect_failure "bonus: unknown set" "Invalid usage" ./fractol_bonus unknown
expect_failure "bonus: extra tricorn argument" "Invalid usage" ./fractol_bonus tricorn extra
expect_failure "bonus: missing Julia values" "requires two numeric parameters" ./fractol_bonus julia
expect_failure "bonus: Julia out of range" "Julia constant must be in the range" ./fractol_bonus julia 0 3

printf '\nCLI results: %d passed, %d failed\n' "$passed" "$failed"
if ((failed > 0)); then
  exit 1
fi
echo "Note: rendering, mouse and keyboard interactions require manual graphical testing."
