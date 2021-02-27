#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "parse.h"
#include "cub3d_utils.h"
#include "mlx.h"

char		**btexs_new(void)
{
	char	**res;

	res = ft_calloc(4, sizeof(char*));
	if (res == NULL)
		errex(42, "Error allocated btexs");
	return (res);
}
