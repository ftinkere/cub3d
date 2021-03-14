/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:22:03 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/20 16:22:06 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include "libft.h"

t_spec	def_spec(void)
{
	t_spec	spec;

	spec.sp = 'd';
	spec.sb = '\0';
	spec.f_mn = 0;
	spec.f_pl = 0;
	spec.f_sp = 0;
	spec.f_oc = 0;
	spec.f_zr = 0;
	spec.w = -1;
	spec.p = -1;
	return (spec);
}

void	add_flag(t_spec *spec, char f)
{
	if (f == '-')
		spec->f_mn = 1;
	else if (f == '+')
		spec->f_pl = 1;
	else if (f == ' ')
		spec->f_sp = 1;
	else if (f == '#')
		spec->f_oc = 1;
	else if (f == '0')
		spec->f_zr = 1;
}

int	add_subspec(t_spec *spec, const char *f)
{
	if (*f == 'l' && f[1] == 'l')
	{
		spec->sb = 'L';
		return (2);
	}
	if (*f == 'h' && f[1] == 'h')
	{
		spec->sb = 'H';
		return (2);
	}
	if (*f == 'l')
	{
		spec->sb = 'l';
		return (1);
	}
	if (*f == 'h')
	{
		spec->sb = 'h';
		return (1);
	}
	return (0);
}

void	parse_prec(const char **fmt, t_spec *spec)
{
	const char	*f;

	f = *fmt;
	if (*f == '.' && f[1] == '*')
	{
		f += 2;
		spec->p = -2;
	}
	else if (*f == '.' && ft_isdigit(f[1]))
	{
		spec->p = ft_atoi(++f);
		while (ft_isdigit(*f))
			f++;
	}
	else if (*f == '.' && !ft_isdigit(f[1]))
	{
		spec->p = 0;
		f++;
	}
	*fmt = f;
}

t_spec	parse_spec(const char **fmt)
{
	t_spec		spec;
	const char	*f;

	spec = def_spec();
	if ((*fmt == NULL || **fmt != '%'))
		return (spec);
	f = *fmt + 1;
	while (is_flag(*f))
		add_flag(&spec, *f++);
	if (*f == '*' && ++f)
		spec.w = -2;
	else if (ft_isdigit(*f))
	{
		spec.w = ft_atoi(f);
		while (ft_isdigit(*f))
			f++;
	}
	parse_prec(&f, &spec);
	f += add_subspec(&spec, f);
	while (!(is_specc(*f) || *f == '\0'))
		f++;
	if (is_specc(*f))
		spec.sp = *f;
	*fmt = f + 1;
	return (spec);
}
