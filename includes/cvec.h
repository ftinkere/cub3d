
#ifndef CVEC_H
#define CVEC_H

typedef struct	s_cveci {
	int		*arr;
	size_t	siz;
	size_t	cap;
}				t_cveci;

typedef struct	s_cvec {
	void	**arr;
	int		siz;
	int		cap;
}				t_cvec;

t_cvec	cvec_new();
t_cveci	cveci_new();
t_cvec	*cvec_grow(t_cvec *vec);
void	*cvec_push(t_cvec *vec, void *e);
t_cveci	*cveci_grow(t_cveci *vec);
int		cveci_push(t_cveci *vec, int e);
int		cvec_clear(t_cvec *vec);
int		cvec_free_all(t_cvec *vec);

#endif
