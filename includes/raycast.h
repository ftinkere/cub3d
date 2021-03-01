#ifndef RAYCAST_H
# define RAYCAST_H

# include <glob.h>
# include "types.h"

typedef struct	s_caster {
	double	k;
	double	p;
	double	m;
	int		x_to;
	int		y_to;
}				t_caster;

typedef struct	s_wall {
	t_tile		*tile;
	t_ipoint	pos;
	t_point		cross;
	double		dist;
}				t_wall;

typedef struct	s_sprite {
	t_tile		*tile;
	t_ipoint	pos;
	t_point		cross;
	double		dist;
	double		dist_tex;
}				t_sprite;

t_wall	cast_ray(t_vars *vars, double ray);
double	dist_points_ab(t_point a, t_point b);

#endif
