/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:13:25 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/11 16:59:46 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_screen(t_vars *vars)
{
	t_screen	*scr;

	scr = &(vars->screen);
	scr->width = START_WIDTH;
	scr->height = START_HEIGHT;
	vec_set(&(scr->left_top), -scr->width / 2, -scr->height / 2);
	vec_set(&(scr->step), scr->width / vars->x, scr->height / vars->y);
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
	if (r < 1 && (screen->width < 1e-15 || screen->height < 1e-15))
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
	if (r > 1)
		vars->max_iter -= ZOOM_ITER_PLUS;
	else
		vars->max_iter += ZOOM_ITER_PLUS;
	if (vars->max_iter <= 10)
		vars->max_iter = 10;
}

void	get_coordinates(t_vars *vars, int x, int y, t_vec *dst)
{
	vec_set(dst, \
		vars->screen.left_top.x + x * vars->screen.step.x, \
		vars->screen.left_top.y + y * vars->screen.step.y);
}
