#ifndef TYPES_H
# define TYPES_H
# include "cvec.h"
# include <stdlib.h>

typedef unsigned int		t_u32;
typedef int					t_i32;
typedef unsigned long long	t_u64;
typedef long long			t_i64;
typedef unsigned char		t_byte;
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
	P_L
};

enum			e_tile_type {
	TILE_TYPE_EMPTY,
	TILE_TYPE_WALL,
	TILE_TYPE_DOOR,
	TILE_TYPE_SPRITE,
	TILE_TYPE_SPAWN,
	TILE_NOT_FOUND = -2
};

enum			e_side {
	SIDE_NOT_FOUND = -1,
	SIDE_NORTH,
	SIDE_EAST,
	SIDE_SOUTH,
	SIDE_WEST
};

enum			e_gui_tex {
	G_CRS = 0
};

typedef struct s_keybuf {
	int		w;
	int		a;
	int		s;
	int		d;
	int		q;
	int		e;
}	t_keybuf;

typedef struct s_tile {
	enum e_tile_type	type;
	int					num;
}	t_tile;

typedef struct s_map {
	t_legend	legend;
	int			w;
	int 		h;
	t_tile		*tiles;
}	t_map;

typedef struct s_config {
	int		w_res;
	int		h_res;
	int		w_vres;
	int		h_vres;

	t_cvec	blocks_texs;
	t_cvec	sprites_texs;

	t_color	floor_color;
	t_color	ceil_color;

	t_map	map;

	double	dist_proj;
	double	fov;
}	t_config;

typedef struct s_point {
	double	x;
	double	y;
}	t_point;

typedef struct s_ipoint {
	int		i;
	int		j;
}				t_ipoint;

typedef struct s_player {
	t_point	cord;
	double	angle;
}	t_player;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_vars {
	void		*mlx;
	t_img		img;
	t_player	pl;
	t_cvec		sprites;
	t_u64		tim;
	void		*win;
	t_config	*conf;
	t_img		*texs;
	int			sprite_offset;
	int			gui_offset;
	double		*z_buf;
	t_keybuf	keybuff;
	int			is_save;
}	t_vars;

int 	exit_handler(t_vars *vars);
void	move_by_key(t_vars *vars);
void	key_handler(t_vars *vars);
int		press_key_handler(int key, t_vars *vars);
int		press_realease_handler(int key, t_vars *vars);
t_color	shadow_dist(t_color color, double dist);
void	write_header(int fd, t_vars *vars); // BMP
void	write_img(int fd, t_vars *vars); // BMP
void	load_texs(t_vars *vars);
int		next_render(t_vars *vars);
void	free_btexs(t_cvec *btexs_cvec);

#endif
