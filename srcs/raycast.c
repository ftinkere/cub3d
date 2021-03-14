#include <math.h>
#include "raycast.h"
#include "cvec.h"

void	set_to(t_caster *caster, double ray)
{
	if (fabs(ray) < 0.00001 || fabs(ray - M_PI) < 0.00001)
		caster->y_to = 0;
	else if (ray > 0 && ray < M_PI)
		caster->y_to = 1;
	else
		caster->y_to = -1;
	if (fabs(ray - M_PI_2) < 0.00001 || fabs(ray - 3 * M_PI_2) < 0.00001)
		caster->x_to = 0;
	else if (ray > M_PI_2 && ray < 3 * M_PI_2)
		caster->x_to = -1;
	else
		caster->x_to = 1;
}

t_wall	step_cast(t_caster *caster, t_vars *vars, double ray)
{
	t_point	hor;
	t_point	ver;
	t_point	dists;
	t_wall	w;

	hor = get_hor_wall(caster, vars, ray);
	ver = get_ver_wall(caster, vars, ray);
	dists.x = dist_abr(vars->pl.cord, hor, ray);
	dists.y = dist_abr(vars->pl.cord, ver, ray);
	if (dists.y < dists.x)
		w.cross = ver;
	else
		w.cross = hor;
	w.pos = get_ij_bypoint(caster, w.cross);
	w.tile = &vars->conf->map.tiles[w.pos.i * vars->conf->map.w + w.pos.j];
	if (dists.y < dists.x)
		w.dist = dists.y;
	else
		w.dist = dists.x;
	return (w);
}

t_wall	cast_ray(t_vars *vars, double ray)
{
	t_caster	caster;

	while (ray >= 2 * M_PI)
		ray -= 2 * M_PI;
	while (ray < 0)
		ray += 2 * M_PI;
	cvec_clear(&vars->sprites);
	caster.k = tan(ray);
	caster.p = tan(M_PI_2 - ray);
	caster.m = (vars->pl.cord.y - caster.k * vars->pl.cord.x);
	set_to(&caster, ray);
	return (step_cast(&caster, vars, ray));
}
