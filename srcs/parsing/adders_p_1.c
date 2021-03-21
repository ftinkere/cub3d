#include "libft.h"
#include "parse.h"
#include "cub3d_utils.h"
#include "adders_p.h"

int	add_p_l(t_config *conf, t_line line)
{
	if (!line)
		return (0);
	conf->map.legend = ft_strdup(line + 2);
	if (conf->map.legend == NULL)
		errex(42, "Error strdup legend");
	return (1);
}

void	add_p_side(t_config *conf, t_lines lines, enum e_param param)
{
	int		index;
	char	**btexs;

	if (ft_isdigit(lines[0][2]))
		index = ft_atoi(lines[0] + 2);
	else
		index = 0;
	while (conf->blocks_texs.siz <= index)
		cvec_push(&conf->blocks_texs, btexs_new());
	btexs = (char **)conf->blocks_texs.arr[index];
	if (param == P_NO && btexs[SIDE_NORTH] == NULL)
		btexs[SIDE_NORTH] = ft_strdup(lines[1]);
	else if (param == P_SO && btexs[SIDE_SOUTH] == NULL)
		btexs[SIDE_SOUTH] = ft_strdup(lines[1]);
	else if (param == P_WE && btexs[SIDE_WEST] == NULL)
		btexs[SIDE_WEST] = ft_strdup(lines[1]);
	else if (param == P_EA && btexs[SIDE_EAST] == NULL)
		btexs[SIDE_EAST] = ft_strdup(lines[1]);
	else
		errex(42, "Error in texture path load");
}
