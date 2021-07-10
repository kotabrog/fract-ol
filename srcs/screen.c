/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:13:25 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/10 22:06:02 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_screen(t_vars *vars)
{
	vec_set(&(vars->screen.center), 0, 0);
	vars->screen.width = vars->x;
	vars->screen.height = vars->y;
	vec_set(&(vars->screen.left_top), -vars->x / 2, -vars->y / 2);
	vec_set(&(vars->screen.step), vars->x / vars->x, vars->y / vars->y);
}

void	slide_screen(t_vars *vars, int x, int y)
{
	t_vec	vec;

	vec_set(&vec, x * vars->screen.step.x, y * vars->screen.step.y);
	vec_add(&(vars->screen.center), &vec, &(vars->screen.center));
	vec_add(&(vars->screen.left_top), &vec, &(vars->screen.left_top));
}

void	get_coordinates(t_vars *vars, int x, int y, t_vec *dst)
{
	vec_set(dst, \
		vars->screen.left_top.x + x * vars->screen.step.x, \
		vars->screen.left_top.y + y * vars->screen.step.y);
}