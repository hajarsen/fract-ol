/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <hsennane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:40:52 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/20 02:49:44 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	handle_key_event(int keycode, t_param *param)
{
	if (keycode == KEY_RIGHT)
		param->offset.offset_x += PAN_FACTOR * param->zoom_factor;
	else if (keycode == KEY_LEFT)
		param->offset.offset_x -= PAN_FACTOR * param->zoom_factor;
	else if (keycode == KEY_UP)
		param->offset.offset_y -= PAN_FACTOR * param->zoom_factor;
	else if (keycode == KEY_DOWN)
		param->offset.offset_y += PAN_FACTOR * param->zoom_factor;
	else if (keycode == KEY_SPACE)
		param->color_shift += COLOR_SHIFT_STEP;
	else if (keycode == KEY_ENTER)
		param->iterations += ITERATION_STEP;
	else if (keycode == KEY_ESCAPE)
		close_window(param);
	if (!ft_strncmp("julia", param->fractal.name, 5))
		draw_julia(&param->img, &param->plan, param->offset, *param);
	else if (!ft_strncmp("mandelbrot", param->fractal.name, 10))
		draw_mandelbrot(&param->img, &param->plan, param->offset, *param);
	else
		draw_tricorn(&param->img, &param->plan, param->offset, *param);
	mlx_put_image_to_window(param->mlx, param->win, param->img.img, 0, 0);
	return (0);
}

int	close_window(t_param *param)
{
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_image(param->mlx, param->img.img);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	exit(EXIT_SUCCESS);
}

static void	draw(t_param *param)
{
	if (!ft_strncmp("julia", param->fractal.name, 5))
		draw_julia(&param->img, &param->plan, param->offset, *param);
	else if (!ft_strncmp("mandelbrot", param->fractal.name, 10))
		draw_mandelbrot(&param->img, &param->plan, param->offset, *param);
	else
		draw_tricorn(&param->img, &param->plan, param->offset, *param);
	mlx_put_image_to_window(param->mlx, param->win, param->img.img, 0, 0);
}

int	handle_mouse_event(int button, int x_pos, int y_pos, t_param *param)
{
	t_complex	old;
	t_complex	new;

	old.real = 0.0;
	old.imag = 0.0;
	new.real = 0.0;
	new.imag = 0.0;
	(void)x_pos;
	(void)y_pos;
	old = map_pixel(WIDTH / 2, HEIGHT / 2, &param->plan, param->offset);
	if (button == SCROLL_UP)
	{
		param->zoom_factor *= ZOOM_IN_FACTOR;
		param->plan.plan_width *= ZOOM_IN_FACTOR;
	}
	else if (button == SCROLL_DOWN)
	{
		param->zoom_factor *= ZOOM_OUT_FACTOR;
		param->plan.plan_width *= ZOOM_OUT_FACTOR;
	}
	new = map_pixel(WIDTH / 2, HEIGHT / 2, &param->plan, param->offset);
	param->offset.offset_x += old.real - new.real;
	param->offset.offset_y += old.imag - new.imag;
	draw(param);
	return (0);
}
