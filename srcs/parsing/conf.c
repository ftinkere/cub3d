#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "parse.h"
#include "cub3d_utils.h"
#include "adders_p.h"
#include "math.h"

void	get_param(t_line line, enum e_param *res)
{
	*res = P_E;
	if ((line == NULL || line[0] == '\0'))
		return ;
	*res = P_M;
	if (!ft_memcmp(line, "R", 1))
		*res = P_R;
	if (!ft_memcmp(line, "S", 1))
		*res = P_S;
	if (!ft_memcmp(line, "NO", 2))
		*res = P_NO;
	if (!ft_memcmp(line, "SO", 2))
		*res = P_SO;
	if (!ft_memcmp(line, "WE", 2))
		*res = P_WE;
	if (!ft_memcmp(line, "EA", 2))
		*res = P_EA;
	if (!ft_memcmp(line, "UP", 2))
		*res = P_UP;
	if (!ft_memcmp(line, "F", 1))
		*res = P_F;
	if (!ft_memcmp(line, "C", 1))
		*res = P_C;
	if (!ft_memcmp(line, "L", 1))
		*res = P_L;
}

int	add_conf(t_vars *vars, t_config *conf, t_line line)
{
	t_lines			lines;
	enum e_param	param;

	lines = ft_split_str(line, " ,");
	get_param(lines[0], &param);
	if (param == P_M)
		return (P_M);
	else if (param == P_E)
		return (P_E);
	else if (param == P_R)
		add_p_r(vars, conf, lines);
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

void	conf_init(t_config *conf)
{
	conf->h_res = 42;
	conf->w_res = 42;
	conf->w_vres = 800;
	conf->h_vres = 600;
	conf->blocks_texs = cvec_new();
	conf->sprites_texs = cvec_new();
	conf->ceil_color = 0x00000000;
	conf->floor_color = 0x00000000;
	conf->map.tiles = NULL;
	conf->map.h = 0;
	conf->map.w = 0;
	conf->map.legend = "0E 1W0 2S0 DD0 NNS0 EES1 SSS2 WWS3";
	conf->fov = M_PI / 2.5;
	conf->dist_proj = (double)conf->w_vres / (2 * tan(conf->fov / 2));
}

t_config	parse_cub(t_vars *vars, t_path conf_path)
{
	t_config	conf;
	t_file		conf_file;
	t_lines_v	lines;
	int			i;
	int			param;

	conf_init(&conf);
	conf_file = open(conf_path, O_RDONLY);
	lines = read_file(conf_file);
	close(conf_file);
	i = 0;
	param = 42;
	while (i < lines.siz && param != P_M)
		param = add_conf(vars, &conf, lines.arr[i++]);
	conf.w_vres = conf.w_res;
	conf.h_vres = conf.h_res;
	if (param == P_M)
		parse_map(&conf.map, &lines, i - 1);
	else
		errex(42, "Map not found in .cub");
	if (!validate_circ(&conf.map))
		errex(42, "Map not valid. Player can go to end of map");
	free(lines.arr);
	return (conf);
}
