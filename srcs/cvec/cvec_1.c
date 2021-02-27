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

int		cvec_free_all(t_cvec *vec)
{
	size_t	i;

	i = 0;
	while (i < vec->siz)
		free(vec->arr[i++]);
	free(vec->arr);
}

int		cvec_clear(t_cvec *vec)
{
	size_t	i;

	i = 0;
	while (i < vec->siz)
		free(vec->arr[i++]);
	vec->siz = 0;
}

void	*cvec_last(t_cvec *cvec)
{

}