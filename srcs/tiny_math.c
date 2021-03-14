#include <math.h>

double	sign(double a)
{
	if (a < 0)
		return (-1);
	else
		return (1);
}

double	anrm(double ang)
{
	while (ang > M_PI)
		ang = (ang - M_PI) * -1;
	while (ang < -M_PI)
		ang = (ang + M_PI) * -1;
	return (ang);
}

double	normilize2(double ang)
{
	while (ang > 2 * M_PI)
		ang = ang - 2 * M_PI;
	while (ang < 0)
		ang = ang + 2 * M_PI;
	return (ang);
}
