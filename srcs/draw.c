/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:07:37 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/11 11:16:10 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	draw_image(t_vars *vars)
{
	int		color;
	int		point[2];
	t_vec	vec;
	int		n;

	color = vars->base_color;
	point[1] = 0;
	while (point[1] < vars->x)
	{
		point[0] = 0;
		while (point[0] < vars->y)
		{
			get_coordinates(vars, point[0], point[1], &vec);
			n = vars->func(vars, &vec);
			if (n < 0)
				return (ERROR);
			if (n > 0)
				my_mlx_pixel_put(&(vars->data), point[0], point[1], color);
			++point[0];
		}
		++point[1];
	}
	return (SUCCESS);
}
