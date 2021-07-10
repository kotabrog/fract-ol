/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_control1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:07:48 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/10 22:22:55 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * \
						(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	clear_image(t_vars *vars)
{
	int	point[2];

	point[0] = 0;
	while (point[0] < vars->x)
	{
		point[1] = 0;
		while (point[1] < vars->y)
		{
			my_mlx_pixel_put(&(vars->data), point[0], point[1], 0);
			++point[1];
		}
		++point[0];
	}
}

void	put_image_to_window(t_vars *vars)
{
	if (vars->func(vars))
		error_put("An error occurred while creating a shape.");
	mlx_put_image_to_window(vars->mlx, vars->win, \
						vars->data.img, 0, 0);
}

static int	control_key_code(int keycode, t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (keycode == KEY_ESC)
		exit(SUCCESS);
	if (keycode == KEY_RIGHT)
		x = SLIDE_STEP;
	if (keycode == KEY_LEFT)
		x = -SLIDE_STEP;
	if (keycode == KEY_DOWN)
		y = SLIDE_STEP;
	if (keycode == KEY_UP)
		y = -SLIDE_STEP;
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT || \
		keycode == KEY_DOWN || keycode == KEY_UP)
	{
		vars->base_color = color_mod_add(vars->base_color, 10);
		slide_screen(vars, x, y);
		mlx_clear_window(vars->mlx, vars->win);
		clear_image(vars);
		put_image_to_window(vars);
	}
	return (SUCCESS);
}

void	set_all_mlx_hook(t_vars *vars)
{
	mlx_key_hook(vars->win, control_key_code, vars);
}
