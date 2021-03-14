#include <stdlib.h>
#include <cub3d_utils.h>
#include "libft.h"
#include "cvec.h"

t_cvec	cvec_new(void)
{
	t_cvec	ret;

	ret.arr = ft_calloc(16, sizeof(void *));
	if (ret.arr == NULL)
		errex(42, "Error allocated cvec");
	ret.siz = 0;
	ret.cap = 16;
	return (ret);
}

t_cvec	*cvec_grow(t_cvec *vec)
{
	void	*new_ptr;

	new_ptr = ft_calloc(vec->cap * 2, sizeof(void *));
	if (!new_ptr)
		errex(42, "Error reallocated cvec");
	ft_memcpy(new_ptr, vec->arr, vec->cap * sizeof(void *));
	free(vec->arr);
	vec->arr = new_ptr;
	vec->cap = vec->cap * 2;
	return (vec);
}

void	*cvec_push(t_cvec *vec, void *e)
{
	if (vec->siz == vec->cap)
		cvec_grow(vec);
	vec->arr[vec->siz] = e;
	vec->siz++;
	return (e);
}

void	cvec_free_all(t_cvec *vec)
{
	size_t	i;

	i = 0;
	while (i < vec->siz)
		free(vec->arr[i++]);
	free(vec->arr);
}

void	cvec_clear(t_cvec *vec)
{
	size_t	i;

	i = 0;
	while (i < vec->siz)
		free(vec->arr[i++]);
	vec->siz = 0;
}
