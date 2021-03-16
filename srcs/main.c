#include <math.h>
#include <stdlib.h>
#include <debug.h>
#include <raycast.h>
#include <glob.h>
#include <cub3d_utils.h>
#include "mlx.h"
#include "libft.h"
#include "cvec.h"
#include "parse.h"
#include "map_validates.h"
#include "conf.h"

#define GUI_TEXES 1

int	exit_handler(t_vars *vars)
{
	ft_printf("Exited\n");
	mlx_do_key_autorepeaton(vars->mlx);
	if (vars->is_save != 1)
		mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	player_init(t_player *player, t_map *map)
{
	int	i;
	int	j;

	find_spawn(map, &i, &j);
	player->cord.y = i + 0.5;
	player->cord.x = j + 0.5;
	if (map->tiles[i * map->w + j].num == 0)
		player->angle = 3 * M_PI_2;
	else if (map->tiles[i * map->w + j].num == 1)
		player->angle = 0;
	else if (map->tiles[i * map->w + j].num == 2)
		player->angle = M_PI_2;
	else if (map->tiles[i * map->w + j].num == 3)
		player->angle = M_PI;
}

void	vars_init(t_vars *vars, t_path to_conf, t_config *conf)
{
	*conf = parse_cub(vars, to_conf);
	vars->conf = conf;
	if (vars->is_save != 1)
	{
		vars->win = mlx_new_window(vars->mlx, conf->w_res, conf->h_res,
				"Cub3d");
		// MACOS TEST NEED. MUST DELETED. Без неё не закрывается на лини
//		closed_win(vars->mlx, vars->win); //
	}
	vars->img.img = mlx_new_image(vars->mlx, conf->w_res, conf->h_res);
	vars->img.w = conf->w_res;
	vars->img.h = conf->h_vres;
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_len, &vars->img.endian);
	vars->tim = 0;
	player_init(&vars->pl, &conf->map);
	vars->sprites = cvec_new();
	vars->texs = ft_calloc(vars->conf->blocks_texs.siz * 4 + \
			vars->conf->sprites_texs.siz + GUI_TEXES, sizeof(t_img));
	vars->keybuff = keybuff_new();
	load_texs(vars);
	vars->z_buf = ft_calloc(vars->conf->h_vres * vars->img.line_len,
			sizeof(double));
}

/*
** TODO: Чистое закрытие программы через крестик окна +-
** TODO: Управление мышкой -
** TODO: Коллизии +-
** TODO: Затемнение пола с расстоянием -
** TODO: Чуть-чуть оптимизации отображения
** TODO: Пофиксить баг R 1080720 +
** TODO: Пофиксить баг R +
** TODO: Пофиксить баг отсутствия параметра конфига
** TODO: Пофиксить баг RNO 1 1
** TODO: Пофиксить баг R ./wolftex/WALL54.xpm
** TODO: Пофиксить баг C 255,200,
** TODO: Пофиксить баг C 255,200,-100
** TODO: Пофиксить баг F
** TODO: Пофиксить баг f 122,122,122
** TODO: Пофиксить баг EA segfault
** TODO: Пофиксить баг EA \n EA
** TODO: Пофиксить баг NULL tex
** TODO: Пофиксить баг valid_maps/valid_map_area_001.cub segfault // Или нет...
** TODO: Проверка на суффикс .cub +
*/
int	main(int argc, char *argv[])
{
	t_config	conf;
	t_vars		vars;
	t_path		to_conf;
	int			i;

	vars.is_save = 0;
	to_conf = NULL;
	i = 1;
	if (argc < 2 || argc > 3)
		errex(42, "Arguments is wrong");
	while (i < argc)
	{
		if (ft_strncmp("--save", argv[i], 7) == 0)
			vars.is_save = 1;
		else if (ft_strlen(argv[i]) > 4 && \
		ft_strncmp(".cub", argv[i] + (int)ft_strlen(argv[i]) - 4, 5) == 0)
			to_conf = argv[i];
		else
			errex(42, "Strange argument found");
		i++;
	}
	if (to_conf == NULL)
		errex(42, "Map not set or doesn't end with .cub");
	vars.mlx = mlx_init();
	vars_init(&vars, to_conf, &conf);
	mlx_do_key_autorepeaton(vars.mlx);
	if (vars.is_save != 1)
	{
		mlx_hook(vars.win, 2, 1L << 0, press_key_handler, &vars);
		mlx_hook(vars.win, 3, 1L << 1, press_realease_handler, &vars);
//		mlx_hook(vars.win, 33, 0, exit_handler, &vars);
		mlx_hook(vars.win, 17, 1L << 17, exit_handler, &vars);
	}
	mlx_loop_hook(vars.mlx, next_render, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
