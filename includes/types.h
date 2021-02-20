#ifndef TYPES_H
# define TYPES_H
# include "cvec.h"

typedef unsigned int		t_u32;
typedef int					t_i32;
typedef unsigned long long	t_u64;
typedef long long			t_i64;
typedef	unsigned char		t_byte;
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
	int		w_vres;
	int		h_vres;
	double	dw;
	double	dh;
	double	scale;

	t_cvec 	blocks_texs;
	t_cvec 	sprites_texs;

	t_color	floor_color;
	t_color	ceil_color;

	t_map	map;

	double	fov;
	double	dist_proj;
}				t_config;

typedef struct	s_point {
	double	x;
	double	y;
}				t_point;

typedef struct	s_player {
	t_point	cord;
	double	angle;
}				t_player;

typedef struct	s_img {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}				t_img;

typedef struct	s_vars {
	t_img		img;
	t_player	player;
	t_u64		tim;
	void		*win;
	t_config	*conf;
}				t_vars;

#endif
