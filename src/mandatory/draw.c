/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <hsennane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:37:53 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/20 02:32:06 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	draw_mandelbrot(void *img, t_plan *plan, t_offset offset, t_param param)
{
	t_complex	z;
	int			iteration;
	int			x;
	int			y;

	z = (t_complex){0.0, 0.0};
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			z = map_pixel(x, y, plan, offset);
			iteration = calculate_mandelbrot(z, param);
			if (iteration == param.iterations)
				my_mlx_pixel_put(img, x, y, COLOR_DEFAULT);
			else
				my_mlx_pixel_put(img, x, y, map_to_color(iteration,
						param.color_shift));
			y++;
		}
		x++;
	}
}

void	draw_julia(void *img, t_plan *plan, t_offset offset, t_param param)
{
	t_complex	z;
	int			iteration;
	int			x;
	int			y;

	z = (t_complex){0.0, 0.0};
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			z = map_pixel(x, y, plan, offset);
			iteration = calculate_julia(param.fractal.c, z, param);
			if (iteration == param.iterations)
				my_mlx_pixel_put(img, x, y, COLOR_DEFAULT);
			else
				my_mlx_pixel_put(img, x, y, map_to_color(iteration,
						param.color_shift));
			y++;
		}
		x++;
	}
}

void	draw_tricorn(void *img, t_plan *plan, t_offset offset, t_param param)
{
	int			x;
	int			y;
	t_complex	z;
	int			iteration;

	z = (t_complex){0.0, 0.0};
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			z = map_pixel(x, y, plan, offset);
			iteration = calculate_tricorn(z, param);
			if (iteration == param.iterations)
				my_mlx_pixel_put(img, x, y, COLOR_DEFAULT);
			else
				my_mlx_pixel_put(img, x, y, map_to_color(iteration,
						param.color_shift));
			y++;
		}
		x++;
	}
}
