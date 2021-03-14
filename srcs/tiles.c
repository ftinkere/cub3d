#include <raycast.h>
#include <math.h>

t_ipoint	get_ij_bypoint(t_caster *caster, t_point point)
{
	t_ipoint	res;

	if (caster->y_to < 0 && floor(point.x) != point.x)
		res.i = floor(point.y - 1);
	else
		res.i = floor(point.y);
	if (caster->x_to < 0 && floor(point.y) != point.y)
		res.j = floor(point.x - 1);
	else
		res.j = floor(point.x);
	return (res);
}

t_tile	*get_tile_bycord(t_caster *caster, t_vars *vars, t_point point)
{
	t_ipoint	pos;

	pos = get_ij_bypoint(caster, point);
	return (&vars->conf->map.tiles[pos.i * vars->conf->map.w + pos.j]);
}
