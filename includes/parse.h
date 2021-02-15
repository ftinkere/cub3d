#ifndef PARSE_H
# define PARSE_H
# include "libft.h"
# include "cvec.h"

typedef unsigned int		t_u32;
typedef int					t_i32;
typedef unsigned long long	t_u64;
typedef long long			t_i64;

typedef char*				t_path;
typedef t_u32				t_color;
typedef char*				t_legend;
typedef char**				t_lines;
typedef char*				t_line;
typedef t_cvec				t_lines_v;
typedef int					t_file;

enum			e_param {
	P_E = -1,
	P_M,
	P_R,
	P_NO,
	P_SO,
	P_WE,
	P_EA,
	P_UP,
	P_S,
	P_F,
	P_C,
	P_L,
	P_FOV
};

enum			e_tile_type {
	TILE_TYPE_EMPTY,
	TILE_TYPE_WALL,
	TILE_TYPE_DOOR,
	TILE_TYPE_SPRITE,
	TILE_TYPE_SPAWN
};

typedef struct	s_tile {
	enum e_tile_type	type;
	int					num;
}				t_tile;

typedef struct	s_map {
	t_legend	legend;
	size_t		width;
	size_t		height;
	t_tile		*tiles;
}				t_map;

typedef struct	s_btexs {
	t_path	north;
	t_path	east;
	t_path	south;
	t_path	west;
	t_path	up;
}				t_btexs;

typedef struct	s_config {
	int		w_res;
	int		h_res;

	t_cvec 	blocks_texs;
	size_t	block_types;
	t_cvec 	sprites_texs;
	size_t	sprite_types;

	t_color	floor_color;
	t_color	ceil_color;

	t_map	map;
	int		fov;
}				t_config;

t_config	parse_cub(t_path conf_path);
int			validate_circ(t_map *map);
t_lines_v	read_file(t_file file);

#endif
