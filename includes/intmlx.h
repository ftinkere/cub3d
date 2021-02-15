#ifndef INTMLX_H
#define INTMLX_H

typedef struct	s_img {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}				t_img;

int				offset(int y, int x, t_img *img);
unsigned int	*img_pixel_get(t_img *img, int y, int x);
void			img_pixel_put(t_img *img, int y, int x, unsigned int color);
unsigned int	gamma_color(unsigned int color);

#endif
