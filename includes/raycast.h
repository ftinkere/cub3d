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

typedef struct	s_obst {
	t_tile	*tile;
	int		i; // y
	int		j; // x
	t_point	cross;
}				t_obst;

double	cast_ray(t_vars *vars, t_cvec *obst, double ray);
double	dist_points_ab(t_point a, t_point b);

#endif
