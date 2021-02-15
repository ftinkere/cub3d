#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "parse.h"
#include "cub3d_utils.h"
#include "adders_p.h"
#include "mlx.h"

extern void *g_mlx;

int			add_p_r(t_config *conf, t_lines sline)
{
	int screen_w;
	int screen_h;

	if (sline == NULL || sline[0] == NULL || sline[1] == NULL
		|| sline[2] == NULL)
		return (0);
	conf->w_res = ft_atoi(sline[1]);
	conf->h_res = ft_atoi(sline[2]);
	if (conf->w_res <= 0)
		errex(42, "Error resolution in config");
	else if (conf->h_res <= 0)
		errex(42, "Error resolution in config");
	mlx_get_screen_size(g_mlx, &screen_w, &screen_h);
	if (conf->w_res > screen_w)
		conf->w_res = screen_w;
	if (conf->h_res > screen_h)
		conf->h_res = screen_h;
	return (1);
}

int			add_p_s(t_config *conf, t_lines lines)
{
	size_t	index;

	index = ft_isdigit(lines[0][1]) ? ft_atoi(lines[0] + 1) : 0;
	if (index == conf->sprites_texs.siz)
	{
		cvec_push(&conf->sprites_texs, ft_strdup(lines[1]));
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

void		add_p_side(t_config *conf, t_lines lines, enum e_param param)
{
	size_t	index;
	t_btexs	*btexs;

	index = ft_isdigit(lines[0][2]) ? ft_atoi(lines[0] + 2) : 0;
	while (conf->blocks_texs.siz <= index)
		cvec_push(&conf->blocks_texs, btexs_new());
	btexs = (t_btexs*)conf->blocks_texs.arr[index];
	if (param == P_NO)
		btexs->north = ft_strdup(lines[1]);
	else if (param == P_SO)
		btexs->south = ft_strdup(lines[1]);
	else if (param == P_WE)
		btexs->west = ft_strdup(lines[1]);
	else if (param == P_EA)
		btexs->east = ft_strdup(lines[1]);
	else if (param == P_UP)
		btexs->up = ft_strdup(lines[1]);
}
