/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:15:28 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/10 17:43:23 by ksuzuki          ###   ########.fr       */
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
	vars->x = 500;
	vars->y = 500;
	vars->base_color = create_trgb(0, 100, 0, 0);
	vars->func = put_simple_square;
	vars->figure_name = "square";
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		error_put("fail mlx_init");
	vars->win = mlx_new_window(vars->mlx, vars->x, vars->y, "Hello world!");
	if (vars->win == NULL)
		error_put("fail mlx_new_window");
	vars_data_init(vars);
}

int	main(void)
{
	t_vars	vars;

	vars_init(&vars);
	put_image_to_window(&vars);
	set_all_mlx_hook(&vars);
	mlx_loop(vars.mlx);
}
