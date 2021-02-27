#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <debug.h>
#include <raycast.h>
#include <glob.h>
#include "unistd.h"
#include "mlx.h"
#include "libft.h"
#include "cvec.h"
#include "parse.h"
#include "intmlx.h"
#include "cub3d_utils.h"
#include "map_validates.h"

void *g_mlx;

int		move_by_key(int keycode, t_vars *vars)
{
	double	dist;

	dist = 0.1;
	if (keycode == 119) // W
	{
		vars->player.cord.y += dist * sin(vars->player.angle);
		vars->player.cord.x += dist * cos(vars->player.angle);
	}
	else if (keycode == 97) // A
	{
		vars->player.cord.y -= dist * cos(vars->player.angle);
		vars->player.cord.x += dist * sin(vars->player.angle);
	}
	else if (keycode == 115) // S
	{
		vars->player.cord.y -= dist * sin(vars->player.angle);
		vars->player.cord.x -= dist * cos(vars->player.angle);
	}
	else if (keycode == 100) // D
	{
		vars->player.cord.y += dist * cos(vars->player.angle);
		vars->player.cord.x -= dist * sin(vars->player.angle);
	}
}

int		key_handler(int keycode, t_vars *vars)
{
	ft_printf("Key: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(g_mlx, vars->win);
		exit(0);
	}
	if (keycode == 113) // Q
		vars->player.angle -= M_PI_4 / 20;
	else if (keycode == 101) // E
		vars->player.angle += M_PI_4 / 20;
	while (vars->player.angle >= M_PI * 2)
		vars->player.angle -= M_PI * 2;
	move_by_key(keycode, vars);
}

t_color	shadow_dist(t_color color, double dist)
{
	double a;
	double r;
	double g;
	double b;

	a = ((color >> 24) & 0xFF);
	r = ((color >> 16) & 0xFF) * pow(0.8, dist);
	g = ((color >> 8) & 0xFF) * pow(0.8, dist);
	b = (color & 0xFF) * pow(0.8, dist);

	return (color_rgba((int)r, (int)g, (int)b, (int)a));
}

t_color	get_pix_color(t_vars *vars)
{
	t_obst	*obs;

	obs = (t_obst *)vars->obst.arr[vars->obst.siz - 1];
}

int		render_block_pix(t_vars *vars, double dist, int i, int j)
{
	int		color;

	if (i == vars->conf->w_vres / 2)
		color = shadow_dist(0x00FF0000, dist);
	else
		color = shadow_dist(0x00FFFFFF, dist);
	img_pixel_put(&vars->img, j, i, color);
}

int		render_ray(t_vars *vars, double dist, int i)
{
	int		j;
	double	pr_h;

	pr_h = vars->conf->dist_proj / dist;
		j = 0;
	while (j < vars->conf->h_vres)
	{
		if (j > vars->conf->h_vres / 2. - pr_h / 2. && j < vars->conf->h_vres / 2. + pr_h / 2.)
			render_block_pix(vars, dist, i, j);
		else if (j < vars->conf->h_vres / 2.)
			img_pixel_put(&vars->img, j, i, vars->conf->ceil_color);
		else
			img_pixel_put(&vars->img, j, i, vars->conf->floor_color);
		j++;
	}
}

int		next_render(t_vars *vars)
{
	double	ray;
	double	dist;
	int		i;

//	ray = vars->player.angle - vars->conf->fov / 2.;
	i = 0;
	while(i < vars->conf->w_vres)
	{
		ray = atan2((double)i - vars->conf->w_vres / 2., vars->conf->dist_proj);
		dist = cast_ray(vars, &vars->obst, ray + vars->player.angle);
		dist *= cos(ray);
		render_ray(vars, dist, i);
		i++;
	}
	mlx_put_image_to_window(g_mlx, vars->win, vars->img.img, 0, 0);
	vars->tim++;
//	ft_printf("%d:a: %f\n", vars->tim, vars->player.angle);

}

void	player_init(t_player *player, t_map *map)
{
	size_t	i;
	size_t	j;

	find_spawn(map, &i, &j);
	player->cord.y = i + 0.5;
	player->cord.x = j + 0.5;
	if (map->tiles[i * map->width + j].num == 0)
		player->angle = 3 * M_PI_2;
	else if (map->tiles[i * map->width + j].num == 1)
		player->angle = 0;
	else if (map->tiles[i * map->width + j].num == 2)
		player->angle = M_PI_2;
	else if (map->tiles[i * map->width + j].num == 3)
		player->angle = M_PI;
}

int		img_load(t_img *img, t_path path)
{
	img->img = mlx_xpm_file_to_image(g_mlx, path, &img->w, &img->h);
	if (!img->img)
	{
		ft_printf("Cannot load texture by path %s\n", path);
		exit(42);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
								  &img->line_length, &img->endian);
}

int		load_texs(t_vars *vars)
{
	int		i;
	int		j;
	char	**btexs;

	i = 0;
	while (i < vars->conf->blocks_texs.siz)
	{
		btexs = ((char**)vars->conf->blocks_texs.arr[i]);
		j = 0;
		while (j < 4)
		{
			img_load(&vars->texs[i * 4 + j], btexs[j]);
			j++;
		}
		i++;
	}
	vars->sprite_offset = vars->conf->blocks_texs.siz * 4;
	i = 0;
	while (i < vars->conf->sprites_texs.siz)
	{
		img_load(&vars->texs[vars->sprite_offset + i],
			((char*)vars->conf->sprites_texs.arr[i]));
		i++;
	}
	cvec_free_all(&vars->conf->blocks_texs);
	cvec_free_all(&vars->conf->sprites_texs);
}

int		main(void)
{
	t_config	conf;
	t_vars		vars;

	g_mlx = mlx_init();
	conf = parse_cub("../maps/conf.cub");
	vars.conf = &conf;
	print_conf(&conf);
	vars.win = mlx_new_window(g_mlx, conf.w_res, conf.h_res, "Cub3d");
	vars.img.img = mlx_new_image(g_mlx, conf.w_res, conf.h_res);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length,
								&vars.img.endian);
	vars.tim = 0;
	player_init(&vars.player, &conf.map);
//	vars.player.angle = 6.195796;
	vars.obst = cvec_new();
	vars.texs = ft_calloc(vars.conf->blocks_texs.siz * 4
			+ vars.conf->sprites_texs.siz, sizeof(t_img));
	load_texs(&vars);
	mlx_do_key_autorepeaton(g_mlx);
	mlx_put_image_to_window(g_mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, key_handler, &vars);
	mlx_loop_hook(g_mlx, next_render, &vars);
	mlx_loop(g_mlx);
	return (0);
}
