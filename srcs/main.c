#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <debug.h>
#include "unistd.h"
#include "mlx.h"
#include "libft.h"
#include "cvec.h"
#include "parse.h"
#include "intmlx.h"

void *g_mlx;

int		main(void) // add to read conf
{
	t_config	conf;
	void		*mlx_win;
	t_img		img;
	int			w;
	int			h;

	g_mlx = mlx_init();
	conf = parse_cub("../conf.cub");
	print_conf(&conf);
	mlx_win = mlx_new_window(g_mlx, conf.w_res, conf.h_res, "Cub3d");
	img.img = mlx_new_image(g_mlx, conf.w_res, conf.h_res);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	w = 0;
	while (w < conf.w_res)
	{
		h = 0;
		while (h < conf.h_res)
		{
			if (h > conf.h_res / 2)
			{
				img_pixel_put(&img, h, w, gamma_color(conf.floor_color));
			}
			else
			{
				img_pixel_put(&img, h, w, gamma_color(conf.ceil_color));
			}
			h++;
		}
		w++;
	}
	mlx_put_image_to_window(g_mlx, mlx_win, img.img, 0, 0);
	mlx_loop(g_mlx);
	return (0);
}
