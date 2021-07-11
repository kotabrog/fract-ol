/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:25:50 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/11 18:41:43 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_value(double *x, double *y, int power, t_vec *vec)
{
	double	rx;
	double	ry;
	double	temp;

	rx = *x;
	ry = *y;
	while (--power)
	{
		temp = rx;
		rx = rx * *x - ry * *y;
		ry = temp * *y + ry * *x;
	}
	*x = rx + vec->x;
	*y = ry + vec->y;
}

int	fractal_mandelbrot2(t_vars *vars, t_vec *vec)
{
	double	x;
	double	y;
	int		i;

	vars->x = vars->x;
	i = 0;
	x = 0;
	y = 0;
	while (!stop_iteration(x, y, i, vars->max_iter))
	{
		update_value(&x, &y, (int)round(vars->param[2]), vec);
		++i;
	}
	if (i >= vars->max_iter)
		return (0);
	return (i);
}

int	fractal_julia2(t_vars *vars, t_vec *vec)
{
	double	x;
	double	y;
	int		i;
	t_vec	c;

	vars->x = vars->x;
	vec_set(&c, vars->param[0], vars->param[1]);
	i = 0;
	x = vec->x;
	y = vec->y;
	while (!stop_iteration(x, y, i, vars->max_iter))
	{
		update_value(&x, &y, (int)round(vars->param[2]), &c);
		++i;
	}
	if (i >= vars->max_iter)
		return (0);
	return (i);
}
