#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
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

unsigned int gamma_color(unsigned int color)
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