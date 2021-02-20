#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include "unistd.h"
#include "mlx.h"
#include "libft.h"
#include "cvec.h"
#include "parse.h"

void	print_map(t_map *map)
{
	int	i = 0, j;

	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_printf("%d", map->tiles[i * map->width + j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_conf(t_config *conf)
{
	ft_printf("w: %4d\nh: %4d\n", conf->w_res, conf->h_res);
	ft_printf("btexs: %d\n", conf->blocks_texs.siz);
	ft_printf("NO0: %s\n", ((t_btexs*)conf->blocks_texs.arr[0])->north);
	ft_printf("SO0: %s\n", ((t_btexs*)conf->blocks_texs.arr[0])->south);
	ft_printf("WE0: %s\n", ((t_btexs*)conf->blocks_texs.arr[0])->west);
	ft_printf("EA0: %s\n", ((t_btexs*)conf->blocks_texs.arr[0])->east);
	ft_printf("UP0: %s\n", ((t_btexs*)conf->blocks_texs.arr[0])->up);
	ft_printf("NO1: %s\n", ((t_btexs*)conf->blocks_texs.arr[1])->north);
	ft_printf("SO1: %s\n", ((t_btexs*)conf->blocks_texs.arr[1])->south);
	ft_printf("WE1: %s\n", ((t_btexs*)conf->blocks_texs.arr[1])->west);
	ft_printf("EA1: %s\n", ((t_btexs*)conf->blocks_texs.arr[1])->east);
	ft_printf("UP1: %s\n", ((t_btexs*)conf->blocks_texs.arr[1])->up);
	ft_printf("S0: %s\n", conf->sprites_texs.arr[0]);
	ft_printf("S1: %s\n", conf->sprites_texs.arr[1]);

	int a,r,g,b;
	a = (conf->floor_color & 0xFF000000) >> 24;
	r = (conf->floor_color & 0x00FF0000) >> 16;
	g = (conf->floor_color & 0x0000FF00) >> 8;
	b = conf->floor_color & 0x000000FF;
	ft_printf("Floor: %3d, r: %3d, g: %3d, b: %3d\n", a, r, g, b);

	a = (conf->ceil_color & 0xFF000000) >> 24;
	r = (conf->ceil_color & 0x00FF0000) >> 16;
	g = (conf->ceil_color & 0x0000FF00) >> 8;
	b = conf->ceil_color & 0x000000FF;
	ft_printf("Ceil: %3d, r: %3d, g: %3d, b: %3d\n", a, r, g, b);
	ft_printf("\nMAP:\n");
	print_map(&conf->map);
	ft_printf("Virtual res: w: %3d h: %3d\n", conf->w_vres, conf->h_vres);
	ft_printf("Distance to projection plane: %f\n", conf->dist_proj);
}