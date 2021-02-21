#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <debug.h>
#include <raycast.h>
#include "unistd.h"
#include "mlx.h"
#include "libft.h"
#include "cvec.h"
#include "parse.h"
#include "intmlx.h"
#include "cub3d_utils.h"

// y = kx + m
// x = (y - m) / k
// k = (y - m) / x = tgα
// m = y - kx

double	straight_x(t_caster *caster, double y)
{
	return ((y - caster->m) * caster->p);
}

double	straight_y(t_caster *caster, double x)
{
	return (caster->k * x + caster->m);
}

void	set_to(t_caster *caster, double ray)
{
	if (ray > 0 && ray < M_PI)
		caster->y_to = 1;
	else if (ray == 0 || ray == M_PI)
		caster->y_to = 0;
	else
		caster->y_to = -1;
	if (ray > M_PI_2 && ray < 3 * M_PI_2)
		caster->x_to = -1;
	else if (ray == M_PI_2 || ray == 3 * M_PI_2)
		caster->x_to = 0;
	else
		caster->x_to = 1;
}

double	angle_round(double	cord, int to)
{
	if (to == 0)
		return (cord);
	else if (to < 0)
		return (floor(cord));
	else if (to > 0)
		return (ceil(cord));
}

double	dist_points_ab(t_point a, t_point b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}

double	dist_points_abr(t_point a, t_point b, double ray)
{
	return (fabs((a.x - b.x) / cos(ray)));
}

void	get_ij_bypoint(t_caster *caster, t_point point, size_t *i, size_t *j)
{
	if (caster->y_to < 0)
		*i = floor(point.y - 1);
	else
		*i = floor(point.y);
	if (caster->x_to < 0)
		*j = floor(point.x - 1);
	else
		*j = floor(point.x);
}

t_tile	*get_tile_bycord(t_caster *caster, t_vars *vars, t_point point)
{
	size_t	i;
	size_t	j;

	get_ij_bypoint(caster, point, &i, &j);
	return (&vars->conf->map.tiles[i * vars->conf->map.width + j]);
}

t_point	get_hor_wall(t_caster *caster, t_vars *vars)
{
	t_point	fir;
	double	dx;

	if (caster->y_to == 0) // TODO inf-inf
	{
		fir.x = INFINITY * (double)caster->x_to;
		return (fir);
	}
	fir.y = angle_round(vars->player.cord.y, caster->y_to);
	fir.x = straight_x(caster, fir.y);
	dx = straight_x(caster, fir.y + 1) - fir.x;
	if (fir.y < 1 || fir.y > vars->conf->map.height
		|| fir.x < 1 || fir.x > vars->conf->map.width)
	{
		fir.x = INFINITY * (double)caster->x_to;
		return (fir);
	}
	while (get_tile_bycord(caster, vars, fir)->type != TILE_TYPE_WALL)
	{
		fir.x += dx;
		fir.y += 1;
		if (fir.y < 1 || fir.y > vars->conf->map.height
			|| fir.x < 1 || fir.x > vars->conf->map.width)
		{
			fir.y = INFINITY * (double)caster->y_to;
			return (fir);
		}
	}
	return (fir);
}

t_point	get_ver_wall(t_caster *caster, t_vars *vars)
{
	t_point	fir;
	double	dy;

	if (caster->x_to == 0) // TODO inf-inf
	{
		fir.y = INFINITY * (double)caster->y_to;
		return (fir);
	}
	fir.x = angle_round(vars->player.cord.x, caster->x_to);
	fir.y = straight_y(caster, fir.x);
	dy = straight_y(caster, fir.x + 1) - fir.y;
	if (fir.y < 1 || fir.y > vars->conf->map.height
	|| fir.x < 1 || fir.x > vars->conf->map.width)
	{
		fir.y = INFINITY * (double)caster->y_to;
		return (fir);
	}
	while (get_tile_bycord(caster, vars, fir)->type != TILE_TYPE_WALL)
	{
		fir.y += dy;
		fir.x += 1;
		if (fir.y < 1 || fir.y > vars->conf->map.height
			|| fir.x < 1 || fir.x > vars->conf->map.width)
		{
			fir.y = INFINITY * (double)caster->y_to;
			return (fir);
		}
	}
	return (fir);
}

int		step_cast(t_caster *caster, t_vars *vars, t_cvec *obst, double ray)
{
	t_point	hor;
	t_point	ver;
	t_obst	*obs;

	hor = get_hor_wall(caster, vars);
	ver = get_ver_wall(caster, vars);
	obs = ft_calloc(1, sizeof(t_obst));
	if (dist_points_abr(vars->player.cord, ver, ray) < dist_points_abr(vars->player.cord, hor, ray))
		obs->cross = ver;
	else
		obs->cross = hor;
	get_ij_bypoint(caster, obs->cross, &obs->i, &obs->j);
	obs->tile = &vars->conf->map.tiles[obs->i * vars->conf->map.width + obs->j];
	cvec_push(obst, obs);
}

double	cast_ray(t_vars *vars, t_cvec *obst, double ray)
{
	t_caster	caster;

	cvec_clear(obst);
	caster.k = tan(ray);
	caster.p = tan(M_PI_2 - ray);
	caster.m = (vars->player.cord.y - caster.k * vars->player.cord.x);
	set_to(&caster, ray);
	step_cast(&caster, vars, obst, ray);
	return (dist_points_abr(((t_obst*)obst->arr[0])->cross, vars->player.cord, ray)); // потом брать последний
}