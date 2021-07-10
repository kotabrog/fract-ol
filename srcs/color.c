/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:34:41 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/10 21:14:12 by ksuzuki          ###   ########.fr       */
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
