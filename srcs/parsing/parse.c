#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "parse.h"
#include "mlx.h"

extern void *mlx;

// MALLOCS
// TODO FREESHER
t_lines_v	read_file(t_file file)
{
	t_lines_v	res;
	t_line		line;

	res = cvec_new();
	while(get_next_line(file, &line) > 0) // ERRORS!
	{
		cvec_push(&res, line);
	}
	if (line != NULL)
		cvec_push(&res, line);
	return (res);
}

enum e_param	get_param(t_config *conf, t_line line)
{
	int		res;

	if (line == NULL || line[0] == '\0')
		return (P_E);
	res = !ft_memcmp(line, "R", 1) ? P_R : P_M;
	res = !ft_memcmp(line, "S", 1) ? P_S : res;
	res = !ft_memcmp(line, "NO", 2) ? P_NO : res;
	res = !ft_memcmp(line, "SO", 2) ? P_SO : res;
	res = !ft_memcmp(line, "WE", 2) ? P_WE : res;
	res = !ft_memcmp(line, "EA", 2) ? P_EA : res;
	res = !ft_memcmp(line, "UP", 2) ? P_UP : res;
	res = !ft_memcmp(line, "F", 1) ? P_F : res;
	res = !ft_memcmp(line, "C", 1) ? P_C : res;
	res = !ft_memcmp(line, "L", 1) ? P_L : res;
	res = !ft_memcmp(line, "FOV", 3) ? P_FOV : res;
	return (res);
}

int			add_p_r(t_config *conf, t_lines sline)
{
	int screen_w;
	int screen_h;

	if (sline == NULL || sline[0] == NULL || sline[1] == NULL
			|| sline[2] == NULL)
		return (0);
	conf->w_res = ft_atoi(sline[1]);
	conf->h_res = ft_atoi(sline[2]);
	mlx_get_screen_size(mlx, &screen_w, &screen_h);
	if (conf->w_res > screen_w)
		conf->w_res = screen_w;
	if (conf->h_res > screen_h)
		conf->h_res = screen_h;
	return (1);
}

void		free_split(t_lines lines)
{
	int i;

	i = 0;
	while (lines[i] != NULL)
	{
		free(lines[i]);
		i++;
	}
	free (lines);
}

t_btexs *btexs_new()
{
	t_btexs *res;

	res = ft_calloc(1, sizeof(t_btexs));
	return (res);
}

