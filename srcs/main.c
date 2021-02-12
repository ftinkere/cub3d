#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include "unistd.h"
#include "mlx.h"
#include "libft.h"
#include "cvec.h"
#include "parse.h"

typedef struct s_data {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

void *mlx;

int				offset(int y, int x, t_data *img)
{
	return (y * img->line_length + x * (img->bits_per_pixel / 8));
}

unsigned int	*img_pixel_get(t_data *img, int y, int x) {
	return (unsigned int*)(img->addr + offset(y, x, img));
}

void			img_pixel_put(t_data *img, int y, int x, unsigned int color)
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

int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type)
{
	int	x;
	int	y;
	int	opp;
	int	dec;
	int	color;
	int	color2;
	unsigned char *ptr;

	int local_endian = 0;
	opp = bpp/8;
	printf("(opp : %d) ",opp);
	y = h;
	while (y--)
	{
		ptr = data+y*sl;
		x = w;
		while (x--)
		{
			if (type==2)
				color = (y*255)/w+((((w-x)*255)/w)<<16)
						+(((y*255)/h)<<8);
			else
				color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
			color = gamma_color(color);
			color2 = mlx_get_color_value(mlx,color);
			dec = opp;
			while (dec--)
				if (endian==local_endian)
				{
					if (endian)
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[4-opp+dec];
					else
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[dec];
				}
				else
				{
					if (endian)
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[opp-1-dec];
					else
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[3-dec];
				}
		}
	}

}

void	print_map(t_map *map)
{
	int	i = 0, j;

	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			ft_printf("%d", map->tiles[i * map->weight + j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_conf(t_config *conf)
{
	ft_printf("w: %4d\nh: %4d\n", conf->w_res, conf->h_res);
	ft_printf("btexs: %d\n", conf->block_types);
	ft_printf("NO: %s\n", ((t_btexs*)conf->blocks_texs.arr[0])->north);
	ft_printf("SO: %s\n", ((t_btexs*)conf->blocks_texs.arr[0])->south);
	ft_printf("WE: %s\n", ((t_btexs*)conf->blocks_texs.arr[0])->west);
	ft_printf("EA: %s\n", ((t_btexs*)conf->blocks_texs.arr[0])->east);
	ft_printf("UP: %s\n", ((t_btexs*)conf->blocks_texs.arr[0])->up);
	ft_printf("S0: %s\n", conf->sprites_texs.arr[0]);
	ft_printf("S1: %s\n", conf->sprites_texs.arr[1]);

	int a,r,g,b;
	a = (conf->floor_color & 0xFF000000) >> 24;
	r = (conf->floor_color & 0x00FF0000) >> 16;
	g = (conf->floor_color & 0x0000FF00) >> 8;
	b = conf->floor_color & 0x000000FF;
	ft_printf("Floor: %3d, r: %3d, g: %3d, b: %3d\n", a, r, g, b);

	a = (conf->ceil_color & 0xFF000000) >> 24;
	r = (conf->ceil_color & 0x00FF0000) >> 16;
	g = (conf->ceil_color & 0x0000FF00) >> 8;
	b = conf->ceil_color & 0x000000FF;
	ft_printf("Ceil: %3d, r: %3d, g: %3d, b: %3d\n", a, r, g, b);
	ft_printf("\nMAP:\n");
	print_map(&conf->map);
}

int		main()
{
	t_lines_v	file_data;
	t_file		file;
	t_config	conf;
	void	*mlx_win;
	t_data	img;
	int i;

	mlx = mlx_init();
	conf = parse_cub("../conf.cub");
	print_conf(&conf);

	mlx_win = mlx_new_window(mlx, conf.w_res, conf.h_res, "Cub3d");
	img.img = mlx_new_image(mlx, conf.w_res, conf.h_res);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	color_map_2(
			img.addr,
			img.bits_per_pixel,
			img.line_length,
			conf.w_res,
			conf.h_res,
			img.endian,
			1
			);
	int w = 0, h = 0;
	while (w < conf.w_res) {
		h = 0;
		while (h < conf.h_res) {
			if (h > conf.h_res / 2) {
				img_pixel_put(&img, h, w, gamma_color(conf.floor_color));
			} else {
				img_pixel_put(&img, h, w, gamma_color(conf.ceil_color));
			}
			h++;
		}
		w++;
	}
//	img_pixel_put(&img, 50, 50, mlx_get_color_value(mlx, 0x00FFFFFF));
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
	return 0;
}
