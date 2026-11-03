#!/usr/bin/env bash
# Capture real screenshots of fract-ol on a running X11 desktop.
# Usage: bash scripts/capture_demo.sh
set -euo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")/.."

if [[ -z "${DISPLAY:-}" ]]; then
  echo "An X11 graphical display is required. Run in an X11 desktop session." >&2
  exit 2
fi
for command in xdotool import; do
  if ! command -v "$command" >/dev/null 2>&1; then
    echo "Missing $command. On Ubuntu: sudo apt install xdotool imagemagick" >&2
    exit 2
  fi
done
if [[ ! -x ./fractol || ! -x ./fractol_bonus ]]; then
  echo "Build fractol and fractol_bonus first (see README.md)." >&2
  exit 2
fi

mkdir -p docs/screenshots
app_pid=""
cleanup() {
  if [[ -n "$app_pid" ]]; then
    kill "$app_pid" 2>/dev/null || true
    wait "$app_pid" 2>/dev/null || true
    app_pid=""
  fi
}
trap cleanup EXIT

capture() {
  local filename="$1" action="$2" window="" attempt
  shift 2
  echo "Capturing $filename..."
  "$@" >/dev/null 2>&1 &
  app_pid=$!

  for ((attempt=0; attempt<40; attempt++)); do
    window="$(xdotool search --onlyvisible --name '^fractol$' 2>/dev/null | tail -n1 || true)"
    [[ -n "$window" ]] && break
    if ! kill -0 "$app_pid" 2>/dev/null; then
      echo "Application exited before creating the window." >&2
      cleanup
      return 1
    fi
    sleep 0.5
  done
  if [[ -z "$window" ]]; then
    echo "Could not find a visible window named fractol." >&2
    cleanup
    return 1
  fi

  # Give the first full rendering a chance to finish.
  sleep 2
  if [[ "$action" == "zoom" ]]; then
    # The bonus build zooms around the cursor. Mouse wheel up is button 4.
    xdotool mousemove --window "$window" 650 475
    xdotool click --repeat 4 --delay 700 4
    sleep 3
  fi

  # Capture the actual application window (not a simulated fractal image).
  import -window "$window" "docs/screenshots/$filename"
  echo "Saved docs/screenshots/$filename"
  cleanup
  sleep 0.5
}

capture mandelbrot.png normal ./fractol mandelbrot
capture julia.png normal ./fractol julia -0.8 0.156
capture tricorn.png normal ./fractol_bonus tricorn
capture mandelbrot-zoom.png zoom ./fractol_bonus mandelbrot

echo
echo "Screenshots ready. Inspect the PNGs before uploading or publishing."
echo "Add docs/screenshots/*.png to the same feature branch, then update the README gallery."
