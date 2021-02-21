#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "parse.h"
#include "cub3d_utils.h"
#include "mlx.h"
#include "adders_p.h"
#include "map_validates.h"
#include "math.h"

enum e_param	get_param(t_line line)
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

int				add_conf(t_config *conf, t_line line)
{
	t_lines			lines;
	enum e_param	param;

	lines = ft_split(line, " ,");
	param = get_param(lines[0]);
	if (param == P_M)
		return (P_M);
	else if (param == P_E)
		return (P_E);
	else if (param == P_R)
		add_p_r(conf, lines);
	else if (param >= P_NO && param <= P_UP)
		add_p_side(conf, lines, param);
	else if (param == P_L)
		add_p_l(conf, line);
	else if (param == P_S)
		add_p_s(conf, lines);
	else if (param == P_F)
		add_p_f(conf, lines);
	else if (param == P_C)
		add_p_c(conf, lines);
	free_split(lines);
	return (param);
}

void			conf_init(t_config *conf)
{
	conf->h_res = 42;
	conf->w_res = 42;
	conf->w_vres = 320;
	conf->h_vres = 200;
	conf->blocks_texs = cvec_new();
	conf->sprites_texs = cvec_new();
	conf->ceil_color = 0x00000000;
	conf->floor_color = 0x00000000;
	conf->map.tiles = NULL;
	conf->map.height = 0;
	conf->map.width = 0;
	conf->map.legend = "0E 1W0 2S0 DD0 NNS0 EES1 SSS2 WWS3";
	conf->fov = M_PI / 3;
	conf->scale = 64;
	conf->dw = conf->w_vres / conf->scale;
	conf->dh = conf->h_vres / conf->scale;
	conf->dist_proj = conf->dw / (2 * tan(conf->fov / 2));
}
