/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:27:14 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/11 16:46:38 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_square(t_vars *vars, t_vec *vec)
{
	vars->x = vars->x;
	if (-1 + 1e-9 < vec->x && vec->x < 1 + 1e-9 && \
			-1 + 1e-9 < vec->y && vec->y < 1 + 1e-9)
		return (vars->max_iter / 2);
	else
		return (0);
}
