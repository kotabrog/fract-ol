/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:16:07 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/10 13:35:18 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "mlx.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define ERROR -1

# define KEY_ESC 65307

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		x;
	int		y;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	*data;
	int		x;
	int		y;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	set_all_mlx_hook(t_vars *vars);

int		create_trgb(int t, int r, int g, int b);

size_t	ft_strlen(const char *c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

#endif
