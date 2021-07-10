/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:27:14 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/10 17:37:54 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	put_simple_square(t_vars *vars)
{
	int	color;
	int	point[2];

	color = vars->base_color;
	point[0] = 100;
	while (point[0] < 400)
	{
		point[1] = 100;
		while (point[1] < 400)
		{
			my_mlx_pixel_put(&(vars->data), point[0], point[1], color);
			++point[1];
		}
		++point[0];
	}
	return (SUCCESS);
}
