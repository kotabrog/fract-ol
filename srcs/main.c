/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:15:28 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/10 13:51:44 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error_put(char *str)
{
	ft_putendl_fd("Error\n", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	vars_init(t_vars *vars)
{
	vars->x = 500;
	vars->y = 500;
}

// void	put_simple_square(t_vars *vars)
// {
// }

int	main(void)
{
	t_vars	vars;
	// int		color;

	vars_init(&vars);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		error_put("fail mlx_init");
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "Hello world!");
	if (vars.win == NULL)
		error_put("fail mlx_new_window");
	// color = create_trgb(0, 255, 0, 0);
	set_all_mlx_hook(&vars);
	mlx_loop(vars.mlx);
}
