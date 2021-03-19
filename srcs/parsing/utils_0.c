#include <stdlib.h>
#include "libft.h"
#include "parse.h"

void	errex(int e, const char *message)
{
	ft_printf("Error\n");
	ft_printf("%d: %s\n", e, message);
	exit(0);
}

t_lines_v	read_file(t_file file)
{
	t_lines_v	res;
	t_line		line;
	int			ret;

	res = cvec_new();
	ret = get_next_line(file, &line);
	while (ret > 0)
	{
		cvec_push(&res, line);
		ret = get_next_line(file, &line);
	}
	if (ret < 0)
		errex(42, "Error while read file");
	if (line != NULL)
		cvec_push(&res, line);
	return (res);
}

void	free_split(t_lines lines)
{
	int	i;

	i = 0;
	while (lines[i] != NULL)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	free_btexs(t_cvec *btexs_cvec)
{
	int		i;
	char	**btexs;

	i = 0;
	while (i < btexs_cvec->siz)
	{
		btexs = btexs_cvec->arr[i];
		free(btexs[SIDE_NORTH]);
		free(btexs[SIDE_EAST]);
		free(btexs[SIDE_WEST]);
		free(btexs[SIDE_SOUTH]);
		i++;
	}
	cvec_free_all(btexs_cvec);
}

void	check_color(t_lines lines)
{
	int	i;

	i = 0;
	if (lines[1][0] == '\0' || lines[2][0] == '\0' || lines[3][0] == '\0')
		errex(42, "Error color style, empty");
	while (lines[1][i])
		if (!ft_isdigit(lines[1][i++]))
			errex(42, "Error color style red");
	i = 0;
	while (lines[2][i])
		if (!ft_isdigit(lines[2][i++]))
			errex(42, "Error color style green");
	i = 0;
	while (lines[3][i])
		if (!ft_isdigit(lines[3][i++]))
			errex(42, "Error color style blue");
}
