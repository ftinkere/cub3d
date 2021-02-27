#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "parse.h"
#include "mlx.h"

void		errex(int e, const char *message)
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
	while ((ret = get_next_line(file, &line)) > 0)
	{
		if (ret < 0)
			errex(42, "Error while read file");
		cvec_push(&res, line);
	}
	if (line != NULL)
		cvec_push(&res, line);
	return (res);
}

void		free_split(t_lines lines)
{
	int i;

	i = 0;
	while (lines[i] != NULL)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}
