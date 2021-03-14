#include <raycast.h>
#include <intmlx.h>
#include "math.h"
#include "types.h"

enum e_side	get_side_cross(t_wall *obst)
{
	if (obst->pos.i == obst->cross.y)
		return (SIDE_NORTH);
	if (obst->pos.j + 1 == obst->cross.x)
		return (SIDE_EAST);
	if (obst->pos.i + 1 == obst->cross.y)
		return (SIDE_SOUTH);
	if (obst->pos.j == obst->cross.x)
		return (SIDE_WEST);
	return (SIDE_NOT_FOUND);
}

t_color	get_pix_color(t_vars *vars, t_point	tex_p, t_wall wall)
{
	t_img		*img;
	t_color		color;
	enum e_side	side;

	side = get_side_cross(&wall);
	if (side == SIDE_NOT_FOUND)
		return (shadow_dist(0x00FFFFFF, wall.dist));
	img = &vars->texs[wall.tile->num * 4 + side];
	if (side == SIDE_NORTH || side == SIDE_EAST)
		tex_p.x = 1 - tex_p.x;
	color = *img_pixel_get(img, (int)(tex_p.y * img->h),
			(int)(tex_p.x * img->w));
	return (shadow_dist(color, wall.dist));
}

t_point	get_tex_p(t_vars *vars, t_wall wall, t_ipoint p, double pr_h)
{
	t_point		tex_p;

	if (wall.cross.x == floor(wall.cross.x))
		tex_p.x = wall.cross.y - floor(wall.cross.y);
	else
		tex_p.x = wall.cross.x - floor(wall.cross.x);
	tex_p.y = (p.j + (pr_h - (double)(vars->conf->h_vres) / 2)) / pr_h - 0.5;
	return (tex_p);
}
