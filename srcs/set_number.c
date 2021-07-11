/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:09:23 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/07/11 16:16:12 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_int(char **s, int *num)
{
	int	i;

	*num = 0;
	i = 0;
	if (**s == '0' && ft_isdigit((*s)[1]))
		return (ERROR);
	while (ft_isdigit(**s))
	{
		if (i > 8)
			return (ERROR);
		else
			*num = *num * 10 + (**s - '0');
		++(*s);
		++i;
	}
	return (SUCCESS);
}

static int	set_double(char **s, double *v)
{
	int		d;
	char	*p;

	if (set_int(s, &d))
		return (ERROR);
	*v = d;
	if (**s == '.')
	{
		(*s)++;
		p = *s;
		while (**s == '0')
			(*s)++;
		if (set_int(s, &d))
			return (ERROR);
		*v += pow(10, -1 * (int)(*s - p)) * d;
	}
	return (SUCCESS);
}

int	set_number(char *s, double *v)
{
	int	sign;

	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	if (!ft_isdigit(*s))
		return (ERROR);
	if (set_double(&s, v))
		return (ERROR);
	if (*s != '\0')
		return (ERROR);
	*v *= sign;
	return (SUCCESS);
}
