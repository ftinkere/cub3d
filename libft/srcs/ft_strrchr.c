/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <ftinkere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:41:20 by ftinkere          #+#    #+#             */
/*   Updated: 2020/10/31 13:42:11 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	size_t	i;

	i = ft_strlen(src) + 1;
	while (i-- > 0)
		if (((char *)src)[i] == (char)c)
			return ((char *)(src + i));
	return (NULL);
}
