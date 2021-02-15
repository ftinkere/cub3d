#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "parse.h"
#include "cub3d_utils.h"
#include "mlx.h"

t_btexs		*btexs_new(void)
{
	t_btexs *res;

	res = ft_calloc(1, sizeof(t_btexs));
	if (res == NULL)
		errex(42, "Error allocated btexs");
	return (res);
}
