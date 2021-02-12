/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printers_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:41:06 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/20 17:41:11 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include "libft.h"

int		print_e_sub_(int sim, t_spec *s, long double e)
{
	t_i64	lg;
	t_i64	adig;
	t_i64	fdig;
	t_i64	rdig;
	int		ret;

	ret = 0;
	lg = mlog10(mabs_d(e));
	lg = (lg == 0xDEADBEEF) ? 0 : lg;
	adig = mround_even(mabs_d(e) * mpow_d(10, -lg + s->p));
	fdig = adig / (t_i64)mpow_d(10, s->p);
	if (fdig >= 10 && (fdig /= 10))
		++lg;
	rdig = adig % (t_i64)mpow_d(10, s->p);
	if (s->p != 0)
		ret += ft_printf_(sim, "%llu.%0*llu", fdig, s->p, rdig);
	else if (s->p == 0 && s->f_oc == 0)
		ret += ft_printf_(sim, "%llu", fdig);
	else if (s->p == 0 && s->f_oc == 1)
		ret += ft_printf_(sim, "%llu.", fdig);
	ret += print_char_(sim, ft_strchr("efg", s->sp) ? 'e' : 'E');
	ret += print_str_(sim, (lg >= 0 || e == 0.0) ? "+" : "-", 1);
	ret += print_str_(sim, mabs_d(lg) < 10 ? "0" : "", mabs_d(lg) < 10 ? 1 : 0);
	ret += ft_printf_(sim, "%d", mabs_i(lg));
	return (ret);
}

int		print_f_sub_(int sim, t_spec *s, long double e)
{
	t_u64	adig;
	t_u64	ldig;
	t_u64	rdig;
	int		ret;

	ret = 0;
	adig = mroundu_even(mabs_d(e) * mpow_d(10, s->p));
	ldig = adig / (t_u64)mpow_d(10, s->p);
	rdig = adig % (t_u64)mpow_d(10, s->p);
	ret += ft_printf_(sim, "%llu", ldig);
	if (s->f_oc || s->p != 0)
		ret += print_char_(sim, '.');
	if (s->p != 0)
		ret += ft_printf_(sim, "%0*llu", s->p, rdig);
	return (ret);
}
