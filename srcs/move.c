#include <math.h>
#include <libft.h>
#include "types.h"

void	move_by_key_1(t_vars *vars, double dist, t_point *new)
{
	if (vars->keybuff.s)
	{
		*new = vars->pl.cord;
		new->y += dist * -sin(vars->pl.angle);
		new->x += dist * -cos(vars->pl.angle);
		if (vars->conf->map.tiles[(int)new->y * vars->conf->map.w + \
			(int)new->x].type != TILE_TYPE_WALL)
			vars->pl.cord = *new;
	}
	if (vars->keybuff.d)
	{
		*new = vars->pl.cord;
		new->y += dist * cos(vars->pl.angle);
		new->x += dist * -sin(vars->pl.angle);
		if (vars->conf->map.tiles[(int)new->y * vars->conf->map.w + \
			(int)new->x].type != TILE_TYPE_WALL)
			vars->pl.cord = *new;
	}
}

void	move_by_key(t_vars *vars)
{
	double		dist;
	t_point		new;

	dist = 0.2;
	if (vars->keybuff.w)
	{
		new = vars->pl.cord;
		new.y += dist * sin(vars->pl.angle);
		new.x += dist * cos(vars->pl.angle);
		if (vars->conf->map.tiles[(int)new.y * vars->conf->map.w + \
			(int)new.x].type != TILE_TYPE_WALL)
			vars->pl.cord = new;
	}
	if (vars->keybuff.a)
	{
		new = vars->pl.cord;
		new.y += dist * -cos(vars->pl.angle);
		new.x += dist * sin(vars->pl.angle);
		if (vars->conf->map.tiles[(int)new.y * vars->conf->map.w + \
			(int)new.x].type != TILE_TYPE_WALL)
			vars->pl.cord = new;
	}
	move_by_key_1(vars, dist, &new);
}

void	key_handler(t_vars *vars)
{
	if (vars->keybuff.q)
		vars->pl.angle -= M_PI_4 / 4;
	while (vars->pl.angle < 0)
		vars->pl.angle += M_PI * 2;
	if (vars->keybuff.e)
		vars->pl.angle += M_PI_4 / 4;
	while (vars->pl.angle >= M_PI * 2)
		vars->pl.angle -= M_PI * 2;
	move_by_key(vars);
}

int	press_key_handler(int key, t_vars *vars)
{
	if (key == 53)
		exit_handler(vars);
	else if (key == 14)
		vars->keybuff.e = 1;
	else if (key == 12)
		vars->keybuff.q = 1;
	else if (key == 13)
		vars->keybuff.w = 1;
	else if (key == 0)
		vars->keybuff.a = 1;
	else if (key == 1)
		vars->keybuff.s = 1;
	else if (key == 2)
		vars->keybuff.d = 1;
	return (0);
}

int	press_realease_handler(int key, t_vars *vars)
{
	if (key == 53)
		exit_handler(vars);
	else if (key == 14)
		vars->keybuff.e = 0;
	else if (key == 12)
		vars->keybuff.q = 0;
	else if (key == 13)
		vars->keybuff.w = 0;
	else if (key == 0)
		vars->keybuff.a = 0;
	else if (key == 1)
		vars->keybuff.s = 0;
	else if (key == 2)
		vars->keybuff.d = 0;
	return (0);
}
