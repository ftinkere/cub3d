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

int	e_inter(int sim, t_i64 lg, t_spec *s, long double e)
{
	int	ret;

	ret = 0;
	if (ft_strchr("efg", s->sp))
		ret += print_char_(sim, 'e');
	else
		ret += print_char_(sim, 'E');
	if (lg >= 0 || e == 0.0)
		ret += print_str_(sim, "+", 1);
	else
		ret += print_str_(sim, "-", 1);
	if (mabs_d(lg) < 10)
		ret += print_str_(sim, "0", 1);
	ret += ft_printf_(sim, "%d", mabs_i(lg));
	return (ret);
}

int	print_e_sub_(int sim, t_spec *s, long double e)
{
	t_i64	lg;
	t_i64	adig;
	t_i64	fdig;
	t_i64	rdig;
	int		ret;

	ret = 0;
	lg = mlog10(mabs_d(e));
	adig = mround_even(mabs_d(e) * mpow_d(10, -lg + s->p));
	fdig = adig / (t_i64)mpow_d(10, s->p);
	if (fdig >= 10)
	{
		++lg;
		fdig /= 10;
	}
	rdig = adig % (t_i64)mpow_d(10, s->p);
	if (s->p != 0)
		ret += ft_printf_(sim, "%llu.%0*llu", fdig, s->p, rdig);
	else if (s->p == 0 && s->f_oc == 0)
		ret += ft_printf_(sim, "%llu", fdig);
	else if (s->p == 0 && s->f_oc == 1)
		ret += ft_printf_(sim, "%llu.", fdig);
	return (ret + e_inter(sim, lg, s, e));
}

int	print_f_sub_(int sim, t_spec *s, long double e)
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

int	print_s_(int sim, t_spec *spec, const char *s)
{
	int		ret;
	int		len;

	ret = 0;
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (spec->p != -1 && len > spec->p)
		len = spec->p;
	if (spec->w > len && !spec->f_mn)
		ret += print_width_(sim, spec, spec->w - len);
	ret += print_str_(sim, s, len);
	spec->f_zr = 0;
	if (spec->w > len && spec->f_mn)
		ret += print_width_(sim, spec, spec->w - len);
	return (ret);
}

int	print_c_(int sim, t_spec *spec, int c)
{
	int		ret;

	ret = 0;
	if (spec->w > 1 && !spec->f_mn)
		ret += print_width_(sim, spec, spec->w - 1);
	ret += print_char_(sim, c);
	if (spec->w > 1 && spec->f_mn)
		ret += print_width_with_(sim, ' ', spec->w - 1);
	return (ret);
}
