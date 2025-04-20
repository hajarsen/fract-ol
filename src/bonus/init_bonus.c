/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <hsennane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:42:59 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/20 13:23:25 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

static void	initialize_params(t_param *param)
{
	param->plan.plan_width = PLANEWIDTH;
	param->offset = (t_offset){0.0, 0.0};
	param->iterations = MAX_ITERATIONS;
	param->zoom_factor = INITIAL_ZOOM_FACTOR;
	param->color_shift = DEFAULT_COLOR_SHIFT;
}

static void	init_fractal_param(t_param *param, char **type)
{
	ft_bzero(param, sizeof(*param));
	param->fractal.name = type[1];
	initialize_params(param);
	if (!ft_strncmp("julia", type[1], 5) && type[2] && type[3])
	{
		param->fractal.c = (t_complex){ft_atof(type[2]), ft_atof(type[3])};
		if (fabs(param->fractal.c.real) > 2.0
			|| fabs(param->fractal.c.imag) > 2.0)
		{
			ft_putstr_fd("Julia constant must be in the range [-2, 2]\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	param->mlx = mlx_init();
	if (!param->mlx)
	{
		ft_putstr_fd("Error: mlx_init failed\n", 2);
		exit(EXIT_FAILURE);
	}
	param->win = mlx_new_window(param->mlx, WIDTH, HEIGHT, "fractol");
	param->img.img = mlx_new_image(param->mlx, WIDTH, HEIGHT);
	param->img.addr = mlx_get_data_addr(param->img.img,
			&param->img.bits_per_pixel, &param->img.line_length,
			&param->img.endian);
}

void	draw_fractal_bonus(char **type)
{
	t_param	param;

	init_fractal_param(&param, type);
	if (!ft_strncmp("mandelbrot", type[1], 10))
		draw_mandelbrot(&param.img, &param.plan, param.offset, param);
	else if (!ft_strncmp("julia", type[1], 5))
		draw_julia(&param.img, &param.plan, param.offset, param);
	else if (!ft_strncmp("tricorn", type[1], 7))
		draw_tricorn(&param.img, &param.plan, param.offset, param);
	mlx_key_hook(param.win, handle_key_event, &param);
	mlx_hook(param.win, 17, 1L << 0, close_window, &param);
	mlx_mouse_hook(param.win, handle_mouse_event_bonus, &param);
	mlx_put_image_to_window(param.mlx, param.win, param.img.img, 0, 0);
	mlx_loop(param.mlx);
}
