/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:13:25 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/11 00:22:59 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_screen(t_vars *vars)
{
	vars->screen.width = vars->x;
	vars->screen.height = vars->y;
	vec_set(&(vars->screen.left_top), -vars->x / 2, -vars->y / 2);
	vec_set(&(vars->screen.step), vars->x / vars->x, vars->y / vars->y);
}

void	slide_screen(t_vars *vars, int x, int y)
{
	t_vec		vec;
	t_screen	*screen;

	screen = &(vars->screen);
	if ((x < 0 && screen->left_top.x < -2 * vars->x) || \
		(x > 0 && screen->left_top.x + screen->width > 2 * vars->x) || \
		(y < 0 && screen->left_top.y < -2 * vars->y) || \
		(x > 0 && screen->left_top.y + screen->width > 2 * vars->y))
		return ;
	vec_set(&vec, x * screen->step.x, y * screen->step.y);
	vec_add(&(screen->left_top), &vec, &(screen->left_top));
}

void	zoom_screen(t_vars *vars, int x, int y, double r)
{
	t_screen	*screen;
	t_vec		vec;

	screen = &(vars->screen);
	if (r < 1 && (screen->width < 1e-4 || screen->height < 1e-4))
		return ;
	get_coordinates(vars, x, y, &vec);
	vec_set(&(screen->left_top), \
			r * screen->left_top.x + (1 - r) * vec.x, \
			r * screen->left_top.y + (1 - r) * vec.y);
	screen->width *= r;
	screen->height *= r;
	vec_set(&(screen->step), \
			screen->width / vars->x, \
			screen->height / vars->y);
}

void	get_coordinates(t_vars *vars, int x, int y, t_vec *dst)
{
	vec_set(dst, \
		vars->screen.left_top.x + x * vars->screen.step.x, \
		vars->screen.left_top.y + y * vars->screen.step.y);
}
