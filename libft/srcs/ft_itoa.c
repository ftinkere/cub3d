/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <ftinkere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:56:22 by ftinkere          #+#    #+#             */
/*   Updated: 2020/11/05 20:19:33 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	quazi_abs(int *n)
{
	int	orig;

	orig = *n;
	if (*n < 0)
		*n *= -1;
	return (orig);
}

static int	digi_county(int n)
{
	int	res;

	if (n == (-2147483647 - 1))
		return (12);
	if (n == 0)
		return (2);
	res = 1;
	if (quazi_abs(&n) < 0)
		res++;
	while (n != 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

static void	reverse(char *str)
{
	char	buf;
	int		len;
	int		half_len;
	int		i;

	if (*str == '-')
		str++;
	len = (int)ft_strlen(str);
	half_len = len / 2;
	i = 0;
	while (i < half_len)
	{
		buf = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = buf;
		i++;
	}
}

static char	*strlcpy_ret(char *dst, const char *src, size_t dstsize)
{
	ft_strlcpy(dst, src, dstsize);
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*res;
	char	*r;
	int		div;

	res = malloc(digi_county(n));
	if (res == NULL)
		return (NULL);
	if (n == (-2147483647 - 1))
		return (strlcpy_ret(res, "-2147483648", 12));
	else if (n == 0)
		return (strlcpy_ret(res, "0", 12));
	r = res;
	if (quazi_abs(&n) < 0)
		*r++ = '-';
	div = n;
	while (div != 0)
	{
		*r++ = (char)((div % 10) + '0');
		div /= 10;
	}
	*r = '\0';
	reverse(res);
	return (res);
}