int			add_p_no(t_config *conf, t_lines lines)
{
	size_t	index;
	t_btexs *btex;

	index = ft_isdigit(lines[0][2]) ? ft_atoi(lines[0] + 2) : 0;
	if (index == conf->block_types)
	{
		btex = btexs_new();
		btex->north = ft_strdup(lines[1]);
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

int			add_p_s(t_config *conf, t_lines lines)
{
	size_t	index;

	index = ft_isdigit(lines[0][1]) ? ft_atoi(lines[0] + 1) : 0;
	if (index == conf->sprite_types)
	{
		cvec_push(&conf->sprites_texs, ft_strdup(lines[1]));
		conf->sprite_types++;
		return (1);
	}
	return (0);
}

int			add_p_f(t_config *conf, t_lines lines)
{
	int r;
	int g;
	int b;

	if (!lines || !lines[0] || !lines[1] || !lines[2] || !lines[3])
		return (0);
	r = ft_atoi(lines[1]);
	g = ft_atoi(lines[2]);
	b = ft_atoi(lines[3]);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		return (0);
	conf->floor_color = 0 | (r << 16) | (g << 8) | b;
	return (1);
}

int			add_p_c(t_config *conf, t_lines lines)
{
	int r;
	int g;
	int b;

	if (!lines || !lines[0] || !lines[1] || !lines[2] || !lines[3])
		return (0);
	r = ft_atoi(lines[1]);
	g = ft_atoi(lines[2]);
	b = ft_atoi(lines[3]);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		return (0);
	conf->ceil_color = 0 | (r << 16) | (g << 8) | b;
	return (1);
}

int			add_p_l(t_config *conf, t_line line)
{
	if (!line)
		return (0);
	conf->map.legend = ft_strdup(line + 2);
	return (1);
}

int			add_conf(t_config *conf, t_line line)
{
	t_lines			lines;
	enum e_param	param;

	lines = ft_split(line, " ,");
	param = get_param(conf, lines[0]);
	if (param == P_M)
		return (P_M);
	else if (param == P_E)
		return (P_E);
	else if (param == P_R)
		add_p_r(conf, lines);
	else if (param == P_NO)
		add_p_no(conf, lines);
	else if (param == P_SO)
		add_p_so(conf, lines);
	else if (param == P_WE)
		add_p_we(conf, lines);
	else if (param == P_EA)
		add_p_ea(conf, lines);
	else if (param == P_UP)
		add_p_up(conf, lines);
	else if (param == P_S)
		add_p_s(conf, lines);
	else if (param == P_F)
		add_p_f(conf, lines);
	else if (param == P_C)
		add_p_c(conf, lines);
	else if (param == P_L)
		add_p_l(conf, line);
	free_split(lines);
	return (param);
}

void		conf_init(t_config *conf)
{
	conf->h_res = 42;
	conf->w_res = 42;
	conf->block_types = 0;
	conf->blocks_texs = cvec_new();
	conf->sprite_types = 0;
	conf->sprites_texs = cvec_new();
	conf->ceil_color = 0x00000000;
	conf->floor_color = 0x00000000;
	conf->map.tiles = NULL;
	conf->map.height = 0;
	conf->map.weight = 0;
	conf->map.legend = "0E 1W0 2S0 DD0 NN0 EE1 SS2 WW3";
	conf->fov = 66;
}

int			validate_raw_map(t_lines_v *lines, int i)
{
	int j;

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

t_tile		get_tile_from(char c, t_lines leg)
{
	t_tile tile;
	int i;

	i = 0;
	tile.type = -2;
	while(leg[i] != NULL)
	{
		if (c == leg[i][0])
		{
			if (leg[i][1] == 'W')
				tile.type = TILE_TYPE_WALL;
			else if (leg[i][1] == 'E' || c == ' ')
				tile.type = TILE_TYPE_EMPTY;
			else if (leg[i][1] == 'S')
				tile.type = TILE_TYPE_SPRITE;
			else if (leg[i][1] == 'D')
				tile.type = TILE_TYPE_DOOR;
			else if (ft_strchr("NESW", leg[i][1]))
				tile.type = TILE_TYPE_SPAWN;
			else
				exit(42);
			if (tile.type != TILE_TYPE_EMPTY)
				tile.num = ft_atoi(&leg[i][2]);
		}
		i++;
	}
//	if (tile.type == -2) error
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
	map->weight = max;
	map->height = lines->siz - j;
	return (1);
}

// NEED FREESHER
int			parse_map(t_map *map, t_lines_v *lines, int i)
{
	t_lines	leg;
	int		j;
	int 	k;

	if (!validate_raw_map(lines, i))
		return (0);
	if (!set_dims_map(map, lines, i))
		return (0);
	map->tiles = ft_calloc(map->height * map->weight, sizeof(t_tile));
	// ERROR
	leg = ft_split(map->legend, " ");
	k = 0;
	while (k < map->height)
	{
		j = 0;
		while (j < ft_strlen(lines->arr[k + i]))
		{
			map->tiles[k * map->weight + j] = get_tile_from(((char*)lines->arr[k + i])[j], leg);
			j++;
		}
		k++;
	}
	return (1);
}

// MALLOCS
// TODO FREESHER
t_config	parse_cub(t_path conf_path)
{
	t_config	conf;
	t_file		conf_file;
	t_lines_v	lines;
	int			i;
	int 		param;

	conf_init(&conf);
	conf_file = open(conf_path, O_RDONLY);
	lines = read_file(conf_file);
	i = 0;
	param = 42;
	while (i < lines.siz && param != P_M)
	{
		param = add_conf(&conf, lines.arr[i]);
		i++;
	}
	if (param == P_M)
		parse_map(&conf.map, &lines, i - 1);
	// else error
	close(conf_file);
	return (conf);
}