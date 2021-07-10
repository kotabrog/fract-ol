/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utility1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:30:10 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/10 22:00:50 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	vec_set(t_vec *vec, double x, double y)
{
	vec->x = x;
	vec->y = y;
}

void	vec_copy(t_vec *dst, t_vec *src)
{
	vec_set(dst, src->x, src->y);
}

void	vec_add(t_vec *vec1, t_vec *vec2, t_vec *vec_dst)
{
	vec_set(vec_dst, vec1->x + vec2->x, vec1->y + vec2->y);
}

void	vec_sub(t_vec *vec1, t_vec *vec2, t_vec *vec_dst)
{
	vec_set(vec_dst, vec1->x - vec2->x, vec1->y - vec2->y);
}