/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:25:50 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/11 16:47:34 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	stop_iteration(double x, double y, int iter, int max_iter)
{
	return (iter >= max_iter || x * x + y * y > 4);
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
	while (!stop_iteration(x, y, i, vars->max_iter))
	{
		update_value(&x, &y, vec);
		++i;
	}
	if (i >= vars->max_iter)
		return (0);
	return (i);
}

int	fractal_julia(t_vars *vars, t_vec *vec)
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
		update_value(&x, &y, &c);
		++i;
	}
	if (i >= vars->max_iter)
		return (0);
	return (i);
}
