#ifndef CUB3D_UTILS_H
# define CUB3D_UTILS_H
# include "types.h"

void		free_split(t_lines lines);
t_lines_v	read_file(t_file file);
void		errex(int e, const char *message);

#endif
