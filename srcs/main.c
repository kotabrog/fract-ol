/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:15:28 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/11 14:05:39 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	vars_data_init(t_vars *vars)
{
	t_data	*data;

	data = &(vars->data);
	data->img = mlx_new_image(vars->mlx, vars->x, vars->y);
	if (data->img == NULL)
		error_put("fail mlx_new_image");
	data->addr = mlx_get_data_addr(data->img, \
		&(data->bits_per_pixel), &(data->line_length), \
		&(data->endian));
}

static void	vars_init(t_vars *vars)
{
	vars->x = SCREEN_X;
	vars->y = SCREEN_Y;
	vars->base_color = create_trgb(0, 100, 0, 0);
	init_screen(vars);
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		error_put("fail mlx_init");
	vars->win = mlx_new_window(vars->mlx, vars->x, vars->y, vars->figure_name);
	if (vars->win == NULL)
		error_put("fail mlx_new_window");
	vars_data_init(vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	arg_parse(&vars, argc, argv);
	vars_init(&vars);
	put_image_to_window(&vars);
	set_all_mlx_hook(&vars);
	mlx_loop(vars.mlx);
}
