/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_control2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:00:19 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/11 17:24:54 by ksuzuki          ###   ########.fr       */
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

static int	set_number_key(int *color, int keycode)
{
	if (keycode < KEY_ZERO || KEY_ZERO + 9 < keycode)
		return (FALSE);
	if (keycode == KEY_ZERO)
		*color = create_trgb(0, 100, 0, 0);
	else if (keycode == KEY_ZERO + 1)
		*color = create_trgb(0, 0, 100, 0);
	else if (keycode == KEY_ZERO + 2)
		*color = create_trgb(0, 0, 0, 100);
	else if (keycode == KEY_ZERO + 3)
		*color = create_trgb(0, 100, 100, 100);
	else if (keycode == KEY_ZERO + 4)
		*color = create_trgb(0, 20, 50, 0);
	else if (keycode == KEY_ZERO + 5)
		*color = create_trgb(0, 30, 70, 150);
	else if (keycode == KEY_ZERO + 6)
		*color = create_trgb(0, 200, 10, 40);
	else if (keycode == KEY_ZERO + 7)
		*color = create_trgb(0, 50, 150, 20);
	else if (keycode == KEY_ZERO + 8)
		*color = create_trgb(0, 30, 200, 10);
	else if (keycode == KEY_ZERO + 9)
		*color = create_trgb(0, 20, 0, 150);
	return (TRUE);
}

static int	control_key_code(int keycode, t_vars *vars)
{
	int	x;
	int	y;
	int	color;

	if (keycode == KEY_ESC)
		exit(SUCCESS);
	else if (set_arrow_key(&x, &y, keycode))
	{
		slide_screen(vars, x, y);
		mlx_clear_window(vars->mlx, vars->win);
		clear_image(vars);
		put_image_to_window(vars);
	}
	else if (set_number_key(&color, keycode))
	{
		vars->base_color = color;
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
