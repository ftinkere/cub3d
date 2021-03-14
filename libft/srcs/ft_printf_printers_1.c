/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printers_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:21:44 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/20 16:21:46 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_utils.h"
#include "libft.h"

int	print_unsign_base_(int sim, t_spec *spec, unsigned long long d)
{
	char	*base_str;
	char	*base_str_up;
	int		base;
	int		ret;

	ret = 0;
	base_str = "0123456789abcdefx";
	base_str_up = "0123456789ABCDEFX";
	if (ft_strchr("xpX", spec->sp))
		base = 16;
	else if (spec->sp == 'o')
		base = 8;
	else
		base = 10;
	if (spec->sp == 'X')
		base_str = base_str_up;
	if (d < (unsigned long long)base && d >= 0)
		ret += print_char_(sim, base_str[d]);
	else
	{
		ret += print_unsign_base_(sim, spec, d / base);
		ret += print_char_(sim, base_str[d % base]);
	}
	return (ret);
}

int	u_inter(t_spec *s, unsigned long long d)
{
	if (s->p != -1)
		s->f_zr = 0;
	if (s->sp == 'p')
	{
		s->sb = 'L';
		s->f_oc = 1;
	}
	if (s->w > 0)
		return (cnt_u(s, d));
	return (-1);
}

int	print_u_(int sim, t_spec *s, unsigned long long d)
{
	int		ret;
	int		be_pr;

	ret = 0;
	be_pr = u_inter(s, d);
	if (s->w > 0 && !s->f_zr && !s->f_mn)
		ret += print_width_(sim, s, s->w - be_pr);
	if ((d != 0 && s->f_oc && ft_strchr("x", s->sp)) || (s->sp == 'p'))
		ret += print_str_(sim, "0x", 2);
	else if (d != 0 && s->f_oc && s->sp == 'X')
		ret += print_str_(sim, "0X", 2);
	else if (s->f_oc && s->sp == 'o' && s->p <= prc_u(s, d))
		ret += print_str_(sim, "0", 1);
	if (s->w > 0 && s->p == -1 && s->f_zr && !s->f_mn)
		ret += print_width_(sim, s, s->w - be_pr);
	if (s->p > 0 && s->p > prc_u(s, d))
		ret += print_width_with_(sim, '0', s->p - prc_u(s, d));
	if (!(s->p == 0 && d == 0))
		ret += print_route(sim, s, d);
	if (s->f_mn && s->w > 0)
		ret += print_width_with_(sim, ' ', s->w - ret);
	return (ret);
}

int	d_inter(t_spec *s, long long d)
{
	if (s->p != -1)
		s->f_zr = 0;
	if (s->w > 0)
		return (cnt_d(s, d));
	return (-1);
}

int	print_d_(int sim, t_spec *s, long long d)
{
	int		ret;
	int		be_pr;

	ret = 0;
	be_pr = d_inter(s, d);
	if (s->w > 0 && !s->f_zr && !s->f_mn)
		ret += print_width_(sim, s, s->w - be_pr);
	if (d < 0)
		ret += print_char_(sim, '-');
	else if (s->f_pl)
		ret += print_char_(sim, '+');
	else if (s->f_sp)
		ret += print_char_(sim, ' ');
	if (s->w > 0 && s->p <= 0 && s->f_zr && !s->f_mn)
		ret += print_width_(sim, s, s->w - be_pr);
	else if (s->w > 0 && s->f_zr && !s->f_mn)
		ret += print_width_(sim, s, s->w - s->p - be_pr);
	if (s->p > 0 && s->p > prc_i(s, d))
		ret += print_width_with_(sim, '0', s->p - prc_i(s, d));
	if (!(s->p == 0 && d == 0))
		ret += print_route(sim, s, mabs_i(d));
	if (s->w > 0 && s->f_mn)
		ret += print_width_with_(sim, ' ', s->w - be_pr);
	return (ret);
}
