/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <ftinkere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:22:08 by ftinkere          #+#    #+#             */
/*   Updated: 2020/11/06 18:31:57 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	is_inset(char c, const char *set)
{
	while (*set != '\0')
		if (c == *set++)
			return (c);
	return (0);
}

char	*ft_strtrim(const char *src, const char *set)
{
	char	*res;
	size_t	len;
	size_t	lft_off;
	size_t	rgt_off;

	if (src == NULL)
		return (NULL);
	len = ft_strlen(src);
	lft_off = 0;
	while (is_inset(src[lft_off], set))
		lft_off++;
	if (lft_off == len)
		return (ft_strdup("\0"));
	rgt_off = 0;
	while (is_inset(src[len - rgt_off - 1], set))
		rgt_off++;
	res = malloc(len - lft_off - rgt_off + 1);
	if (res != NULL)
	{
		ft_memccpy(res, src + lft_off, '\0', len - lft_off - rgt_off + 1);
		res[len - lft_off - rgt_off] = '\0';
	}
	return (res);
}
