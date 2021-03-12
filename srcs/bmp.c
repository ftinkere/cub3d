#include <types.h>
#include <unistd.h>
#include <cub3d_utils.h>
#include "intmlx.h"

void	set_int(unsigned char *block, int i)
{
	block[0] = i & 0xFF;
	block[1] = (i >> 8) & 0xFF;
	block[2] = (i >> 16) & 0xFF;
	block[3] = (i >> 24) & 0xFF;
}

int		write_header(int fd, t_vars *vars)
{
	int				i;
	unsigned char	header[54];

	i = 0;
	while (i < 54)
		header[i++] = 0;
	header[0x0] = 'B';
	header[0x1] = 'M';
	set_int(&header[0x2], 54 + vars->img.line_length * vars->img.h);
	header[0xA] = 54;
	header[0xE] = 40;
	set_int(&header[0x12], vars->img.w);
	set_int(&header[0x16], vars->img.h);
	header[0x1A] = 1;
	header[0x1C] = 32;
	header[0x22] = vars->img.line_length;
	if (write(fd, header, 54) < 0)
		errex(42, "Error writing image");
}

void	write_img(int fd, t_vars *vars)
{
	int		i;
	int		j;
	t_color	col;

//	write(fd, vars->img.addr, vars->img.line_length * vars->img.h);
	i = vars->img.h - 1;
	while (i >= 0)
	{
		write(fd, vars->img.addr + i * vars->img.line_length, vars->img.line_length);
		i--;
	}
//	i = 0;
//	while (i < vars->img.w)
//	{
//		j = 0;
//		while (j < vars->img.h) {
//			col = *img_pixel_get(&vars->img, i, j);
////			col = col | vars->img.addr[i + 1] << 8
////				  | vars->img.addr[i + 2] << 16 | vars->img.addr[i + 3] << 24;
//			if (write(fd, &col, 4) < 0)
//				errex(42, "Error writing pixel");
//			j++;
//		}
//		i++;
//	}
}