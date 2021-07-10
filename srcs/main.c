/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:15:28 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/10 16:45:03 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error_put(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	vars_init(t_vars *vars)
{
	vars->x = 500;
	vars->y = 500;
}

void	put_simple_square(t_vars *vars)
{
	int	color;
	int	point[2];

	color = create_trgb(0, 255, 0, 0);
	point[0] = 100;
	while (point[0] < 400)
	{
		point[1] = 100;
		while (point[1] < 400)
		{
			my_mlx_pixel_put(&(vars->data), point[0], point[1], color);
			++point[1];
		}
		++point[0];
	}
}

int	main(void)
{
	t_vars	vars;

	vars_init(&vars);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		error_put("fail mlx_init");
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "Hello world!");
	if (vars.win == NULL)
		error_put("fail mlx_new_window");
	vars.data.img = mlx_new_image(vars.mlx, vars.x, vars.y);
	if (vars.data.img == NULL)
		error_put("fail mlx_new_image");
	vars.data.addr = mlx_get_data_addr(vars.data.img, \
		&(vars.data.bits_per_pixel), &(vars.data.line_length), \
		&(vars.data.endian));
	put_simple_square(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, \
						vars.data.img, 0, 0);
	set_all_mlx_hook(&vars);
	mlx_loop(vars.mlx);
}
