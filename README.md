*This project has been created as part of the 42 curriculum by hsennane.*

# fract-ol

## Description

fract-ol is an interactive fractal viewer written in C using the Linux version of MiniLibX. It renders a 1000 × 1000 window and lets you explore fractals through zooming, movement, color changes, and increased iteration counts.

The mandatory program displays the **Mandelbrot** and **Julia** sets. The bonus program also displays the **Tricorn** fractal and zooms around the mouse pointer.

### How it works

Each pixel is mapped to a complex number. The program repeatedly applies a formula until the result escapes a radius of 2 or reaches the iteration limit. The escape iteration determines the pixel's color.

| Fractal | Formula | Starting values |
| --- | --- | --- |
| Mandelbrot | `z = z² + c` | `z = 0`; `c` is the pixel's complex coordinate |
| Julia | `z = z² + c` | `z` is the pixel's complex coordinate; `c` comes from the command line |
| Tricorn | `z = conjugate(z)² + c` | This implementation initializes both `z` and `c` to the pixel's complex coordinate |

## Instructions

### Requirements

- Linux with a C compiler and GNU Make.
- X11 development libraries and an accessible X display.
- [MiniLibX for Linux](https://github.com/42Paris/minilibx-linux), which is not bundled in this repository.

On Debian or Ubuntu, install the system dependencies:

```sh
sudo apt-get update
sudo apt-get install build-essential git libx11-dev libxext-dev libbsd-dev
```

### Build

Clone and build MiniLibX alongside the project. This revision matches the callback API used by the source and was verified with GCC 14:

```sh
git clone https://github.com/42Paris/minilibx-linux.git ../minilibx-linux
git -C ../minilibx-linux checkout 6e7e6efdfed0b03e88559109319a01a521021df6
make -C ../minilibx-linux
```

From the fract-ol repository root, build the mandatory and bonus programs:

```sh
make INCS='-I includes -I ../minilibx-linux' \
     MLX_FLAGS='-L../minilibx-linux -lmlx -lX11 -lXext -lm'

make bonus INCS='-I includes -I ../minilibx-linux' \
     MLX_FLAGS='-L../minilibx-linux -lmlx -lX11 -lXext -lm'
```

If MiniLibX is already installed in the compiler's standard include and library paths, use `make` and `make bonus` directly.

### Run

```sh
./fractol mandelbrot
./fractol julia -0.8 0.156

./fractol_bonus mandelbrot
./fractol_bonus julia 0.285 0.01
./fractol_bonus tricorn
```

Fractal names are lowercase. Julia requires a real and an imaginary parameter, each in `[-2, 2]`. Missing arguments, unsupported fractal names, and out-of-range Julia constants produce an error and exit.

The application requires a working X display. On a headless machine, Xvfb can provide a virtual display for automated checks; viewing and interacting with the window requires a graphical session.

### Controls

| Input | Action |
| --- | --- |
| Mouse wheel up / down | Zoom in / out |
| Arrow keys | Move around the complex plane |
| Space | Shift the color palette |
| Enter | Add 50 iterations for more detail |
| Escape or window close button | Close the program |

Mandatory zoom is centered on the window. Bonus zoom is centered on the mouse pointer. Increasing the iteration count can slow rendering.

### Clean up

```sh
make clean    # Remove object files
make fclean   # Remove object files and both executables
```

`make re` rebuilds the mandatory program; pass the same `INCS` and `MLX_FLAGS` overrides if MiniLibX is installed outside the standard paths.

## Project structure

```text
includes/       Shared types, constants, and function declarations
src/mandatory/  Fractal calculations, rendering, argument handling, and events
src/bonus/      Bonus entry point, initialization, and mouse-centered zoom
Makefile        Mandatory, bonus, and cleanup targets
```

## Resources

- [MiniLibX for Linux](https://github.com/42Paris/minilibx-linux): graphics library, build requirements, and API documentation.
- [Mandelbrot set](https://en.wikipedia.org/wiki/Mandelbrot_set): escape-time rendering and the complex quadratic map.
- [Julia set](https://en.wikipedia.org/wiki/Julia_set): the relationship between the fixed complex parameter and the rendered set.
- [Tricorn fractal](https://en.wikipedia.org/wiki/Tricorn_(mathematics)): the conjugate quadratic map.
- The fract-ol subject on the 42 intranet: consult your assigned subject version for evaluation requirements.

### Use of AI

AI assistance was used to inspect the existing source, draft this README, and prepare and validate the cloud development environment. The setup checks built both executables and exercised rendering, palette changes, zoom, Escape handling, and selected invalid command-line arguments. No application source code was changed during this documentation and setup work.
