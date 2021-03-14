#include <stdlib.h>
#include "libft.h"
#include "parse.h"

void	errex(int e, const char *message)
{
	ft_printf("Exit: %d: %s\n", e, message);
	exit(e);
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
