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

int		close_win(int keycode, t_vars *vars)
{
	ft_printf("Keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(g_mlx, vars->win);
		exit(0);
	}
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

int		render_ray(t_vars *vars, double dist, int i, double ray)
{
	double	pr_h;
	int		j;

	dist *= cos(ray);
	pr_h = vars->conf->dist_proj / dist;
	j = 0;
	while (j < vars->conf->h_vres)
	{
		if ((double)j * vars->conf->h_vres / vars->conf->h_vres > vars->conf->h_vres / 2. - pr_h / 2.
		&& (double)j * vars->conf->h_vres / vars->conf->h_vres < vars->conf->h_vres / 2. + pr_h / 2.)
			img_pixel_put(&vars->img, j, i, shadow_dist(0x00FFFFFF, dist));
		else if (j < vars->conf->h_vres / 2.)
			img_pixel_put(&vars->img, j, i, vars->conf->ceil_color);
		else if (j > vars->conf->h_vres / 2.)
			img_pixel_put(&vars->img, j, i, vars->conf->floor_color);
		j++;
	}
}

double	get_i_ray(t_vars *vars, int i)
{
	double	ray;

	ray = atan2(fabs((double)i - vars->conf->w_vres / 2.), vars->conf->dist_proj);
	if (i < vars->conf->w_vres / 2.)
		ray *= -1;
	return (ray);
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
		ray = get_i_ray(vars, i);
		dist = cast_ray(vars, &vars->obst, ray + vars->player.angle);
		render_ray(vars, dist, i, ray);
		i++;
	}
	mlx_put_image_to_window(g_mlx, vars->win, vars->img.img, 0, 0);
	vars->tim++;
	vars->player.angle += M_PI_4 / 100;
	if (vars->player.angle >= M_PI * 2)
		vars->player.angle -= M_PI * 2;
//	ft_printf("t: %d\na: %f\n\n", vars->tim, vars->player.angle);

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

int		main(void)
{
	t_config	conf;
	t_vars		vars;
	int			w;
	int			h;

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
	vars.player.angle = 4.405088;
	vars.obst = cvec_new();
	w = 0;
	while (w < conf.w_res)
	{
		h = 0;
		while (h < conf.h_res)
		{
			if (h > conf.h_res / 2)
				img_pixel_put(&vars.img, h, w, conf.floor_color);
			else
				img_pixel_put(&vars.img, h, w, conf.ceil_color);
			h++;
		}
		w++;
	}
	mlx_put_image_to_window(g_mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, close_win, &vars);
	mlx_loop_hook(g_mlx, next_render, &vars);
	mlx_loop(g_mlx);
	return (0);
}
