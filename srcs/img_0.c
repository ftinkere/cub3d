#include <cub3d_utils.h>

int	offset(int y, int x, t_img *img)
{
	return (y * img->line_len + x * (img->bits_per_pixel / 8));
}

unsigned int	*img_pixel_get(t_img *img, int y, int x)
{
	return ((unsigned int *)(img->addr + offset(y, x, img)));
}

void	img_pixel_put(t_img *img, int y, int x, unsigned int color)
{
	*img_pixel_get(img, y, x) = color;
}

t_color	color_rgba(t_byte r, t_byte g, t_byte b, t_byte a)
{
	return ((t_u32)b | ((t_u32)g << 8) | ((t_u32)r << 16) | ((t_u32)a << 24));
}
