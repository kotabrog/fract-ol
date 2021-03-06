/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:30:46 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/05/21 20:29:32 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_malloc(void *pointer, size_t type_size, size_t n)
{
	*(void **)pointer = malloc(type_size * n);
	return (!*(void **)pointer);
}

int	ft_free(void *pointer)
{
	if ((void **)pointer == NULL)
		return (SUCCESS);
	free(*(void **)pointer);
	*(void **)pointer = NULL;
	return (SUCCESS);
}
