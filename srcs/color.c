/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:34:41 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/11 16:38:41 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color_mod_add(int trgb, int value)
{
	int	trgb_array[3];

	trgb_array[0] = (trgb_to_r_int(trgb) + value) % 256;
	trgb_array[1] = (trgb_to_g_int(trgb) + value) % 256;
	trgb_array[2] = (trgb_to_b_int(trgb) + value) % 256;
	return (create_trgb(0, trgb_array[0], trgb_array[1], trgb_array[3]));
}

int	create_div_color(int base, int max_div, int num)
{
	double	ratio;
	int		r;
	int		g;
	int		b;

	ratio = (double)num / max_div;
	r = trgb_to_r_int(base);
	g = trgb_to_g_int(base);
	b = trgb_to_b_int(base);
	r = (int)round(fmin(ratio * (256 - r) + r, 255));
	g = (int)round(fmin(ratio * (256 - g) + g, 255));
	b = (int)round(fmin(ratio * (256 - b) + b, 255));
	return (create_trgb(0, r, g, b));
}
