#ifndef PARSE_H
# define PARSE_H
# include "types.h"

t_config	parse_cub(t_vars *vars, t_path conf_path);
int			validate_circ(t_map *map);
t_lines_v	read_file(t_file file);
int			parse_map(t_map *map, t_lines_v *lines, int i);

#endif
