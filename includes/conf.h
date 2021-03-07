#ifndef CONF_H
# define CONF_H
# include "types.h"

enum e_param	get_param(t_line line);
void			conf_init(t_config *conf);
t_keybuf		keybuff_new(void);

#endif