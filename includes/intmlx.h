#ifndef INTMLX_H
# define INTMLX_H
# include "types.h"

int				offset(int y, int x, t_img *img);
t_color			*img_pixel_get(t_img *img, int y, int x);
void			img_pixel_put(t_img *img, int y, int x, unsigned int color);
t_color			gcolor(unsigned int color);
t_color			gcolor_rgba(t_byte r, t_byte g, t_byte b, t_byte a);
t_color			gcolor_norm(double r, double g, double b, double a);
t_color			color_rgba(t_byte r, t_byte g, t_byte b, t_byte a);
t_color			color_norm(double r, double g, double b, double a);

#endif
