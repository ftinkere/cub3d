/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <ftinkere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:11:00 by ftinkere          #+#    #+#             */
/*   Updated: 2020/11/06 16:28:27 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	dlen;

	if (src == NULL || dst == NULL)
		return (0);
	dlen = ft_strlen(dst);
	if (dlen > siz)
		dlen = siz;
	return (dlen + ft_strlcpy(dst + dlen, src, siz - dlen));
}
