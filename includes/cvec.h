#ifndef CVEC_H
# define CVEC_H

typedef struct s_cveci {
	int		*arr;
	int		siz;
	int		cap;
}	t_cveci;

typedef struct s_cvec {
	void	**arr;
	int		siz;
	int		cap;
}	t_cvec;

t_cvec	cvec_new(void);
t_cvec	*cvec_grow(t_cvec *vec);
void	*cvec_push(t_cvec *vec, void *e);
void	cvec_clear(t_cvec *vec);
void	cvec_free_all(t_cvec *vec);

#endif
