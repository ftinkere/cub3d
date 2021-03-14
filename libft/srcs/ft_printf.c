/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:21:12 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/20 16:21:14 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_utils.h"
#include "libft.h"

int	print_by_spec_(int sim, t_spec *spec, va_list p_args)
{
	int		ret;

	ret = 0;
	if (ft_strchr("di", spec->sp))
		ret += print_d_(sim, spec, read_var_int(spec, p_args));
	else if (ft_strchr("opuxX", spec->sp))
		ret += print_u_(sim, spec, read_var_u(spec, p_args));
	else if (spec->sp == 'c')
		ret += print_c_(sim, spec, read_var_char(spec, p_args));
	else if (spec->sp == 's')
		ret += print_s_(sim, spec, read_var_s(spec, p_args));
	else if (ft_strchr("eE", spec->sp))
		ret += print_e_(sim, spec, read_var_double(spec, p_args));
	else if (ft_strchr("fF", spec->sp))
		ret += print_f_(sim, spec, read_var_double(spec, p_args));
	else if (ft_strchr("gG", spec->sp))
		ret += print_g_(sim, spec, read_var_double(spec, p_args));
	else if (spec->sp == '%')
		ret += print_c_(sim, spec, '%');
	return (ret);
}

void	spec_n(t_spec *spec, int ret, va_list p_args)
{
	int		*n;

	if (spec->w == -2)
		spec->w = va_arg(p_args, int);
	if (spec->p == -2)
		spec->p = va_arg(p_args, int);
	if (spec->w < -1)
	{
		spec->w = mabs_i(spec->w);
		spec->f_mn = 1;
	}
	if (spec->p < 0)
		spec->p = -1;
	n = va_arg(p_args, int *);
	*n = ret;
}

int	ft_printf_bs(int sim, const char *format, va_list args)
{
	int			ret;
	t_spec		spec;
	const char	*f;

	ret = 0;
	while (1)
	{
		if (*format == '\0')
			break ;
		if (*format != '\0' && *format != '%')
		{
			f = get_block_end(format);
			ret += pr_2str_(sim, format, f);
			format = f;
		}
		else if (*format == '%')
		{
			spec = parse_spec(&format);
			if (spec.sp != 'n')
				ret += print_by_spec_(sim, &spec, args);
			else
				spec_n(&spec, ret, args);
		}
	}
	return (ret);
}

int	ft_printf_(int sim, const char *format, ...)
{
	int			ret;
	va_list		args;

	va_start(args, format);
	ret = ft_printf_bs(sim, format, args);
	va_end(args);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int			ret;
	va_list		args;

	va_start(args, format);
	ret = ft_printf_bs(0, format, args);
	va_end(args);
	return (ret);
}
