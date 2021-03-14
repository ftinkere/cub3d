/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 07:41:43 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/11 07:41:45 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define BUFS_SIZ 256

static int	cp_n(char *dst, char *buf)
{
	int	n;
	int	ret;

	n = 0;
	ret = 0;
	if (dst == NULL || buf == NULL)
		return (-1);
	while (n < ((BUFFER_SIZE + 1) - 1) && buf[n] != '\0' && buf[n] != '\n')
	{
		dst[n] = buf[n];
		n++;
	}
	dst[n] = '\0';
	if (buf[n] == '\n' && ++n)
		ret = 1;
	ft_memmove(buf, buf + n, ft_strlen(buf + n) + 1);
	if (n == 0)
		n = 1;
	buf[(BUFFER_SIZE + 1) - n - 1] = '\0';
	return (ret);
}

static int	free_buf(char **bufs, int fd, int ret)
{
	if (fd < 0 || bufs[fd] == NULL)
		return (ret);
	free(bufs[fd]);
	bufs[fd] = NULL;
	return (ret);
}

static int	comif(char **bufs, int fd, int *ret, char *line)
{
	return (((bufs[fd] = malloc(BUFFER_SIZE + 1)) == NULL
			&& (*ret = -1)) || \
			((*ret = (int)read(fd, bufs[fd], BUFFER_SIZE)) < 0 && \
			*line == '\0'));
}

int	get_next_line(int fd, char **line)
{
	static char	*bufs[BUFS_SIZ];
	char		res[BUFFER_SIZE + 1];
	int			ret;
	int			flag;

	if ((BUFFER_SIZE <= 0) || (fd < 0) || (line == NULL)
		|| (*line = (char*)malloc(sizeof(char*))) == NULL)
		return (free_buf(bufs, fd, -1));
	ret = BUFFER_SIZE;
	**line = '\0';
	while (1)
	{
		if (bufs[fd] == NULL)
			if (comif(bufs, fd, &ret, *line))
				break ;
		bufs[fd][ret] = '\0';
		flag = cp_n(res, bufs[fd]);
		ft_strapp(line, res, &ret);
		if (exif(flag, &ret))
			break ;
		else if (flag == 0 && free_buf(bufs, fd, 1))
			continue ;
		return (1);
	}
	return (free_buf(bufs, fd, ret));
}
