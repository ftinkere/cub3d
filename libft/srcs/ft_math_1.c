/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:20:53 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/20 16:20:59 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

t_i64	mabs_i(t_i64 x)
{
	if (x < 0)
		return (-x);
	return (x);
}

long double	mabs_d(long double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

long double	mpow_d(t_i64 x, t_i64 p)
{
	double	res;

	if (p == 0)
		return (1);
	if (p < 0)
		return (1.0 / mpow_d(x, -p));
	res = 1;
	while (p-- > 0)
		res *= x;
	return (res);
}

t_i64	mlog10(long double x)
{
	int			i;
	long double	t;

	if (x == 0.0 || x == -0.0)
		return (0);
	i = -310;
	while (i < 310)
	{
		t = mabs_d(x / mpow_d(10, i));
		if (1 <= t && t < 10)
			return (i);
		i++;
	}
	return (0xDEADBEEF);
}

t_i64	mfloor(long double x)
{
	if (x < 0)
		return ((t_i64)x - 1);
	return ((t_i64)x);
}
