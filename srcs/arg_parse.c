/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:26:42 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/11 18:44:28 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help_and_exit(void)
{
	ft_putendl_fd("fractol accepts parameters as follows.", 1);
	ft_putendl_fd("./fractol [type] [param]", 1);
	ft_putendl_fd("-- type list --\n", 1);
	ft_putendl_fd("- m (mandelbrot)", 1);
	ft_putendl_fd("The Mandelbrot set is given as the set of points C\n\
that converge with the following asymptotic formula", 1);
	ft_putendl_fd("z_0 = 0, z_n+1 = (z_n)^2 + c", 1);
	ft_putendl_fd("example: ./fractol m\n", 1);
	ft_putendl_fd("- n (mandelbrot2)", 1);
	ft_putendl_fd("change the squared to the nth power.", 1);
	ft_putendl_fd("example: ./fractol n 3\n", 1);
	ft_putendl_fd("- j (julia)", 1);
	ft_putendl_fd("param: [a(double)] [b(double)]", 1);
	ft_putendl_fd("The Julia set is given as the set of points z_0\n\
that converge with the following asymptotic formula", 1);
	ft_putendl_fd("z_n+1 = (z_n)^2 + c, c = a + bi", 1);
	ft_putendl_fd("example: ./fractol j 0.1 0.4", 1);
	ft_putendl_fd("If you don't specify a or b,\n\
the default values will be applied. (a = 0.3, b = 0.2)\n", 1);
	ft_putendl_fd("- k (julia2)", 1);
	ft_putendl_fd("change the squared to the nth power.", 1);
	ft_putendl_fd("example: ./fractol k 0.1 0.4 3\n", 1);
	exit(EXIT_SUCCESS);
}

void	check_fractal_type(t_vars *vars, char *argv)
{
	if (argv[0] == '\0' || argv[1] != '\0')
		print_help_and_exit();
	if (argv[0] == 'm')
	{
		vars->func = fractal_mandelbrot;
		vars->figure_name = "mandelbrot";
	}
	else if (argv[0] == 'j')
	{
		vars->func = fractal_julia;
		vars->figure_name = "julia";
	}
	else if (argv[0] == 'n')
	{
		vars->func = fractal_mandelbrot2;
		vars->figure_name = "mandelbrot2";
	}
	else if (argv[0] == 'k')
	{
		vars->func = fractal_julia2;
		vars->figure_name = "julia2";
	}
	else
		print_help_and_exit();
}

static void	set_param(t_vars *vars, int argc, char **argv)
{
	if ((argv[1][0] == 'n' && argc > 3) || (argv[1][0] == 'j' && argc > 4))
		print_help_and_exit();
	if (ft_malloc(&(vars->param), sizeof(double), 3))
		error_put("malloc error");
	vars->param[0] = 0.3;
	vars->param[1] = 0.1;
	vars->param[2] = 2;
	if (argc > 2 && ((argv[1][0] == 'n' && \
					set_number(argv[2], &(vars->param[2]))) || \
					(argv[1][0] != 'n' && \
					set_number(argv[2], &(vars->param[0])))))
		print_help_and_exit();
	if (argc > 3 && set_number(argv[3], &(vars->param[1])))
		print_help_and_exit();
	if (argc > 4 && set_number(argv[4], &(vars->param[2])))
		print_help_and_exit();
	if (vars->param[2] < 2)
		vars->param[2] = 2;
	if (vars->param[2] > 100)
		vars->param[2] = 100;
}

void	arg_parse(t_vars *vars, int argc, char **argv)
{
	if (argc == 1 || argc > 5)
		print_help_and_exit();
	check_fractal_type(vars, argv[1]);
	if (argv[1][0] == 'm' && argc > 2)
		print_help_and_exit();
	else
		set_param(vars, argc, argv);
}
