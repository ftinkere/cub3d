#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <cub3d_utils.h>
#include "unistd.h"
#include "mlx.h"
#include "libft.h"
#include "cvec.h"
#include "parse.h"
#include "intmlx.h"

int				offset(int y, int x, t_img *img)
{
	return (y * img->line_length + x * (img->bits_per_pixel / 8));
}

unsigned int	*img_pixel_get(t_img *img, int y, int x)
{
	return (unsigned int*)(img->addr + offset(y, x, img));
}

void			img_pixel_put(t_img *img, int y, int x, unsigned int color)
{
	*img_pixel_get(img, y, x) = color;
}

t_color			color_rgba(t_byte r, t_byte g, t_byte b, t_byte a)
{
	return ((t_u32)b | ((t_u32)g << 8) | ((t_u32)r << 16) | ((t_u32)a << 24));
}

t_color			color_norm(double r, double g, double b, double a)
{
	return (int)(b * 255) | ((int)(g * 255) << 8) | ((int)(r * 255) << 16)
							| ((int)(a * 255) << 24);
}

t_color			gcolor_rgba(t_byte r, t_byte g, t_byte b, t_byte a)
{
	return
		((int)(pow(b / 255., 1/2.2) * 255)
	|	((int)(pow(g / 255., 1/1.2) * 255) << 8)
	|	((int)(pow(r / 255., 1/1.2) * 255) << 16)
	|	((int)(pow(a / 255., 1/1.2) * 255) << 24));
}

t_color			gcolor_norm(double r, double g, double b, double a)
{
	return
		((int)(pow(b, 1/2.2) * 255)
	 |	((int)(pow(g, 1/1.2) * 255) << 8)
	 |	((int)(pow(r, 1/1.2) * 255) << 16)
	 |	((int)(pow(a, 1/1.2) * 255) << 24));
}

unsigned int gcolor_int(unsigned int color)
{
	double a;
	double r;
	double g;
	double b;

	a = pow(((color >> 24) & 0xFF) / (double)255, 1/1.2);
	r = pow(((color >> 16) & 0xFF) / (double)255, 1/1.2);
	g = pow(((color >> 8) & 0xFF) / (double)255, 1/1.2);
	b = pow((color & 0xFF) / (double)255, 1/2.2);

	return (int)(b * 255) | ((int)(g * 255) << 8) | ((int)(r * 255) << 16) | ((int)(a * 255) << 24);
}