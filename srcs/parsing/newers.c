#include "libft.h"
#include "cub3d_utils.h"

char	**btexs_new(void)
{
	char	**res;

	res = ft_calloc(4, sizeof(char *));
	if (res == NULL)
		errex(42, "Error allocated btexs");
	return (res);
}
