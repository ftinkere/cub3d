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
#include "conf.h"

#define GUI_TEXES 1

int		move_by_key(t_vars *vars)
{
	double		dist;
	t_point		new;

	dist = 0.2;
	if (vars->keybuff.w)
	{
		new = vars->player.cord;
		new.y += dist * sin(vars->player.angle);
		new.x += dist * cos(vars->player.angle);
		if (vars->conf->map.tiles[(int)new.y * vars->conf->map.width + (int)new.x].type != TILE_TYPE_WALL)
			vars->player.cord = new;
	}
	if (vars->keybuff.a)
	{
		new = vars->player.cord;
		new.y += dist * -cos(vars->player.angle);
		new.x += dist * sin(vars->player.angle);
		if (vars->conf->map.tiles[(int)new.y * vars->conf->map.width + (int)new.x].type != TILE_TYPE_WALL)
			vars->player.cord = new;
	}
	if (vars->keybuff.s)
	{
		new = vars->player.cord;
		new.y += dist * -sin(vars->player.angle);
		new.x += dist * -cos(vars->player.angle);
		if (vars->conf->map.tiles[(int)new.y * vars->conf->map.width + (int)new.x].type != TILE_TYPE_WALL)
			vars->player.cord = new;
	}
	if (vars->keybuff.d)
	{
		new = vars->player.cord;
		new.y += dist * cos(vars->player.angle);
		new.x += dist *-sin(vars->player.angle);
		if (vars->conf->map.tiles[(int)new.y * vars->conf->map.width + (int)new.x].type != TILE_TYPE_WALL)
			vars->player.cord = new;
	}
}

