/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:06:01 by ftinkere          #+#    #+#             */
/*   Updated: 2020/11/07 14:48:20 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_pure_atoi(const char *s)
{
	int	res;

	res = 0;
	while ('0' <= *s && *s <= '9')
	{
		res = (res * 10) - (*s - '0');
		if (res > 0)
			return (-1);
		s++;
	}
	return (-res);
}

int	ft_atoi(const char *s)
{
	int	res;
	int	neg;

	neg = 1;
	while (*s == '\t' || *s == '\v' || *s == '\f' || *s == '\r'
		|| *s == '\n' || *s == ' ')
		s++;
	if (*s == '-')
	{
		neg = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	res = ft_pure_atoi(s);
	if (neg == -1 && res == -1)
		return (0);
	return (neg * res);
}
