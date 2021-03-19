/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_readers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:21:58 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/20 16:21:59 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_utils.h"
#include "libft.h"

t_u64	read_var_u(t_spec *spec, va_list p_args)
{
	long long	d;
	int			w;

	d = 0;
	w = spec->w;
	if (spec->w == -2)
		spec->w = va_arg(p_args, int);
	if (spec->p == -2)
		spec->p = va_arg(p_args, int);
	if (spec->w < 0 && w != -1)
	{
		spec->w = mabs_i(spec->w);
		spec->f_mn = 1;
	}
	if (spec->p < 0)
		spec->p = -1;
	if (spec->sb == 'L' || spec->sp == 'p')
		d = va_arg(p_args, t_u64);
	else if (spec->sb == '\0' || ft_strchr("hH", spec->sb))
		d = va_arg(p_args, unsigned int);
	else if (spec->sb == 'l')
		d = va_arg(p_args, unsigned long int);
	return (d);
}

long long	read_var_int(t_spec *spec, va_list p_args)
{
	long long	d;
	int			w;

	d = 0;
	w = spec->w;
	if (spec->w == -2)
		spec->w = va_arg(p_args, int);
	if (spec->p == -2)
		spec->p = va_arg(p_args, int);
	if (spec->w < 0 && w != -1)
	{
		spec->w = mabs_i(spec->w);
		spec->f_mn = 1;
	}
	if (spec->p < 0)
		spec->p = -1;
	if (spec->sb == 'L' || spec->sp == 'p')
		d = va_arg(p_args, t_i64);
	else if (spec->sb == '\0' || ft_strchr("hH", spec->sb))
		d = va_arg(p_args, int);
	else if (spec->sb == 'l')
		d = va_arg(p_args, long int);
	return (d);
}

int	read_var_char(t_spec *spec, va_list p_args)
{
	int	w;

	w = spec->w;
	if (spec->w == -2)
		spec->w = va_arg(p_args, int);
	if (spec->p == -2)
		spec->p = va_arg(p_args, int);
	if (spec->w < 0 && w != -1)
	{
		spec->w = mabs_i(spec->w);
		spec->f_mn = 1;
	}
	if (spec->p < 0)
		spec->p = -1;
	return (va_arg(p_args, int));
}

double	read_var_double(t_spec *spec, va_list p_args)
{
	int	w;

	w = spec->w;
	if (spec->w == -2)
		spec->w = va_arg(p_args, int);
	if (spec->p == -2)
		spec->p = va_arg(p_args, int);
	if (spec->w < 0 && w != 0)
	{
		spec->w = mabs_i(spec->w);
		spec->f_mn = 1;
	}
	if (spec->p < 0)
		spec->p = -1;
	return (va_arg(p_args, double));
}

char	*read_var_s(t_spec *spec, va_list p_args)
{
	int	w;

	w = spec->w;
	if (spec->w == -2)
		spec->w = va_arg(p_args, int);
	if (spec->p == -2)
		spec->p = va_arg(p_args, int);
	if (spec->w < 0 && w != -1)
	{
		spec->w = mabs_i(spec->w);
		spec->f_mn = 1;
	}
	if (spec->p < 0)
		spec->p = -1;
	return (va_arg(p_args, char *));
}
