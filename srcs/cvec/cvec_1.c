#include <stdlib.h>
#include <parse.h>
#include <cub3d_utils.h>
#include "libft.h"
#include "cvec.h"

int		cveci_push(t_cveci *vec, int e)
{
	if (vec->siz == vec->cap)
		cveci_grow(vec);
	vec->arr[vec->siz] = e;
	vec->siz++;
	return (e);
}
