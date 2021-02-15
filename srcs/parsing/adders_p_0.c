#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "parse.h"
#include "cub3d_utils.h"
#include "adders_p.h"
#include "mlx.h"

int			add_p_no(t_config *conf, t_lines lines)
{
	size_t	index;
	t_btexs *btex;

	index = ft_isdigit(lines[0][2]) ? ft_atoi(lines[0] + 2) : 0;
	if (index == conf->block_types)
	{
		btex = btexs_new();
		btex->north = ft_strdup(lines[1]);
		if (btex->north == NULL)
			errex(42, "Error strdup north tex");
		cvec_push(&conf->blocks_texs, btex);
		conf->block_types++;
		return (1);
	}
	else if (index < conf->block_types
	&& ((t_btexs*)conf->blocks_texs.arr[index])->north == NULL)
	{
		((t_btexs*)conf->blocks_texs.arr[index])->north = ft_strdup(lines[1]);
		return (1);
	}
	return (0);
}

int			add_p_so(t_config *conf, t_lines lines)
{
	size_t	index;
	t_btexs *btex;

	index = ft_isdigit(lines[0][2]) ? ft_atoi(lines[0] + 2) : 0;
	if (index == conf->block_types)
	{
		btex = btexs_new();
		btex->south = ft_strdup(lines[1]);
		if (btex->south == NULL)
			errex(42, "Error strdup south");
		cvec_push(&conf->blocks_texs, btex);
		conf->block_types++;
		return (1);
	}
	else if (index < conf->block_types
	&& ((t_btexs*)conf->blocks_texs.arr[index])->south == NULL)
	{
		((t_btexs*)conf->blocks_texs.arr[index])->south = ft_strdup(lines[1]);
		return (1);
	}
	return (0);
}

int			add_p_we(t_config *conf, t_lines lines)
{
	size_t	index;
	t_btexs *btex;

	index = ft_isdigit(lines[0][2]) ? ft_atoi(lines[0] + 2) : 0;
	if (index == conf->block_types)
	{
		btex = btexs_new();
		btex->west = ft_strdup(lines[1]);
		if (btex->west == NULL)
			errex(42, "Error strdup west");
		cvec_push(&conf->blocks_texs, btex);
		conf->block_types++;
		return (1);
	}
	else if (index < conf->block_types
	&& ((t_btexs*)conf->blocks_texs.arr[index])->west == NULL)
	{
		((t_btexs*)conf->blocks_texs.arr[index])->west = ft_strdup(lines[1]);
		return (1);
	}
	return (0);
}

int			add_p_ea(t_config *conf, t_lines lines)
{
	size_t	index;
	t_btexs *btex;

	index = ft_isdigit(lines[0][2]) ? ft_atoi(lines[0] + 2) : 0;
	if (index == conf->block_types)
	{
		btex = btexs_new();
		btex->east = ft_strdup(lines[1]);
		if (btex->east == NULL)
			errex(42, "Error strdup east");
		cvec_push(&conf->blocks_texs, btex);
		conf->block_types++;
		return (1);
	}
	else if (index < conf->block_types
	&& ((t_btexs*)conf->blocks_texs.arr[index])->east == NULL)
	{
		((t_btexs*)conf->blocks_texs.arr[index])->east = ft_strdup(lines[1]);
		return (1);
	}
	return (0);
}

int			add_p_up(t_config *conf, t_lines lines)
{
	size_t	index;
	t_btexs *btex;

	index = ft_isdigit(lines[0][2]) ? ft_atoi(lines[0] + 2) : 0;
	if (index == conf->block_types)
	{
		btex = btexs_new();
		btex->up = ft_strdup(lines[1]);
		if (btex->up == NULL)
			errex(42, "Error strdup up");
		cvec_push(&conf->blocks_texs, btex);
		conf->block_types++;
		return (1);
	}
	else if (index < conf->block_types
	&& ((t_btexs*)conf->blocks_texs.arr[index])->up == NULL)
	{
		((t_btexs*)conf->blocks_texs.arr[index])->up = ft_strdup(lines[1]);
		return (1);
	}
	return (0);
}
