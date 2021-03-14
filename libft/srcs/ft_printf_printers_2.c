/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printers_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:21:50 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/20 16:21:53 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include "libft.h"

int	print_infnan_(int sim, t_spec *spec, long double e)
{
	int		ret;

	ret = 0;
	if (e != e && ft_strchr("efg", spec->sp))
		ret += print_str_(sim, "nan", 3);
	else if (e != e && ft_strchr("EFG", spec->sp))
		ret += print_str_(sim, "NAN", 3);
	else if ((e == 1 / 0.0 || e == 1 / -0.0) && ft_strchr("efg", spec->sp))
		ret += print_str_(sim, "inf", 3);
	else if ((e == 1 / 0.0 || e == 1 / -0.0) && ft_strchr("EFG", spec->sp))
		ret += print_str_(sim, "INF", 3);
	if (spec->f_mn)
	{
		spec->f_zr = 0;
		ret += print_width_(sim, spec, spec->w - (ret + \
			!!(sign_d(e) || spec->f_pl || spec->f_sp)));
	}
	return (ret);
}

int	print_e_(int sim, t_spec *s, long double e)
{
	int		ret;

	ret = 0;
	if (s->p < 0)
		s->p = 6;
	if (s->w > 0 && !s->f_zr && !s->f_mn && !is_infnan(e))
		ret += print_width_(sim, s, s->w - cnt_e(s, e));
	else if (s->w > 0 && !s->f_mn && is_infnan(e))
		ret += print_width_with_(sim, ' ', s->w - cnt_e(s, e));
	if ((e < 0 || sign_d((double)e) == 1) && e == e)
		ret += print_char_(sim, '-');
	else if (s->f_pl && e == e)
		ret += print_char_(sim, '+');
	else if (s->f_sp && e == e)
		ret += print_char_(sim, ' ');
	if (is_infnan(e))
		return (ret + print_infnan_(sim, s, e));
	ret += print_e_sub_(sim, s, e);
	if (s->w > 0 && s->f_zr && !s->f_mn)
		ret += print_width_(sim, s, s->w - cnt_e(s, e));
	if (s->w > 0 && s->f_mn)
		ret += print_width_with_(sim, ' ', s->w - ret);
	return (ret);
}

int	print_f_(int sim, t_spec *s, long double e)
{
	int		ret;

	ret = 0;
	if (s->p == -1)
		s->p = 6;
	if (!s->f_zr && !s->f_mn && s->w > 0 && !is_infnan(e))
		ret += print_width_(sim, s, s->w - cnt_f(s, e));
	else if (!s->f_mn && s->w > 0 && is_infnan(e))
		ret += print_width_with_(sim, ' ', s->w - cnt_f(s, e));
	if (sign_d(e) && e == e)
		ret += print_char_(sim, '-');
	else if (s->f_pl && e == e)
		ret += print_char_(sim, '+');
	else if (s->f_sp && e == e)
		ret += print_char_(sim, ' ');
	if (s->f_zr && !s->f_mn && s->w > 0 && !is_infnan(e))
		ret += print_width_(sim, s, s->w - cnt_f(s, e));
	if (is_infnan(e))
		return (ret + print_infnan_(sim, s, e));
	ret += print_f_sub_(sim, s, e);
	if (s->w != -1 && s->f_mn)
		ret += print_width_with_(sim, ' ', s->w - ret);
	return (ret);
}

int	print_g_(int sim, t_spec *spec, long double e)
{
	int		ret;

	ret = 0;
	if (spec->p == -1)
		spec->p = 6;
	spec->p = cnt_g_prec(spec, e);
	if (cnt_e(spec, e) < cnt_f(spec, e))
		ret += print_e_(sim, spec, e);
	else
		ret += print_f_(sim, spec, e);
	return (ret);
}

int	print_route(int sim, t_spec *s, unsigned long long d)
{
	if (d == 0 && s->f_oc && s->sp == 'o' && s->p <= prc_u(s, d))
		return (0);
	else if (s->sb == '\0')
		return (print_unsign_base_(sim, s, (unsigned int)d));
	else if (s->sb == 'H')
		return (print_unsign_base_(sim, s, (unsigned char)d));
	else if (s->sb == 'h')
		return (print_unsign_base_(sim, s, (unsigned short int)d));
	else if (s->sb == 'l')
		return (print_unsign_base_(sim, s, (unsigned long)d));
	else if (s->sb == 'L')
		return (print_unsign_base_(sim, s, (unsigned long long)d));
	return (0);
}
