/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 07:41:57 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/11 07:41:59 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_int.h"
#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strapp(char **dst, const char *src, int *ret)
{
	char	*res;
	char	*r;
	char	*d;

	d = *dst;
	if (d == 0 && src != 0)
		res = malloc(ft_strlen(src) + 1);
	else if (src == 0 && *dst != 0)
		res = malloc(ft_strlen(d) + 1);
	else
		res = malloc(ft_strlen(src) + ft_strlen(d) + 1);
	if (res == NULL)
		return ((char *)((char)(*ret = -1) + (char *) 1));
	r = res;
	if (*dst != NULL)
		while (*d != '\0')
			*r++ = *d++;
	if (src != NULL)
		while (*src != '\0')
			*r++ = *src++;
	*r = '\0';
	if (*dst != NULL)
		free(*dst);
	return (*dst = res);
}

int	exif(int flag, int *ret)
{
	return (flag < 0 || (flag == 0 && *ret < BUFFER_SIZE && !(*ret = 0)));
}
