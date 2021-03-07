#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "parse.h"
#include "cub3d_utils.h"
#include "mlx.h"
#include "adders_p.h"
#include "map_validates.h"
#include "conf.h"

void		tile_set(t_tile *tile, t_line leg, char c)
{
	if (c == leg[0])
	{
		if (ft_strchr("NESW", leg[1]) && leg[2] == 'S')
			tile->type = TILE_TYPE_SPAWN;
		else if (leg[1] == 'W')
			tile->type = TILE_TYPE_WALL;
		else if (leg[1] == 'E')
			tile->type = TILE_TYPE_EMPTY;
		else if (leg[1] == 'D')
			tile->type = TILE_TYPE_DOOR;
		else if (leg[1] == 'S')
			tile->type = TILE_TYPE_SPRITE;
		else
			errex(42, "Legend not found right char");
		if (tile->type == TILE_TYPE_SPAWN && leg[1] == 'N')
			tile->num = 0;
		else if (tile->type == TILE_TYPE_SPAWN && leg[1] == 'E')
			tile->num = 1;
		else if (tile->type == TILE_TYPE_SPAWN && leg[1] == 'S')
			tile->num = 2;
		else if (tile->type == TILE_TYPE_SPAWN && leg[1] == 'W')
			tile->num = 3;
		else if (tile->type != TILE_TYPE_EMPTY)
			tile->num = ft_atoi(&leg[2]);
	}
	else if (c == ' ')
	{
		tile->type = TILE_TYPE_EMPTY;
	}
}

t_tile		get_tile_from(char c, t_lines leg)
{
	t_tile	tile;
	int		i;

	i = 0;
	tile.type = -2;
	while (leg[i] != NULL)
	{
		tile_set(&tile, leg[i], c);
		i++;
	}
	if (tile.type == -2)
		errex(42, "Tile type not found");
	return (tile);
}

int			set_dims_map(t_map *map, t_lines_v *lines, int i)
{
	size_t	max;
	size_t	temp;
	int		j;

	max = 0;
	j = i;
	while (i < lines->siz)
	{
		temp = ft_strlen(lines->arr[i]);
		if (temp == 0)
			return (0);
		max = temp > max ? temp : max;
		i++;
	}
	map->width = max;
	map->height = lines->siz - j;
	return (1);
}

int			parse_map(t_map *map, t_lines_v *lines, int i)
{
	t_lines	leg;
	int		j;
	int		k;

	if (!validate_raw_map(lines, i))
		errex(42, "Empty lines in map");
	set_dims_map(map, lines, i);
	map->tiles = ft_calloc(map->height * map->width, sizeof(t_tile));
	leg = ft_split(map->legend, " ");
	if (leg == NULL || map->tiles == NULL)
		errex(42, "Error allocated memory while parse map");
	k = 0;
	while (k < map->height)
	{
		j = 0;
		while (j < ft_strlen(lines->arr[k + i]))
		{
			map->tiles[k * map->width + j] =
					get_tile_from(((char*)lines->arr[k + i])[j], leg);
			j++;
		}
		k++;
	}
	free_split(leg);
	return (1);
}

t_config	parse_cub(t_vars *vars, t_path conf_path)
{
	t_config	conf;
	t_file		conf_file;
	t_lines_v	lines;
	int			i;
	int			param;

	conf_init(&conf);
	conf_file = open(conf_path, O_RDONLY);
	lines = read_file(conf_file);
	close(conf_file);
	i = 0;
	param = 42;
	while (i < lines.siz && param != P_M)
	{
		param = add_conf(vars, &conf, lines.arr[i]);
		i++;
	}
	conf.w_vres = conf.w_res;
	conf.h_vres = conf.h_res; // Временно
	if (param == P_M)
		parse_map(&conf.map, &lines, i - 1);
	else
		errex(42, "Map not found in .cub");
	if (!validate_circ(&conf.map))
		errex(42, "Map not valid. Player can go to end of map");
	free(lines.arr);
	return (conf);
}
