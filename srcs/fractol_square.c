/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:27:14 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/10 22:14:04 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	square_conditional(t_vec *vec)
{
	return (-150 + 1e-9 < vec->x && vec->x < 150 + 1e-9 && \
			-150 + 1e-9 < vec->y && vec->y < 150 + 1e-9);
}

int	put_simple_square(t_vars *vars)
{
	int		color;
	int		point[2];
	t_vec	vec;

	color = vars->base_color;
	point[1] = 0;
	while (point[1] < 500)
	{
		point[0] = 0;
		while (point[0] < 500)
		{
			get_coordinates(vars, point[0], point[1], &vec);
			if (square_conditional(&vec))
				my_mlx_pixel_put(&(vars->data), point[0], point[1], color);
			++point[0];
		}
		++point[1];
	}
	return (SUCCESS);
}
