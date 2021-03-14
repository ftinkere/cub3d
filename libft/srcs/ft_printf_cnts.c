/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cnts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:21:25 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/20 16:21:29 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	cnt_u(t_spec *spec, unsigned long long d)
{
	int		w;
	int		ret;

	w = spec->w;
	spec->w = 0;
	ret = print_u_(1, spec, d);
	spec->w = w;
	return (ret);
}

int	cnt_d(t_spec *spec, long long d)
{
	int		w;
	int		ret;

	w = spec->w;
	spec->w = 0;
	ret = print_d_(1, spec, d);
	spec->w = w;
	return (ret);
}

int	cnt_e(t_spec *spec, long double e)
{
	int		w;
	char	s;
	int		ret;

	w = spec->w;
	s = spec->sp;
	spec->w = 0;
	spec->sp = 'e';
	ret = print_e_(1, spec, e);
	spec->w = w;
	spec->sp = s;
	return (ret);
}

int	cnt_f(t_spec *spec, long double e)
{
	int		w;
	char	s;
	int		ret;

	w = spec->w;
	s = spec->sp;
	spec->w = 0;
	spec->sp = 'f';
	ret = print_f_(1, spec, e);
	spec->w = w;
	spec->sp = s;
	return (ret);
}

int	cnt_g_prec(t_spec *spec, long double e)
{
	int		res;
	t_u64	adig;

	res = spec->p;
	adig = mroundu_even(mabs_d(e) * mpow_d(10, spec->p));
	if (adig == 0)
		return (0);
	while ((adig % 10) == 0)
	{
		res--;
		adig /= 10;
	}
	return (res);
}
