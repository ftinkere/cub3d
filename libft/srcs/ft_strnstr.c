/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <ftinkere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:58:21 by ftinkere          #+#    #+#             */
/*   Updated: 2020/11/06 18:19:36 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strisstart(const char *src, const char *re, size_t n)
{
	while (*re != '\0')
		if (n-- == 0 || *src++ != *re++)
			return (0);
	return (1);
}

char	*ft_strnstr(const char *src, const char *re, size_t siz)
{
	size_t	i;

	if (ft_strlen(re) == 0)
		return ((char *)src);
	if (siz == 0)
		return (NULL);
	i = 0;
	while (i < siz && src[i] != '\0')
	{
		if (ft_strisstart(src + i, re, siz - i))
			return ((char *)(src + i));
		i++;
	}
	return (NULL);
}
