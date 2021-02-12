/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <ftinkere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:56:05 by ftinkere          #+#    #+#             */
/*   Updated: 2020/10/31 19:56:21 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*res;
	size_t	len;

	len = ft_strlen(src) + 1;
	res = malloc(len);
	if (res != NULL)
		ft_memccpy(res, src, '\0', len);
	return (res);
}
