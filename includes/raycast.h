#ifndef RAYCAST_H
# define RAYCAST_H

# include <glob.h>
# include "types.h"

typedef struct s_caster {
	double	k;
	double	p;
	double	m;
	int		x_to;
	int		y_to;
}	t_caster;

typedef struct s_wall {
	t_tile		*tile;
	t_ipoint	pos;
	t_point		cross;
	double		dist;
}	t_wall;

typedef struct s_sprite {
	t_tile		*tile;
	t_point		cross;
	double		dist;
	double		texp;
}	t_sprite;

t_wall		cast_ray(t_vars *vars, double ray);
double		dist_ab(t_point a, t_point b);
void		set_to(t_caster *caster, double ray);
t_tile		*get_tile_bycord(t_caster *caster, t_vars *vars, t_point point);
double		anrm(double ang);
double		normilize2(double ang);
t_color		get_pix_color(t_vars *vars, t_point	tex_p, t_wall wall);
t_point		get_tex_p(t_vars *vars, t_wall wall, t_ipoint p, double pr_h);
void		render_ray(t_vars *vars, t_wall wall, int i);
void		render_spite_ray(t_vars *vars, t_sprite *sprite, int i);
double		straight_x(t_caster *caster, double y);
double		straight_y(t_caster *caster, double x);
double		angle_round(double	cord, int to);
double		dist_ab(t_point a, t_point b);
double		dist_abr(t_point a, t_point b, double ray);
double		sign(double a);
void		add_sprite(t_caster *caster, t_vars *vars, t_ipoint pos, double ry);
t_point		get_hor_wall(t_caster *caster, t_vars *vars, double ray);
t_point		get_ver_wall(t_caster *caster, t_vars *vars, double ray);
t_ipoint	get_ij_bypoint(t_caster *caster, t_point point);

#endif
