/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:16:07 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/11 18:18:07 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "../minilibx-linux/mlx.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define ERROR -1

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ZERO 48
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define SLIDE_STEP 20
# define SCREEN_X 500
# define SCREEN_Y 500
# define ZOOMIN_RATE 0.8
# define ZOOMOUT_RATE 1.2

# define MAX_ITERATION_INIT 100
# define ZOOM_ITER_PLUS 4
# define STOP_DIVERGENCE 2

# define START_WIDTH 4
# define START_HEIGHT 4

typedef struct s_vec {
	double	x;
	double	y;
}				t_vec;

typedef struct s_screen {
	t_vec	left_top;
	t_vec	step;
	double	width;
	double	height;
}				t_screen;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_data		data;
	int			x;
	int			y;
	int			base_color;
	int			(*func)(struct s_vars *, t_vec *);
	char		*figure_name;
	t_screen	screen;
	double		*param;
	int			max_iter;
}				t_vars;

void	arg_parse(t_vars *vars, int argc, char **argv);
int		set_number(char *s, double *v);

int		stop_iteration(double x, double y, int iter, int max_iter);
int		fractal_square(t_vars *vars, t_vec *vec);
int		fractal_mandelbrot(t_vars *vars, t_vec *vec);
int		fractal_julia(t_vars *vars, t_vec *vec);
int		fractal_mandelbrot2(t_vars *vars, t_vec *vec);
int		fractal_julia2(t_vars *vars, t_vec *vec);

void	clear_image(t_vars *vars);
int		draw_image(t_vars *vars);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	put_image_to_window(t_vars *vars);
void	set_all_mlx_hook(t_vars *vars);

void	init_screen(t_vars *vars);
void	slide_screen(t_vars *vars, int x, int y);
void	zoom_screen(t_vars *vars, int x, int y, double r);
void	get_coordinates(t_vars *vars, int x, int y, t_vec *dst);

void	vec_set(t_vec *vec, double x, double y);
void	vec_copy(t_vec *dst, t_vec *src);
void	vec_add(t_vec *vec1, t_vec *vec2, t_vec *vec_dst);
void	vec_sub(t_vec *vec1, t_vec *vec2, t_vec *vec_dst);

int		create_trgb(int t, int r, int g, int b);
int		color_mod_add(int trgb, int value);
int		create_div_color(int base, int max_div, int num);

int		trgb_to_t_int(int trgb);
int		trgb_to_r_int(int trgb);
int		trgb_to_g_int(int trgb);
int		trgb_to_b_int(int trgb);
int		trgb_to_t(int trgb);
int		trgb_to_r(int trgb);
int		trgb_to_g(int trgb);
int		trgb_to_b(int trgb);

int		error_put(char *str);

int		ft_malloc(void *pointer, size_t type_size, size_t n);
int		ft_free(void *pointer);

size_t	ft_strlen(const char *c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int c);

#endif
