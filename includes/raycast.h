#ifndef RAYCAST_H
# define RAYCAST_H
# include "types.h"

typedef struct	s_caster {
	double	k;
	double	m;
//	t_point	last;
	int		x_to;
	int		y_to;
}				t_caster;

typedef struct	s_obst {
	t_tile	*tile;
	size_t	i;
	size_t	j;
	t_point	cross;
}				t_obst;

double	cast_ray(t_vars *vars, t_cvec *obst, double ray);

#endif
