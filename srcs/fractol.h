/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:16:07 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/10 17:44:15 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

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

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	data;
	int		x;
	int		y;
	int		base_color;
	int		(*func)(struct s_vars *);
	char	*figure_name;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	put_image_to_window(t_vars *vars);
void	set_all_mlx_hook(t_vars *vars);

int		create_trgb(int t, int r, int g, int b);
int		color_mod_add(int trgb, int value);

int		trgb_to_t_int(int trgb);
int		trgb_to_r_int(int trgb);
int		trgb_to_g_int(int trgb);
int		trgb_to_b_int(int trgb);
int		trgb_to_t(int trgb);
int		trgb_to_r(int trgb);
int		trgb_to_g(int trgb);
int		trgb_to_b(int trgb);

int		error_put(char *str);

size_t	ft_strlen(const char *c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

int	put_simple_square(t_vars *vars);

#endif
