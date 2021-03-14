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
