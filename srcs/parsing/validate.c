#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "parse.h"
#include "mlx.h"

int		find_spawn(t_map *map, size_t *i, size_t *j)
{
	size_t	u;
	size_t	v;
	int		num;

	num = 0;
	u = 0;
	while (u < map->height)
	{
		v = 0;
		while (v < map->width)
		{
			if (map->tiles[u * map->width + v].type == TILE_TYPE_SPAWN)
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

int		rec_circ(t_map *map, int *passed, size_t i, size_t j)
{
	int u;
	int v;

	if (i < 0 || j < 0 || i >= map->height || j >= map->width)
		return (0);
	passed[i * map->width + j] = 1;
	u = -1;
	while (u <= 1)
	{
		v = -1;
		while (v <= 1)
		{
			if (!((passed[(i + u) * map->width + (j + v)] == 1 ||
			abs(u) == abs(v) || map->tiles[(i + u) * map->width + (j + v)].type
			== TILE_TYPE_WALL)) && !rec_circ(map, passed, i + u, j + v)
			|| (i + u < 0 || j + v < 0 || i + u >= map->height
			|| j + v >= map->width))
				return (0);
			v++;
		}
		u++;
	}
	return (1);
}

int		validate_circ(t_map *map)
{
	int		res;
	int		*passed;
	size_t	i;
	size_t	j;

	passed = ft_calloc(map->width * map->width, sizeof(int));
	if ((res = find_spawn(map, &i, &j)) != 1)
	{
		ft_printf("Spawn nums not equal 1. Its: %d\n", res);
		exit(42);
	}
	res = rec_circ(map, passed, i, j);
	free(passed);
	return (res);
}

int		validate_raw_map(t_lines_v *lines, int i)
{
	if (i >= lines->siz)
		return (0);
	while (i < lines->siz)
	{
		if (((char*)lines->arr[i])[0] == '\0')
			return (0);
		i++;
	}
	return (1);
}
