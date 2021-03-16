#include <raycast.h>
#include <intmlx.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <mlx.h>
#include <libft.h>
#include "types.h"

double	*get_z_buf(t_vars *vars, int j, int i)
{
	return (&vars->z_buf[j * vars->img.line_len + i]);
}

int		z_buf(t_vars *vars, int j, int i, double dist)
{
	double	z_buf;

	z_buf = *get_z_buf(vars, j, i);
	return (z_buf >= dist || z_buf == 0);
}

void	render_spite_ray(t_vars *vars, t_sprite *sprite, int i)
{
	t_img		*img;
	int			j;
	double		pr_h;
	t_color		color;

	img = &vars->texs[vars->sprite_offset + sprite->tile->num];
	pr_h = vars->conf->dist_proj / sprite->dist;
	j = 0;
	while (j < vars->conf->h_vres)
	{
		if (j > vars->conf->h_vres / 2. - pr_h / 2.
			&& j < vars->img.h / 2 + (int)pr_h / 2)
		{
			color = *img_pixel_get(img,
					(int)floor(img->h * ((j + (pr_h - \
					(double)(vars->conf->h_vres) / 2)) / pr_h - 0.5)),
					(int)floor(img->w * sprite->texp));
//			if (color != 0
			if (((color >> 24) & 0xFF) == 0 && z_buf(vars, j, i, sprite->dist))
			{
				img_pixel_put(&vars->img, j, i, shadow_dist(color,
					sprite->dist / 2.));
				*get_z_buf(vars, j, i) = sprite->dist;
			}
		}
		j++;
	}
}

//void	render_spite_ray(t_vars *vars, t_sprite *sprite, int i)
//{
//	t_img		*img;
//	int			j;
//	double		pr_h;
//	t_color		color;
//
//	img = &vars->texs[vars->sprite_offset + sprite->tile->num];
//	pr_h = vars->conf->dist_proj / sprite->dist;
//	j = (int)floor(vars->img.h / 2. - pr_h / 2.);
//	if (j < 0)
//		j = 0;
//	while (j < vars->img.h / 2. + pr_h / 2. && j < vars->img.h)
//	{
//		color = *img_pixel_get(img,
//			(int)floor(img->h * ((j + (pr_h - vars->img.h / 2.)) / pr_h - 0.5)),
//			(int)floor(img->w * sprite->texp));
//		if (color != 0 && z_buf(vars, j, i, sprite->dist))
//		{
//			*get_z_buf(vars, j, i) = sprite->dist;
//			img_pixel_put(&vars->img, j, i, shadow_dist(color, sprite->dist / 2));
//		}
//		j++;
//	}
//}

/*
**
** TODO Переоптимизировать. Реализовать три малых цикла
**
*/
void	render_ray(t_vars *vars, t_wall wall, int i)
{
	t_ipoint	p;
	double		pr_h;

	p.i = i;
	pr_h = vars->conf->dist_proj / wall.dist;
	p.j = 0;
	while (p.j < vars->conf->h_vres)
	{
		if (p.j > vars->conf->h_vres / 2. - pr_h / 2.
			&& p.j < vars->conf->h_vres / 2. + pr_h / 2.
			&& (fabs(wall.cross.y) != INFINITY && fabs(wall.cross.x) != \
			INFINITY) && (wall.cross.y == wall.cross.y && wall.cross.x == \
			wall.cross.x) && (*get_z_buf(vars, p.j, p.i) >= wall.dist || \
			*get_z_buf(vars, p.j, p.i) == 0))
		{
			img_pixel_put(&vars->img, p.j, p.i,
				get_pix_color(vars, get_tex_p(vars, wall, p, pr_h), wall));
			*get_z_buf(vars, p.j, p.i) = wall.dist;
		}
		else if (p.j < vars->conf->h_vres / 2.)
			img_pixel_put(&vars->img, p.j, p.i, vars->conf->ceil_color);
		else
			img_pixel_put(&vars->img, p.j, p.i, vars->conf->floor_color);
		p.j++;
	}
}

//void	render_ray(t_vars *vars, t_wall wall, int i)
//{
//	t_ipoint	p;
//	double		pr_h;
//
//	p.i = i;
//	pr_h = vars->conf->dist_proj / wall.dist;
//	p.j = 0;
//	while (p.j < vars->img.h / 2. && p.j < vars->conf->h_vres / 2. - pr_h / 2.)
//		img_pixel_put(&vars->img, p.j++, p.i, vars->conf->ceil_color);
//	while (p.j < vars->conf->h_vres / 2. + pr_h / 2. && p.j < vars->img.h)
//	{
//		if ((fabs(wall.cross.y) != INFINITY && \
//		fabs(wall.cross.x) != INFINITY) && \
//		(wall.cross.y == wall.cross.y && wall.cross.x == wall.cross.x) && \
//		(z_buf(vars, p.j, p.i, wall.dist)))
//		{
//			img_pixel_put(&vars->img, p.j, p.i,
//						  get_pix_color(vars, get_tex_p(vars, wall, p, pr_h), wall));
//			*get_z_buf(vars, p.j, p.i) = wall.dist;
//		}
//		p.j++;
//	}
//	while (p.j >= vars->img.h / 2. && p.j < vars->img.h && \
//	p.j >= vars->conf->h_vres / 2. + pr_h / 2.)
//		img_pixel_put(&vars->img, p.j++, p.i, vars->conf->floor_color);
//}

void	next_renderer_1(t_vars *vars)
{
	int	fd;

	if (vars->is_save)
	{
		fd = open("../screen.bmp", O_RDWR | O_CREAT);
		write_header(fd, vars);
		write_img(fd, vars);
		close(fd);
		exit_handler(vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	vars->tim++;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->texs[vars->gui_offset + G_CRS].img,
		vars->conf->w_vres / 2 - vars->texs[vars->gui_offset + G_CRS].w / 2,
		vars->conf->h_vres / 2 - vars->texs[vars->gui_offset + G_CRS].h / 2);
	ft_bzero(vars->z_buf, vars->conf->h_vres * vars->img.line_len * \
		sizeof(double));
	key_handler(vars);
}

int	next_render(t_vars *vars)
{
	t_wall	wall;
	double	ray;
	int		i;
	int		s;

	i = 0;
	while (i < vars->conf->w_vres)
	{
		ray = atan2(i - vars->img.w / 2., vars->conf->dist_proj);
		wall = cast_ray(vars, ray + vars->pl.angle);
		wall.dist *= cos(ray);
		render_ray(vars, wall, i);
		s = 0;
		while (s < vars->sprites.siz)
			render_spite_ray(vars, (t_sprite *) vars->sprites.arr[s++], i);
		i++;
	}
	next_renderer_1(vars);
	return (0);
}
