#include <raycast.h>
#include <libft.h>
#include <math.h>

void	add_sprite(t_caster *caster, t_vars *vars, t_ipoint pos, double ray)
{
	t_sprite	*sprt;
	t_point		tmp;
	t_caster	h;

	sprt = ft_calloc(1, sizeof(t_sprite));
	tmp.x = pos.j + 0.5;
	tmp.y = pos.i + 0.5;
	h.p = atan2((tmp.y - vars->pl.cord.y), (tmp.x - vars->pl.cord.x));
	h.k = tan(h.p + M_PI_2);
	h.m = tmp.y - tmp.x * h.k;
	if (fabs(h.p - M_PI) < 0.001 || fabs(h.p) < 0.01)
		sprt->cross.x = tmp.x;
	else
		sprt->cross.x = (h.m - caster->m) / (caster->k - h.k);
	if (!(fabs(h.p) < 0.01 || fabs(h.p - M_PI) < 0.01))
		sprt->cross.y = h.k * sprt->cross.x + h.m;
	else
		sprt->cross.y = caster->k * sprt->cross.x + caster->m;
	sprt->texp = dist_ab(tmp, sprt->cross) * sign(anrm(ray - h.p)) + 0.5;
	if (sprt->texp <= 0 || sprt->texp >= 1)
		return (free(sprt));
	sprt->dist = dist_ab(tmp, vars->pl.cord) * cos(vars->pl.angle - ray);
	sprt->tile = &vars->conf->map.tiles[pos.i * vars->conf->map.w + pos.j];
	cvec_push(&vars->sprites, sprt);
}
