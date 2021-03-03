#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <debug.h>
#include <float.h>
#include "raycast.h"
#include "unistd.h"
#include "mlx.h"
#include "libft.h"
#include "cvec.h"
#include "parse.h"
#include "intmlx.h"
#include "cub3d_utils.h"

// y = kx + m
// x = (y - m) / k
// x = p(y - m)
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
	if (fabs(a.x - b.x) < 0.0001)
		return (fabs(a.y - b.y));
	else if (fabs(a.y - b.y) < 0.0001)
		return (fabs(a.x - b.x));
	return (fabs((a.x - b.x) / cos(ray)));
}

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

t_tile		*get_tile_bycord(t_caster *caster, t_vars *vars, t_point point)
{
	t_ipoint	pos;

	pos = get_ij_bypoint(caster, point);
	return (&vars->conf->map.tiles[pos.i * vars->conf->map.width + pos.j]);
}

double		sign(double a)
{
	if (a < 0)
		return (-1);
	else
		return (1);
}

void		add_sprite(t_caster *caster, t_vars *vars, t_ipoint pos, double ray)
{
	t_sprite	*sprite;
	t_point		tmp;
	double		g;
	double		n;
	double		angle;

	sprite = ft_calloc(1, sizeof(t_sprite));
//	g = tan(vars->player.angle + M_PI_2);
	tmp.x = pos.j + 0.5;
	tmp.y = pos.i + 0.5;
	angle = atan2((tmp.y - vars->player.cord.y), (tmp.x - vars->player.cord.x));
	g = tan(angle + M_PI_2);
	n = (pos.i + 0.5) - (pos.j + 0.5) * g;
	if (angle == M_PI || angle == 0)
		sprite->cross.x = tmp.x;
	else
		sprite->cross.x = (n - caster->m) / (caster->k - g);
//		sprite->cross.y = sprite->cross.x * g + n;
	if (angle == M_PI_2 || angle == 3 * M_PI_2)
		sprite->cross.y = tmp.y;
	else
		sprite->cross.y = caster->k * sprite->cross.x + caster->m;
	sprite->dist_tex = dist_points_ab(tmp, sprite->cross);
	n = ray - angle;
	while (n > vars->conf->fov)
		n = (n - M_PI) * -1;
	while (n < -vars->conf->fov)
		n = (n + M_PI) * -1;
	sprite->dist_tex = sprite->dist_tex * sign(n) + 0.5;
	if (sprite->dist_tex < 0 || sprite->dist_tex > 1)
	{
		free(sprite);
		return ;
	}
	sprite->dist = dist_points_ab(tmp, vars->player.cord);
	sprite->pos = pos;
	sprite->tile = get_tile_bycord(caster, vars, tmp);
	cvec_push(&vars->sprites, sprite);
}

t_point		get_hor_wall(t_caster *caster, t_vars *vars, double ray)
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
	dx = straight_x(caster, fir.y + caster->y_to) - fir.x;
	if (caster->x_to == 0)
		fir.x = vars->player.cord.x;
	if (fir.y < 1 || fir.y >= vars->conf->map.height
		|| fir.x < 1 || fir.x >= vars->conf->map.width)
	{
		fir.x = INFINITY * (double)caster->x_to;
		return (fir);
	}
	while (get_tile_bycord(caster, vars, fir)->type != TILE_TYPE_WALL)
	{
		if (get_tile_bycord(caster, vars, fir)->type == TILE_TYPE_SPRITE)
			add_sprite(caster, vars, get_ij_bypoint(caster, fir), ray);
		fir.x += dx;
		fir.y += caster->y_to;
		if (fir.y < 1 || fir.y >= vars->conf->map.height
			|| fir.x < 1 || fir.x >= vars->conf->map.width)
		{
			fir.y = INFINITY * (double)caster->y_to;
			return (fir);
		}
	}
	return (fir);
}

t_point	get_ver_wall(t_caster *caster, t_vars *vars, double ray)
{
	t_point	fir;
	double	dy;

	if (caster->x_to == 0)
	{
		fir.y = INFINITY * (double)caster->y_to;
		return (fir);
	}
	fir.x = angle_round(vars->player.cord.x, caster->x_to);
	fir.y = straight_y(caster, fir.x);
	dy = straight_y(caster, fir.x + caster->x_to) - fir.y;
	if (caster->y_to == 0)
		fir.y = vars->player.cord.y;
	if (fir.y < 1 || fir.y >= vars->conf->map.height
	|| fir.x < 1 || fir.x >= vars->conf->map.width)
	{
		fir.y = INFINITY * (double)caster->y_to;
		return (fir);
	}
	while (get_tile_bycord(caster, vars, fir)->type != TILE_TYPE_WALL)
	{
		if (get_tile_bycord(caster, vars, fir)->type == TILE_TYPE_SPRITE)
			add_sprite(caster, vars, get_ij_bypoint(caster, fir), ray);
		fir.y += dy;
		fir.x += caster->x_to;
		if (fir.y < 1 || fir.y >= vars->conf->map.height
			|| fir.x < 1 || fir.x >= vars->conf->map.width)
		{
			fir.y = INFINITY * (double)caster->y_to;
			return (fir);
		}
	}
	return (fir);
}

t_wall		step_cast(t_caster *caster, t_vars *vars, double ray)
{
	t_point	hor;
	t_point	ver;
	t_point	dists;
	t_wall	w;

	hor = get_hor_wall(caster, vars, ray);
	ver = get_ver_wall(caster, vars, ray);
	dists.x = dist_points_abr(vars->player.cord, hor, ray);
	dists.y = dist_points_abr(vars->player.cord, ver, ray);
	if (dists.y < dists.x)
		w.cross = ver;
	else
		w.cross = hor;
	w.pos = get_ij_bypoint(caster, w.cross);
	w.tile = &vars->conf->map.tiles[w.pos.i * vars->conf->map.width + w.pos.j];
//	cvec_push(sprs, obs);
	if (dists.y < dists.x)
		w.dist = dists.y;
	else
		w.dist = dists.x;
	return (w);
}

t_wall		cast_ray(t_vars *vars, double ray)
{
	t_caster	caster;

	while (ray >= 2 * M_PI)
		ray -= 2 * M_PI;
	while (ray < 0)
		ray += 2 * M_PI;
	cvec_clear(&vars->sprites);
	caster.k = tan(ray);
	caster.p = tan(M_PI_2 - ray);
	caster.m = (vars->player.cord.y - caster.k * vars->player.cord.x);
	set_to(&caster, ray);
	return (step_cast(&caster, vars, ray));
}