/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <ftinkere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:32:07 by ftinkere          #+#    #+#             */
/*   Updated: 2020/11/05 14:25:21 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t siz)
{
	char	*res;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (len >= siz)
		len = siz;
	len++;
	res = malloc(len);
	if (start >= ft_strlen(s))
	{
		res[0] = '\0';
	}
	else if (res != NULL && len != 0)
	{
		ft_memccpy(res, s + start, '\0', len);
		res[len - 1] = '\0';
	}
	return (res);
}
