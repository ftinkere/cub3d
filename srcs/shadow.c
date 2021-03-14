#include <math.h>
#include <intmlx.h>

t_color	shadow_dist(t_color color, double dist)
{
	double	a;
	double	r;
	double	g;
	double	b;

	a = ((color >> 24) & 0xFF);
	r = ((color >> 16) & 0xFF) * pow(0.8, dist);
	g = ((color >> 8) & 0xFF) * pow(0.8, dist);
	b = (color & 0xFF) * pow(0.8, dist);
	return (color_rgba((int)r, (int)g, (int)b, (int)a));
}
