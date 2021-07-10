/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_control1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:07:48 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/10 23:15:09 by ksuzuki          ###   ########.fr       */
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

void	put_image_to_window(t_vars *vars)
{
	if (vars->func(vars))
		error_put("An error occurred while creating a shape.");
	mlx_put_image_to_window(vars->mlx, vars->win, \
						vars->data.img, 0, 0);
}

void	clear_image(t_vars *vars)
{
	int	point[2];

	point[0] = 0;
	while (point[0] < vars->x)
	{
		point[1] = 0;
		while (point[1] < vars->y)
		{
			my_mlx_pixel_put(&(vars->data), point[0], point[1], 0);
			++point[1];
		}
		++point[0];
	}
}
