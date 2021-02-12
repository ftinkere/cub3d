/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 07:41:57 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/11 07:41:59 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_int.h"
#include "libft.h"

#include <string.h>
#include <stdio.h>

//char	*ft_memmove(char *dest, const char *src, size_t n)
//{
//	size_t i;
//
//	if (src == dest)
//		return (dest);
//	else if (src < dest)
//	{
//		i = n;
//		while (i-- > 0)
//			dest[i] = src[i];
//	}
//	else
//	{
//		i = 0;
//		while (i++ < n)
//			dest[i - 1] = src[i - 1];
//	}
//	return (dest);
//}
//
//size_t	ft_strlen(const char *s)
//{
//	size_t i;
//
//	i = 0;
//	while (s[i] != '\0')
//		i++;
//	return (i);
//}

char	*ft_strapp(char **dst, const char *src, int *ret)
{
	char	*res;
	char	*r;
	char	*d;

	d = *dst;
	if (d == 0 && src != 0)
		res = malloc(ft_strlen(src) + 1);
	else if (src == 0 && *dst != 0)
		res = malloc(ft_strlen(d) + 1);
	else
		res = malloc(ft_strlen(src) + ft_strlen(d) + 1);
	if (res == NULL && (*ret = -1))
		return (NULL);
	r = res;
	if (*dst != NULL)
		while (*d != '\0')
			*r++ = *d++;
	if (src != NULL)
		while (*src != '\0')
			*r++ = *src++;
	*r = '\0';
	if (*dst != NULL)
		free(*dst);
	return (*dst = res);
}
