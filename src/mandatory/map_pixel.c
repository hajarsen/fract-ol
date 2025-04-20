/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <hsennane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:14:56 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/19 17:15:48 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

t_complex	map_pixel(int x, int y, t_plan *plan, t_offset offset)
{
	t_complex	c;

	c.real = (((double)x - (WIDTH * 0.5)) * (plan->plan_width / (double)WIDTH))
		+ offset.offset_x;
	c.imag = (((double)y - (HEIGHT * 0.5)) * (plan->plan_width
				/ (double)HEIGHT)) + offset.offset_y;
	return (c);
}
