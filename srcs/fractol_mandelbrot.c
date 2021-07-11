/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:25:50 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/11 11:40:29 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	stop_iteration(double x, double y, int iter)
{
	return (iter >= MAX_ITERATION || x * x + y * y > 4);
}

static void	update_value(double *x, double *y, t_vec *vec)
{
	double	temp;

	temp = *x;
	*x = *x * *x - *y * *y + vec->x;
	*y = 2 * temp * *y + vec->y;
}

int	fractal_mandelbrot(t_vars *vars, t_vec *vec)
{
	double	x;
	double	y;
	int		i;

	vars->x = vars->x;
	i = 0;
	x = 0;
	y = 0;
	while (!stop_iteration(x, y, i))
	{
		update_value(&x, &y, vec);
		++i;
	}
	if (i >= MAX_ITERATION)
		return (0);
	return (i);
}
