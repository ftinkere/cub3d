#include "libft.h"
#include "parse.h"
#include "cub3d_utils.h"
#include "adders_p.h"
#include "mlx.h"

void	add_p_r_1(t_vars *vars, t_config *conf, int screen_w, int screen_h)
{
	if (conf->w_res > screen_w && vars->is_save == 0)
		conf->w_vres = screen_w;
	else
		conf->w_vres = conf->w_res;
	if (conf->h_res > screen_h && vars->is_save == 0)
		conf->h_vres = screen_h;
	else
		conf->h_vres = conf->h_res;
}

int	add_p_r(t_vars *vars, t_config *conf, t_lines sline)
{
	int	screen_w;
	int	screen_h;
	int	i;

	if (sline == NULL || sline[0] == NULL || sline[1] == NULL
		|| sline[2] == NULL)
		errex(42, "Error resolution in config");
	i = 0;
	while (sline[1][i])
		if (!ft_isdigit(sline[1][i++]))
			errex(42, "Error resolution in config");
	i = 0;
	while (sline[2][i])
		if (!ft_isdigit(sline[1][i++]))
			errex(42, "Error resolution in config");
	conf->w_res = ft_atoi(sline[1]);
	conf->h_res = ft_atoi(sline[2]);
	if (conf->w_res <= 0 || conf->h_res <= 0)
		errex(42, "Error resolution in config");
	mlx_get_screen_size(vars->mlx, &screen_w, &screen_h);
	add_p_r_1(vars, conf, screen_w, screen_h);
	return (1);
}

int	add_p_s(t_config *conf, t_lines lines)
{
	int	index;

	if (ft_isdigit(lines[0][1]))
		index = ft_atoi(lines[0] + 1);
	else
		index = 0;
	if (index == conf->sprites_texs.siz)
	{
		cvec_push(&conf->sprites_texs, ft_strdup(lines[1]));
		return (1);
	}
	return (0);
}

int	add_p_f(t_config *conf, t_lines lines)
{
	int	r;
	int	g;
	int	b;

	if (!lines || !lines[0] || !lines[1] || !lines[2] || !lines[3])
		errex(42, "Error floor color style");
	check_color(lines);
	r = ft_atoi(lines[1]);
	g = ft_atoi(lines[2]);
	b = ft_atoi(lines[3]);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		errex(42, "Error floor color");
	conf->floor_color = 0 | (r << 16) | (g << 8) | b;
	return (1);
}

int	add_p_c(t_config *conf, t_lines lines)
{
	int	r;
	int	g;
	int	b;

	if (!lines || !lines[0] || !lines[1] || !lines[2] || !lines[3])
		errex(42, "Error ceil color style");
	check_color(lines);
	r = ft_atoi(lines[1]);
	g = ft_atoi(lines[2]);
	b = ft_atoi(lines[3]);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		errex(42, "Error ceil color");
	conf->ceil_color = 0 | (r << 16) | (g << 8) | b;
	return (1);
}