int		exit_handler(t_vars *vars)
{
	// TODO: ДА ЗАРАБОТАЙ СУКА
	// TODO:::: FREEEEEEEEEEEEEEEEEEEEEEE
	ft_printf("Exited\n");
	mlx_do_key_autorepeaton(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int		key_handler(t_vars *vars)
{
	if (vars->keybuff.q)
		vars->player.angle -= M_PI_4 / 4;
	while (vars->player.angle < 0)
		vars->player.angle += M_PI * 2;
	if (vars->keybuff.e)
		vars->player.angle += M_PI_4 / 4;
	while (vars->player.angle >= M_PI * 2)
		vars->player.angle -= M_PI * 2;
	move_by_key(vars);
}

int		press_key_handler(int key, t_vars *vars)
{
	if (key == 65307) // ESC
		exit_handler(vars);
	else if (key == 101) // E
		vars->keybuff.e = 1;
	else if (key == 113) // Q
		vars->keybuff.q = 1;
	else if (key == 119) // W
		vars->keybuff.w = 1;
	else if (key == 97) // A
		vars->keybuff.a = 1;
	else if (key == 115) // S
		vars->keybuff.s = 1;
	else if (key == 100) // D
		vars->keybuff.d = 1;
}

int		press_realease_handler(int key, t_vars *vars)
{
	if (key == 65307) // ESC
		exit_handler(vars);
	else if (key == 101) // E
		vars->keybuff.e = 0;
	else if (key == 113) // Q
		vars->keybuff.q = 0;
	else if (key == 119) // W
		vars->keybuff.w = 0;
	else if (key == 97) // A
		vars->keybuff.a = 0;
	else if (key == 115) // S
		vars->keybuff.s = 0;
	else if (key == 100) // D
		vars->keybuff.d = 0;
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

enum e_side	get_side_cross(t_wall *obst)
{
	if (obst->pos.i == obst->cross.y)
		return (SIDE_NORTH);
	if (obst->pos.j + 1 == obst->cross.x)
		return (SIDE_EAST);
	if (obst->pos.i + 1 == obst->cross.y)
		return (SIDE_SOUTH);
	if (obst->pos.j == obst->cross.x)
		return (SIDE_WEST);
//	errex(42, "Side not found error");
	return (-1);
}

t_color		get_pix_color(t_vars *vars, t_point	tex_p, t_wall wall)
{
	t_img		*img;
	t_color		color;
	enum e_side	side;

	side = get_side_cross(&wall);
	if (side == -1)
		return (shadow_dist(0x00FFFFFF, wall.dist));
	img = &vars->texs[wall.tile->num * 4 + side];
	if (side == SIDE_NORTH || side == SIDE_EAST)
		tex_p.x = 1 - tex_p.x;
	color = *img_pixel_get(img, (int)(tex_p.y * img->h), (int)(tex_p.x * img->w));
	return (shadow_dist(color, wall.dist));
}

t_point	get_tex_p(t_vars *vars, t_wall wall, t_ipoint p, double pr_h)
{
	t_point		tex_p;

	if (wall.cross.x == floor(wall.cross.x))
		tex_p.x = wall.cross.y - floor(wall.cross.y);
	else
		tex_p.x = wall.cross.x - floor(wall.cross.x);
	tex_p.y = (p.j + (pr_h - (double)(vars->conf->h_vres) / 2)) / pr_h - 0.5;
	return (tex_p);
}

double	*get_z_buf(t_vars *vars, int j, int i)
{
	return (&vars->z_buf[j * vars->img.line_length + i]);
}

int		render_spite_ray(t_vars *vars, t_sprite *sprite, int i, double ray)
{
	t_img		*img;
	int			j;
	double		pr_h;
	t_color		color;


	img = &vars->texs[vars->sprite_offset + sprite->tile->num];;
	pr_h = vars->conf->dist_proj / sprite->dist;
	j = 0;
	while (j < vars->conf->h_vres)
	{
		if (j > vars->conf->h_vres / 2. - pr_h / 2.
		&& j < vars->conf->h_vres / 2. + pr_h / 2.)
		{
			color = *img_pixel_get(img,
				(int)round(img->h * ((j + (pr_h - (double)(vars->conf->h_vres) / 2)) / pr_h - 0.5)),
				(int)round(img->w * sprite->dist_tex));
			if (color != 0
			&& (*get_z_buf(vars, j, i) >= sprite->dist || *get_z_buf(vars, j, i) == 0))
			{
				*get_z_buf(vars, j, i) = sprite->dist;
				img_pixel_put(&vars->img, j, i, shadow_dist(color, sprite->dist / 2.));
			}
		}
		j++;
	}
}

int		render_ray(t_vars *vars, t_wall wall, int i)
{
	t_ipoint	p;
	double		pr_h;

	p.i = i;
	pr_h = vars->conf->dist_proj / wall.dist;
	p.j = 0;
	while (p.j < vars->conf->h_vres)
	{
		if (p.j > vars->conf->h_vres / 2. - pr_h / 2.
		&& p.j < vars->conf->h_vres / 2. + pr_h / 2.
		&& (fabs(wall.cross.y) != INFINITY && fabs(wall.cross.x) != INFINITY)
		&& (wall.cross.y == wall.cross.y && wall.cross.x == wall.cross.x)
		&& (*get_z_buf(vars, p.j, p.i) >= wall.dist || *get_z_buf(vars, p.j, p.i) == 0))
		{
			img_pixel_put(&vars->img, p.j, p.i,
				get_pix_color(vars, get_tex_p(vars, wall, p, pr_h), wall));
			*get_z_buf(vars, p.j, p.i) = wall.dist;
		}
		else if (p.j < vars->conf->h_vres / 2.)
			img_pixel_put(&vars->img, p.j, p.i, vars->conf->ceil_color);
		else
			img_pixel_put(&vars->img, p.j, p.i, vars->conf->floor_color);
		p.j++;
	}
}

int		add_gui_img(t_vars *vars, enum e_gui_tex elem, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
					&vars->texs[vars->gui_offset + elem], x, y);
}

int		write_header(int fd, t_vars *vars);
void	write_img(int fd, t_vars *vars);

int		next_render(t_vars *vars)
{
	t_wall	wall;
	double	ray;
	int		i;
	int		s;

	i = 0;
	while(i < vars->conf->w_vres)
	{
		ray = atan2((double)i - vars->conf->w_vres / 2., vars->conf->dist_proj);
		wall = cast_ray(vars, ray + vars->player.angle);
		wall.dist *= cos(ray);
		render_ray(vars, wall, i);
		s = 0;
		while (s < vars->sprites.siz)
			render_spite_ray(vars, (t_sprite *) vars->sprites.arr[s++], i, ray);
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	vars->tim++;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->texs[vars->gui_offset + GUI_CROSS].img,
		vars->conf->w_vres / 2 - vars->texs[vars->gui_offset + GUI_CROSS].w / 2,
		vars->conf->h_vres / 2 - vars->texs[vars->gui_offset + GUI_CROSS].h / 2);
	ft_bzero(vars->z_buf, vars->conf->h_vres * vars->img.line_length
				* sizeof(double));
	key_handler(vars);
	///////
//	int fd;
//	fd = open("../screen.bmp", O_RDWR | O_CREAT);
//	write_header(fd, vars);
//	write_img(fd, vars);
//	close(fd);
//	exit_handler(vars);
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

int		img_load(t_vars *vars, t_img *img, t_path path)
{
	img->img = mlx_xpm_file_to_image(vars->mlx, path, &img->w, &img->h);
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
			img_load(vars, &vars->texs[i * 4 + j], btexs[j]);
			j++;
		}
		i++;
	}
	vars->sprite_offset = vars->conf->blocks_texs.siz * 4;
	i = 0;
	while (i < vars->conf->sprites_texs.siz)
	{
		img_load(vars, &vars->texs[vars->sprite_offset + i],
			((char*)vars->conf->sprites_texs.arr[i]));
		i++;
	}
	vars->gui_offset = vars->sprite_offset + i;
	img_load(vars, &vars->texs[vars->gui_offset + 0], "../texs/gui/cross.xpm");
	cvec_free_all(&vars->conf->blocks_texs);
	cvec_free_all(&vars->conf->sprites_texs);
}

/*
** TODO: Переделать спрайты с нуля?
** TODO: Аргумент --save
** TODO: Буфер кнопок +
** TODO: Чистое закрытие программы через крестик окна
** TODO: Показ спрайтов +
** TODO: Управление мышкой
** TODO: Коллизии
** TODO: Улучшенный конфиг: сбор путей для гуишных текстур, параметры fov и т.п.
** TODO: Разное разрешение виртуальное и реальное
** TODO: Затемнение пола с расстоянием
** TODO TOO FAR: Двери и секретки
** TODO TOO FAR: Ловушки и хилки
** TODO TOO FAR: Звуки и музыка
** TODO TOO FAR: Предметы и инвентарь
** TODO TOO FAR: Меню
** TODO TOO FAR: Уровни
*/

int		main(void)
{
	t_config	conf;
	t_vars		vars;

	vars.mlx = mlx_init();
	conf = parse_cub(&vars, "../maps/conf.cub");
	vars.conf = &conf;
	print_conf(&conf);
	vars.win = mlx_new_window(vars.mlx, conf.w_res, conf.h_res, "Cub3d");
	closed_win(vars.mlx, vars.win);
	vars.img.img = mlx_new_image(vars.mlx, conf.w_res, conf.h_res);
	vars.img.w = conf.w_res;
	vars.img.h = conf.h_vres;
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length,
								&vars.img.endian);
	vars.tim = 0;
	player_init(&vars.player, &conf.map);
//	vars.player.angle = 6.195796;
	vars.sprites = cvec_new();
	vars.texs = ft_calloc(vars.conf->blocks_texs.siz * 4
			+ vars.conf->sprites_texs.siz + GUI_TEXES, sizeof(t_img));
	vars.keybuff = keybuff_new();
	load_texs(&vars);
	vars.z_buf = ft_calloc(vars.conf->h_vres * vars.img.line_length, sizeof(double));
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
//	mlx_do_key_autorepeatoff(vars.mlx);
	mlx_do_key_autorepeaton(vars.mlx);
	mlx_hook(vars.win, 2, 1L << 0, press_key_handler, &vars);
	mlx_hook(vars.win, 3, 1L << 1, press_realease_handler, &vars);
	mlx_hook(vars.win, 33, 0, exit_handler, &vars);
	mlx_loop_hook(vars.mlx, next_render, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
