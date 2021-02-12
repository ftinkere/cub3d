/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <ftinkere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:02:06 by ftinkere          #+#    #+#             */
/*   Updated: 2020/11/06 18:24:38 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t len;

	if (n == 0)
		return (0);
	len = (n < ft_strlen(s1) ? n : ft_strlen(s1) + 1);
	len = (len < ft_strlen(s2) ? len : ft_strlen(s2) + 1);
	return (ft_memcmp(s1, s2, len));
}
