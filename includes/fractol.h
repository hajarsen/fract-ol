/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <hsennane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:09:45 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/20 02:38:55 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000
# define PLANEWIDTH 5.0
# define MAX_ITERATIONS 50

// Keycode macros
# define KEY_RIGHT XK_Right
# define KEY_LEFT XK_Left
# define KEY_UP XK_Up
# define KEY_DOWN XK_Down
# define KEY_ESCAPE XK_Escape
# define KEY_SPACE 32
# define KEY_ENTER XK_Return
// Mouse scroll macros
# define SCROLL_UP 4
# define SCROLL_DOWN 5
// Fractal control macros
# define PAN_FACTOR 0.5
# define ZOOM_IN_FACTOR 0.9
# define ZOOM_OUT_FACTOR 1.105
# define ITERATION_STEP 50
# define COLOR_SHIFT_STEP 5
# define COLOR_DEFAULT 0x000000

// Initial defaults
# define INITIAL_ZOOM_FACTOR 0.5
# define DEFAULT_COLOR_SHIFT 70
# define ESCAPE_THRESHOLD_SQ 4.0

typedef struct s_color
{
	double		red;
	double		green;
	double		blue;
}				t_color;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct s_plan
{
	double		plan_width;
	double		plan_start;
}				t_plan;

typedef struct s_mouse_pos
{
	int			x_pos;
	int			y_pos;
}				t_mouse_pos;

typedef struct s_fractal
{
	char		*name;
	t_complex	c;
}				t_fractal;

typedef struct s_offset
{
	double		offset_x;
	double		offset_y;
}				t_offset;

typedef struct s_param
{
	void		*win;
	void		*mlx;
	int			color_shift;
	double		zoom_factor;
	int			iterations;
	t_data		img;
	t_plan		plan;
	t_mouse_pos	mouse;
	t_offset	offset;
	t_fractal	fractal;
}				t_param;
void			draw_fractal(char **type);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				map_to_color(int iteration, int color_shift);
int				handle_key_event(int keycode, t_param *param);
void			draw_mandelbrot(void *img, t_plan *plan, t_offset offset,
					t_param param);
int				handle_mouse_event(int button, int x_pos, int y_pos,
					t_param *param);
t_complex		map_pixel(int i, int j, t_plan *plan, t_offset offset);
void			draw_julia(void *img, t_plan *plan, t_offset offset,
					t_param param);
void			draw_tricorn(void *img, t_plan *plan, t_offset offset,
					t_param param);
double			ft_atof(char *str);
void			handle_error(int error_code);
int				close_window(t_param *param);
int				calculate_mandelbrot(t_complex z, t_param param);
int				calculate_julia(t_complex c, t_complex z, t_param param);
int				calculate_tricorn(t_complex z, t_param param);

void			ft_bzero(void *s, size_t n);
void			ft_putchar_fd(char c, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putstr_fd(char *s, int fd);
int				ft_strlen(char *str);
#endif // FRACTOL_H
