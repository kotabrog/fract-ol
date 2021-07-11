/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_control2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:00:19 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/11 16:42:22 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_arrow_key(int *x, int *y, int keycode)
{
	*x = 0;
	*y = 0;
	if (keycode == KEY_RIGHT)
		*x = SLIDE_STEP;
	if (keycode == KEY_LEFT)
		*x = -SLIDE_STEP;
	if (keycode == KEY_DOWN)
		*y = SLIDE_STEP;
	if (keycode == KEY_UP)
		*y = -SLIDE_STEP;
	return (keycode == KEY_RIGHT || keycode == KEY_LEFT || \
			keycode == KEY_DOWN || keycode == KEY_UP);
}

static int	control_key_code(int keycode, t_vars *vars)
{
	int	x;
	int	y;

	if (keycode == KEY_ESC)
		exit(SUCCESS);
	if (set_arrow_key(&x, &y, keycode))
	{
		slide_screen(vars, x, y);
		mlx_clear_window(vars->mlx, vars->win);
		clear_image(vars);
		put_image_to_window(vars);
	}
	return (SUCCESS);
}

static int	control_mouse_hook(int button, int x, int y, t_vars *vars)
{
	double	rate;

	rate = 0;
	if (button == SCROLL_UP)
		rate = ZOOMIN_RATE;
	else if (button == SCROLL_DOWN)
		rate = ZOOMOUT_RATE;
	if (rate != 0)
	{
		zoom_screen(vars, x, y, rate);
		mlx_clear_window(vars->mlx, vars->win);
		clear_image(vars);
		put_image_to_window(vars);
	}
	return (SUCCESS);
}

void	set_all_mlx_hook(t_vars *vars)
{
	mlx_key_hook(vars->win, control_key_code, vars);
	mlx_mouse_hook(vars->win, control_mouse_hook, vars);
}
