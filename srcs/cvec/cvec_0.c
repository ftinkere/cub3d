#include <stdlib.h>
#include "libft.h"
#include "cvec.h"

t_cvec	cvec_new()
{
	t_cvec ret;
	int i;

	ret.arr = ft_calloc(16, sizeof(void*));
	ret.siz = 0;
	ret.cap = 16;
	return (ret);
}

t_cveci	cveci_new()
{
	t_cveci ret;
	int i;

	ret.arr = malloc(16 * sizeof(int));
	i = 0;
	while (i < 16)
	{
		ret.arr[i] = 0;
		i++;
	}
	ret.siz = 0;
	ret.cap = 16;
	return (ret);
}

t_cvec	*cvec_grow(t_cvec *vec)
{
	void *new_ptr;

	new_ptr = ft_calloc(vec->cap * 2, sizeof(void*));
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, vec->arr, vec->cap * sizeof(void*));
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

t_cveci	*cveci_grow(t_cveci *vec)
{
	int *new_ptr;

	new_ptr = ft_calloc(vec->cap * 2, sizeof(int));
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, vec->arr, vec->cap * sizeof(int));
	free(vec->arr);
	vec->arr = new_ptr;
	vec->cap = vec->cap * 2;
	return (vec);
}

int		cveci_push(t_cveci *vec, int e)
{
	if (vec->siz == vec->cap)
		cveci_grow(vec);
	vec->arr[vec->siz] = e;
	vec->siz++;
	return (e);
}