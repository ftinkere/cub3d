/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <ftinkere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:10:25 by ftinkere          #+#    #+#             */
/*   Updated: 2020/11/01 19:45:06 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	char		*d;
	const char	*s;
	size_t		n;

	d = dst;
	s = src;
	n = siz;
	if (dst == NULL || src == NULL)
		return (0);
	if (n != 0 && --n != 0 && (*d++ = *s++) != 0)
		while (--n != 0)
			if ((*d++ = *s++) == 0)
				break ;
	if (n == 0)
	{
		if (siz != 0)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
