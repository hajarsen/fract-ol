# Fract-ol — Test plan and demonstration

This file lists **proposed tests** for the current mandatory and bonus builds. It does not claim that the tests have been run or passed.

## 1. Prerequisites

Build MiniLibX and both programs as described in [README.md](../README.md). On Linux with MiniLibX cloned into `../minilibx-linux`, from the project directory:

```bash
make INCS='-I includes -I ../minilibx-linux' MLX_FLAGS='-L../minilibx-linux -lmlx -lX11 -lXext -lm'
make bonus INCS='-I includes -I ../minilibx-linux' MLX_FLAGS='-L../minilibx-linux -lmlx -lX11 -lXext -lm'
```

For a basic non-graphical check:

```bash
bash tests/smoke.sh
```

The smoke script checks error cases and exit codes. It doesn't verify fractal pixels, animation, mouse navigation, or rendering correctness.

## 2. Manual functional tests

| ID | Action | Expected behavior | Evidence |
|---|---|---|---|
| G01 | `./fractol mandelbrot` | 1000 × 1000 Mandelbrot window renders | `mandelbrot.png` |
| G02 | `./fractol julia -0.8 0.156` | Julia fractal renders using these parameters | `julia.png` |
| G03 | `./fractol_bonus tricorn` | Tricorn fractal renders | `tricorn.png` |
| G04 | Mouse scroll up / down | Zoom in / out | Before / after screenshots |
| G05 | Arrow keys | View pans in the matching direction | Before / after screenshots |
| G06 | Space | Color palette changes | Before / after screenshots |
| G07 | Enter | More detail is drawn at a higher iteration limit | Before / after screenshots |
| G08 | Esc | Window closes cleanly | Observe application |
| G09 | Window close button | Window closes | Observe application |
| G10 | Bonus: scroll near a specific feature | Zoom centers around mouse position | `mandelbrot-zoom.png` |
| G11 | Mandatory: scroll at corner | Zoom stays centered on the window | Before / after screenshots |

**Note:** Raising the iteration limit increases CPU work. Rendering may not look instantaneous.

## 3. Input validation tests

After compiling both executables, use `bash tests/smoke.sh` to check:

- No arguments or unknown fractal name
- Extra arguments after Mandelbrot or Tricorn
- Missing or incomplete Julia parameters
- Julia components outside the range [-2, 2]

A failed test is useful evidence of a bug. Do not edit test expectations merely to force the suite to pass.

## 4. Screenshots for GitHub

To generate **real application captures** in an X11 desktop session, install:

```bash
sudo apt install xdotool imagemagick
```

Then run:

```bash
bash scripts/capture_demo.sh
```

The script creates the following files locally (they are **not** currently committed):

```text
docs/screenshots/
├── mandelbrot.png
├── julia.png
├── tricorn.png
└── mandelbrot-zoom.png
```

Inspect each image. If the display is blank, give the program more time to render and capture it again. On Wayland, use an X11 session or take screenshots manually with the desktop screenshot tool.

After confirming the images really show your running program, add them to the same feature branch:

```bash
git switch docs/readme-tests-demo
git add docs/screenshots/*.png
git commit -m "add screenshots"
git push
```

Finally replace the README's pending-gallery note with:

```markdown
### Demo gallery

| Mandelbrot | Julia |
|---|---|
| ![Mandelbrot](docs/screenshots/mandelbrot.png) | ![Julia](docs/screenshots/julia.png) |

| Tricorn (bonus) | Zoom (bonus) |
|---|---|
| ![Tricorn](docs/screenshots/tricorn.png) | ![Zoom](docs/screenshots/mandelbrot-zoom.png) |
```

Never describe a mathematically generated illustration as an actual screenshot of the running executable.
