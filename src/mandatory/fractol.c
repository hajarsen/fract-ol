/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <hsennane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:19:26 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/20 02:30:21 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	calculate_julia(t_complex c, t_complex z, t_param param)
{
	int		iter;
	double	temp;

	iter = 0;
	while ((z.real * z.real + z.imag * z.imag) < ESCAPE_THRESHOLD_SQ
		&& iter < param.iterations)
	{
		temp = z.real * z.real - z.imag * z.imag;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp + c.real;
		iter++;
	}
	return (iter);
}

int	calculate_mandelbrot(t_complex z, t_param param)
{
	t_complex	c;
	t_complex	com;
	double		tmp;
	int			iteration;

	c = z;
	iteration = 0;
	com = (t_complex){0.0, 0.0};
	while ((com.real * com.real + com.imag * com.imag) < ESCAPE_THRESHOLD_SQ
		&& iteration < param.iterations)
	{
		tmp = com.real * com.real - com.imag * com.imag + c.real;
		com.imag = 2 * com.real * com.imag + c.imag;
		com.real = tmp;
		iteration++;
	}
	return (iteration);
}

int	calculate_tricorn(t_complex z, t_param param)
{
	int			iter;
	double		temp;
	t_complex	c;

	c = z;
	iter = 0;
	while ((z.real * z.real + z.imag * z.imag) < ESCAPE_THRESHOLD_SQ
		&& iter < param.iterations)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = -2 * z.real * z.imag + c.imag;
		z.real = temp;
		iter++;
	}
	return (iter);
}
