/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <hsennane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:36:45 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/20 03:20:11 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	handle_error(int error_code)
{
	if (error_code == 1)
	{
		ft_putstr_fd("Error: Invalid usage.\n", STDERR_FILENO);
		ft_putstr_fd("Usage:\n", STDERR_FILENO);
		ft_putstr_fd("  ./fractol <fractal_name> [parameters]\n",
			STDERR_FILENO);
		ft_putstr_fd("Available fractals:\n", STDERR_FILENO);
		ft_putstr_fd("  mandelbrot\n", STDERR_FILENO);
		ft_putstr_fd("  julia <real_part> <imag_part>\n", STDERR_FILENO);
	}
	else if (error_code == 2)
	{
		ft_putstr_fd("Error: Julia set requires two numeric parameters.\n",
			STDERR_FILENO);
		ft_putstr_fd("Usage: ./fractol julia <real_part> <imag_part>\n",
			STDERR_FILENO);
	}
	exit(EXIT_FAILURE);
}

void	handle_error_bonus(int error_code)
{
	if (error_code == 1)
	{
		ft_putstr_fd("Error: Invalid usage.\n", STDERR_FILENO);
		ft_putstr_fd("Usage:\n", STDERR_FILENO);
		ft_putstr_fd("  ./fractol <fractal_name> [parameters]\n",
			STDERR_FILENO);
		ft_putstr_fd("Available fractals:\n", STDERR_FILENO);
		ft_putstr_fd("  mandelbrot\n", STDERR_FILENO);
		ft_putstr_fd("  julia <real_part> <imag_part>\n", STDERR_FILENO);
		ft_putstr_fd("  tricorn\n", STDERR_FILENO);
	}
	else if (error_code == 2)
	{
		ft_putstr_fd("Error: Julia set requires two numeric parameters.\n",
			STDERR_FILENO);
		ft_putstr_fd("Usage: ./fractol julia <real_part> <imag_part>\n",
			STDERR_FILENO);
	}
	exit(EXIT_FAILURE);
}
