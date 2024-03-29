#include "libft.h"
#include "parse.h"
#include "cub3d_utils.h"
#include "map_validates.h"

void	num_set(t_tile *tile, t_line leg)
{
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

void	tile_set(t_tile *tile, t_line leg, char c)
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
			errex(42, "Legend or map not right");
		num_set(tile, leg);
	}
	else if (c == ' ')
		tile->type = TILE_TYPE_EMPTY;
}

t_tile	get_tile_from(char c, t_lines leg)
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
	if (tile.type == TILE_NOT_FOUND)
		errex(42, "Tile type not found");
	return (tile);
}

int	set_dims_map(t_map *map, t_lines_v *lines, int i)
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
		if (temp > max)
			max = temp;
		i++;
	}
	map->w = max;
	map->h = lines->siz - j;
	if (map->w < 3 || map->h < 3)
		errex(42, "Map too small, you cant do it good");
	return (1);
}

int	parse_map(t_map *map, t_lines_v *lines, int i)
{
	t_lines	leg;
	int		j;
	int		k;

	if (!validate_raw_map(lines, i))
		errex(42, "Empty lines in map");
	set_dims_map(map, lines, i);
	map->tiles = ft_calloc(map->h * map->w, sizeof(t_tile));
	leg = ft_split_str(map->legend, " ");
	if (leg == NULL || map->tiles == NULL)
		errex(42, "Error allocated memory while parse map");
	k = 0;
	while (k < map->h)
	{
		j = 0;
		while (j < (int)ft_strlen(lines->arr[k + i]))
		{
			map->tiles[k * map->w + j] = \
					get_tile_from(((char *)lines->arr[k + i])[j], leg);
			j++;
		}
		k++;
	}
	free_split(leg);
	return (1);
}
