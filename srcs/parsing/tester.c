#include <cub3d_utils.h>
#include <libft.h>

void	tester_step(enum e_param *param, int *i, int tester[10], t_lines_v lin)
{
	t_lines			spl;

	spl = ft_split_str(lin.arr[*i], " ,");
	get_param(spl[0], param);
	if (*param != P_E)
		tester[(int)*param]++;
	(*i)++;
	free_split(spl);
}

void	tester_raw(t_lines_v lines)
{
	enum e_param	param;
	int				i;
	int				tester[10];

	i = 0;
	param = P_E;
	ft_bzero(&tester, sizeof(int) * 10);
	while (i < lines.siz && param != P_M)
		tester_step(&param, &i, tester, lines);
	i = 1;
	while (i < (int)P_L)
	{
		if (!(i >= P_NO && i <= P_S) && tester[i] != 1)
			errex(i, "In config many or not one of param");
		i++;
	}
	if (tester[P_NO] != tester[P_SO] || tester[P_SO] != tester[P_WE] || \
	tester[P_WE] != tester[P_EA])
		errex(42, "Textures count not equal");
}

void	test_conf(t_config *conf)
{
	if (conf->w_res <= 0 || conf->h_res <= 0)
		errex(42, "Error, R not found in config");
}
