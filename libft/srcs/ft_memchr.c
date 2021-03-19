/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <ftinkere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:42:44 by ftinkere          #+#    #+#             */
/*   Updated: 2020/11/05 20:10:07 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		if (((unsigned char *)src)[i - 1] == (unsigned char)c)
			return ((unsigned char *)(src + i - 1));
	return (NULL);
}
