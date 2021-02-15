#ifndef ADDERS_P_H
# define ADDERS_P_H

t_btexs		*btexs_new();
int			add_p_r(t_config *conf, t_lines sline);
int			add_p_no(t_config *conf, t_lines lines);
int			add_p_so(t_config *conf, t_lines lines);
int			add_p_we(t_config *conf, t_lines lines);
int			add_p_ea(t_config *conf, t_lines lines);
int			add_p_up(t_config *conf, t_lines lines);
int			add_p_s(t_config *conf, t_lines lines);
int			add_p_f(t_config *conf, t_lines lines);
int			add_p_c(t_config *conf, t_lines lines);
int			add_p_l(t_config *conf, t_line line);

#endif
