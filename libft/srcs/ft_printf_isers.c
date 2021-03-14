/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_isers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:21:37 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/20 16:21:38 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include "libft.h"

int	is_flag(char c)
{
	if (ft_strchr("-+ #0", c))
		return (1);
	return (0);
}

int	is_specc(char c)
{
	if (ft_strchr("diuoxXfFgGeEcsp%n", c))
		return (1);
	return (0);
}

int	is_infnan(double e)
{
	return (e != e || e == 1.0 / 0.0 || e == -1.0 / 0.0);
}
