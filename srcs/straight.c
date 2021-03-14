#include <raycast.h>
#include <math.h>

double	straight_x(t_caster *caster, double y)
{
	return ((y - caster->m) * caster->p);
}

double	straight_y(t_caster *caster, double x)
{
	return (caster->k * x + caster->m);
}

double	angle_round(double	cord, int to)
{
	if (to == 0)
		return (cord);
	else if (to < 0)
		return (floor(cord));
	else if (to > 0)
		return (ceil(cord));
	else
		return (0);
}

double	dist_ab(t_point a, t_point b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}

double	dist_abr(t_point a, t_point b, double ray)
{
	if (fabs(a.x - b.x) < 0.0001)
		return (fabs(a.y - b.y));
	else if (fabs(a.y - b.y) < 0.0001)
		return (fabs(a.x - b.x));
	return (fabs((a.x - b.x) / cos(ray)));
}
