/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_control1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:07:48 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/10 13:32:06 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * \
						(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	control_key_code(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit(SUCCESS);
	vars->x = vars->x;
	return (SUCCESS);
}

void	set_all_mlx_hook(t_vars *vars)
{
	mlx_key_hook(vars->win, control_key_code, vars);
}
