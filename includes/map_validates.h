#ifndef MAP_VALIDATES_H
# define MAP_VALIDATES_H
# include "types.h"

int		validate_raw_map(t_lines_v *lines, int i);
int		validate_circ(t_map *map);
int		find_spawn(t_map *map, int *i, int *j);

#endif
