/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <hsennane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:26:35 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/20 03:20:27 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# include "fractol.h"

void	draw_fractal_bonus(char **type);
int		handle_mouse_event_bonus(int button, int x_pos, int y_pos,
			t_param *param);
void	handle_error_bonus(int error_code);

#endif
