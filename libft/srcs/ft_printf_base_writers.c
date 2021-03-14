/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base_writers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:21:18 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/20 16:21:20 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_utils.h"

int	print_char_(int sim, int c)
{
	if (sim)
		return (1);
	return (write(1, &c, 1));
}

int	pr_2str_(int sim, const char *start, const char *end)
{
	if (sim)
		return (end - start);
	return (write(1, start, end - start));
}

int	print_str_(int sim, const char *s, int siz)
{
	if (sim)
		return (siz);
	return (write(1, s, siz));
}

int	print_width_with_(int sim, char c, int be_pr)
{
	int	ret;

	ret = 0;
	while (be_pr-- > 0)
		ret += print_char_(sim, c);
	return (ret);
}

int	print_width_(int sim, t_spec *spec, int be_pr)
{
	if (spec->f_zr)
		return (print_width_with_(sim, '0', be_pr));
	else
		return (print_width_with_(sim, ' ', be_pr));
}
