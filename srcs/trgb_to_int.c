/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:27:26 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/10 21:14:40 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	trgb_to_t_int(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	trgb_to_r_int(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	trgb_to_g_int(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	trgb_to_b_int(int trgb)
{
	return (trgb & 0xFF);
}
