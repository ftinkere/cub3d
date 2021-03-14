/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <ftinkere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:10:39 by ftinkere          #+#    #+#             */
/*   Updated: 2020/11/05 20:11:36 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		delta;

	i = 0;
	while (i < n)
	{
		delta = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		if (delta != 0)
			return ((int)delta);
		i++;
	}
	return (0);
}
