/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:22:09 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/20 16:22:11 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf_utils.h"
#include "libft.h"

const char	*get_block_end(const char *str)
{
	const char	*s;

	if (str == NULL)
		return (NULL);
	s = str;
	while (*s != '\0')
	{
		if (*s == '\\' && s[1] == '%')
			s += 1;
		else if (*s == '\0' || *s == '%')
			return (s);
		s++;
	}
	return (s);
}

int	prc_u(t_spec *spec, unsigned long long d)
{
	int			res;
	int			base;

	res = 1;
	if (spec->sp == 'o')
		base = 8;
	else if (ft_strchr("xpX", spec->sp))
		base = 16;
	else
		base = 10;
	d /= base;
	while (d != 0)
	{
		++res;
		d /= base;
	}
	return (res);
}

int	prc_i(t_spec *spec, long long d)
{
	int			res;
	int			base;

	res = 1;
	d = mabs_i(d);
	if (spec->sp == 'o')
		base = 8;
	else if (spec->sp == 'x' || spec->sp == 'X')
		base = 16;
	else
		base = 10;
	d /= base;
	while (d != 0)
	{
		++res;
		d /= base;
	}
	return (res);
}
