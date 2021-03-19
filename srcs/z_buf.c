#include <types.h>

double	*get_z_buf(t_vars *vars, int j, int i)
{
	return (&vars->z_buf[j * vars->img.line_len + i]);
}

int	z_buf(t_vars *vars, int j, int i, double dist)
{
	double	z_buf;

	z_buf = *get_z_buf(vars, j, i);
	return (z_buf >= dist || z_buf == 0);
}
