/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <ftinkere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:51:05 by ftinkere          #+#    #+#             */
/*   Updated: 2020/10/31 19:55:38 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t num, size_t siz)
{
	void	*res;
	size_t	bytes;

	bytes = num * siz;
	res = malloc(bytes);
	if (res != NULL)
		ft_bzero(res, bytes);
	return (res);
}
