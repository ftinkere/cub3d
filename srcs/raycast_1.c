#include <math.h>
#include "raycast.h"

t_point	ret(t_point p, int to, int isy)
{
	if (isy)
		p.y = INFINITY * (double)to;
	else
		p.x = INFINITY * (double)to;
	return (p);
}

t_point	get_hor_wall(t_caster *caster, t_vars *vars, double ray)
{
	t_point	fir;
	double	dx;

	fir.y = angle_round(vars->pl.cord.y, caster->y_to);
	fir.x = straight_x(caster, fir.y);
	if (caster->y_to == 0)
		return (ret(fir, caster->x_to, 0));
	dx = straight_x(caster, fir.y + caster->y_to) - fir.x;
	if (caster->x_to == 0)
		fir.x = vars->pl.cord.x;
	if (fir.y < 1 || fir.y >= vars->conf->map.h
		|| fir.x < 1 || fir.x >= vars->conf->map.w)
		return (ret(fir, caster->x_to, 0));
	while (get_tile_bycord(caster, vars, fir)->type != TILE_TYPE_WALL)
	{
		if (get_tile_bycord(caster, vars, fir)->type == TILE_TYPE_SPRITE)
			add_sprite(caster, vars, get_ij_bypoint(caster, fir), ray);
		fir.x += dx;
		fir.y += caster->y_to;
		if (fir.y < 1 || fir.y >= vars->conf->map.h
			|| fir.x < 1 || fir.x >= vars->conf->map.w)
			return (ret(fir, caster->x_to, 0));
	}
	return (fir);
}

t_point	get_ver_wall(t_caster *caster, t_vars *vars, double ray)
{
	t_point	fir;
	double	dy;

	fir.x = angle_round(vars->pl.cord.x, caster->x_to);
	fir.y = straight_y(caster, fir.x);
	if (caster->x_to == 0)
		return (ret(fir, caster->y_to, 1));
	dy = straight_y(caster, fir.x + caster->x_to) - fir.y;
	if (caster->y_to == 0)
		fir.y = vars->pl.cord.y;
	if (fir.y < 1 || fir.y >= vars->conf->map.h
		|| fir.x < 1 || fir.x >= vars->conf->map.w)
		return (ret(fir, caster->y_to, 1));
	while (get_tile_bycord(caster, vars, fir)->type != TILE_TYPE_WALL)
	{
		if (get_tile_bycord(caster, vars, fir)->type == TILE_TYPE_SPRITE)
			add_sprite(caster, vars, get_ij_bypoint(caster, fir), ray);
		fir.y += dy;
		fir.x += caster->x_to;
		if (fir.y < 1 || fir.y >= vars->conf->map.h
			|| fir.x < 1 || fir.x >= vars->conf->map.w)
			return (ret(fir, caster->y_to, 1));
	}
	return (fir);
}
