#include <stdlib.h>
#include "libft.h"
#include "parse.h"

int	find_spawn(t_map *map, int *i, int *j)
{
	int	u;
	int	v;
	int	num;

	num = 0;
	u = 0;
	while (u < map->h)
	{
		v = 0;
		while (v < map->w)
		{
			if (map->tiles[u * map->w + v].type == TILE_TYPE_SPAWN)
			{
				num++;
				*i = u;
				*j = v;
			}
			v++;
		}
		u++;
	}
	return (num);
}

int	rec_circ(t_map *map, int *passed, int i, int j)
{
	int	u;
	int	v;

	if (i < 0 || j < 0 || i >= map->h || j >= map->w)
		return (0);
	passed[i * map->w + j] = 1;
	u = -1;
	while (u <= 1)
	{
		v = -1;
		while (v <= 1)
		{
			if ((!((passed[(i + u) *map->w + (j + v)] == 1 || \
					abs(u) == abs(v) || map->tiles[(i + u) *map->w + \
					(j + v)].type == TILE_TYPE_WALL)) && !rec_circ(map, \
						passed, i + u, j + v)) || (i + u < 0 || j + v < \
						0 || i + u >= map->h || j + v >= map->w))
				return (0);
			v++;
		}
		u++;
	}
	return (1);
}

int	validate_circ(t_map *map)
{
	int		res;
	int		*passed;
	int		i;
	int		j;

	passed = ft_calloc(map->w * map->w, sizeof(int));
	res = find_spawn(map, &i, &j);
	if (res != 1)
	{
		ft_printf("Spawn nums not equal 1. Its: %d\n", res);
		exit(42);
	}
	res = rec_circ(map, passed, i, j);
	free(passed);
	return (res);
}

int	validate_raw_map(t_lines_v *lines, int i)
{
	if (i >= lines->siz)
		return (0);
	while (i < lines->siz)
	{
		if (((char *)lines->arr[i])[0] == '\0')
			return (0);
		i++;
	}
	return (1);
}
