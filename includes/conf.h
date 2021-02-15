#ifndef CONF_H
# define CONF_H

#include "parse.h"

enum e_param	get_param(t_line line);
int				add_conf_1(t_config *conf, t_lines lines, enum e_param param);
int				add_conf(t_config *conf, t_line line);
void			conf_init(t_config *conf);

#endif