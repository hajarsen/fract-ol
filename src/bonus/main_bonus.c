/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <hsennane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:27:21 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/20 03:22:54 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

int	main(int ac, char **av)
{
	if (ac < 2 || !av[1][0])
		handle_error_bonus(1);
	else if (!ft_strncmp("mandelbrot", av[1], ft_strlen(av[1]))
		&& ft_strlen(av[1]) == 10)
	{
		if (ac > 2)
			handle_error_bonus(1);
		draw_fractal_bonus(av);
	}
	else if (!ft_strncmp("julia", av[1], ft_strlen(av[1]))
		&& ft_strlen(av[1]) == 5)
	{
		if (ac < 4 || ac > 4 || !av[2][0] || !av[3][0])
			handle_error_bonus(2);
		draw_fractal_bonus(av);
	}
	else if (!ft_strncmp("tricorn", av[1], ft_strlen(av[1]))
		&& ft_strlen(av[1]) == 7)
	{
		if (ac > 2)
			handle_error_bonus(1);
		draw_fractal_bonus(av);
	}
	else
		handle_error_bonus(1);
}
