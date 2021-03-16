/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:44:39 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/20 17:44:41 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdarg.h>
# include <stddef.h>

/*
** vld		валидность
** sp		спецификатор "d i u o x X f g e c s p % n"
** sb		субспецификатор "l ll h hh"
** f_*		указан ли флаг
**   mn		'-'
**   pl		'+'
**   sp		' '
**   oc		'#'
**   zr		'0'
** w		указанная ширина
** p		указанная точность
*/
typedef struct s_spec
{
	char	sp;
	char	sb;
	char	f_mn;
	char	f_pl;
	char	f_sp;
	char	f_oc;
	char	f_zr;
	int		w;
	int		p;
}	t_spec;

typedef unsigned long long	t_u64;
typedef long long			t_i64;

/*
** PRINTERS
*/

int							ft_printf_(int sim, const char *format, ...);
int							print_width_(int sim, t_spec *spec, int be_pr);
int							print_unsign_base_(int sim, t_spec *spec, t_u64 d);
int							print_d_(int sim, t_spec *s, long long d);
int							print_u_(int sim, t_spec *s, unsigned long long d);
int							print_width_with_(int sim, char c, int be_pr);
int							print_c_(int sim, t_spec *spec, int c);
int							print_s_(int sim, t_spec *spec, const char *s);
int							print_infnan_(int sim, t_spec *spec, long double e);
int							print_route(int sim, t_spec *s, t_u64 d);
int							print_e_(int sim, t_spec *spec, long double e);
int							print_e_sub_(int sim, t_spec *s, long double e);
int							print_f_(int sim, t_spec *s, long double e);
int							print_f_sub_(int sim, t_spec *s, long double e);
int							print_g_(int sim, t_spec *spec, long double e);

/*
** READERS
*/
long long					read_var_int(t_spec *spec, va_list p_args);
unsigned long long			read_var_u(t_spec *spec, va_list p_args);
int							read_var_char(t_spec *spec, va_list p_args);
double						read_var_double(t_spec *spec, va_list p_args);
char						*read_var_s(t_spec *spec, va_list p_args);

/*
** ISERS
*/
int							is_specc(char c);
int							is_flag(char c);
int							is_infnan(double e);

/*
** BASE WRITERS
*/
int							print_char_(int sim, int c);
int							print_str_(int sim, const char *s, int siz);
int							pr_2str_(int sim, const char *st, const char *end);

/*
** SPEC
*/
t_spec						parse_spec(const char **fmt);
t_spec						def_spec(void);

/*
** UTILS
*/
const char					*get_block_end(const char *str);
int							prc_i(t_spec *spec, long long d);
int							prc_u(t_spec *spec, unsigned long long d);
int							cnt_f(t_spec *spec, long double e);
int							cnt_u(t_spec *spec, unsigned long long d);
int							cnt_d(t_spec *spec, long long d);
int							cnt_e(t_spec *spec, long double e);
int							cnt_g_prec(t_spec *spec, long double e);

/*
** MATH
*/
t_i64						mabs_i(t_i64 x);
long double					mabs_d(long double x);
long double					mpow_d(t_i64 x, t_i64 p);
t_i64						mlog10(long double x);
t_i64						mfloor(long double x);
t_i64						mround_even(long double x);
unsigned long long			sign_d(double x);
t_u64						mroundu_even(long double x);

/*
** LIBFTS
*/
//size_t						ft_strlen(const char *s);
//void						*ft_memchr(const void *src, int c, size_t n);
//char						*ft_strchr(const char *src, int c);
//void						*ft_memcpy(void *dest, const void *src, size_t n);
//int							ft_isdigit(int c);
//int							ft_atoi(const char *s);

#endif
