//
// Created by ftinkere on 14.02.2021.
//

#ifndef MAP_VALIDATES_H
#define MAP_VALIDATES_H

int		validate_raw_map(t_lines_v *lines, int i);
int		validate_circ(t_map *map);
int		find_spawn(t_map *map, size_t *i, size_t *j);

#endif
