#ifndef ADDERS_P_H
# define ADDERS_P_H
# include "types.h"

char		**btexs_new(void);
int			add_conf(t_vars *vars, t_config *conf, t_line line);
int			add_p_r(t_vars *vars, t_config *conf, t_lines sline);
int			add_p_s(t_config *conf, t_lines lines);
int			add_p_f(t_config *conf, t_lines lines);
int			add_p_c(t_config *conf, t_lines lines);
int			add_p_l(t_config *conf, t_line line);
void		add_p_side(t_config *conf, t_lines lines, enum e_param param);
#endif
