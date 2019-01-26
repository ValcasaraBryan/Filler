/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:10:24 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/07 18:19:08 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRINTF_H
# define _PRINTF_H

# include <stdarg.h>
# include <wchar.h>

typedef struct		s_flag
{
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				l_maj;
	int				hash;
	int				plus;
	int				minus;
	int				zero;
	int				space;
	int				size;
	int				prec;
	long int		re;
}					t_flag;

typedef struct		s_float
{
	short			sign;
	long long int	stock;
	short			point;
}					t_float;

char				*ft_float(t_flag flag, long double flt);
int					ft_len(char *str, t_flag flag, char c);
void				ft_choose(char *str, t_flag *flag, char c);
void				ft_print_dif(char *str, t_flag *flag, int *len, char c);
void				ft_print_csp(char *str, t_flag *flag, int *len, char c);
void				ft_print_oxxb(char *str, t_flag *flag, char c, int *len);
void				ft_print_u(char *str, t_flag *flag, int *len);
void				ft_minus(t_flag *flag, int *len);
void				ft_hash(char c, t_flag *flag);
void				ft_zero(char *str, t_flag *flag, int *len, char c);
void				ft_space(int *len, t_flag *flag);
void				ft_field(t_flag *flag, int *len);
char				*ft_manager(t_flag flag, va_list ap, char c);
char				*ft_unbrtoa(unsigned long long int nbr);
char				*ft_nbrtoa(long long int nbr);
char				*ft_conv_base(unsigned long long nbr, int base, char id);
char				*ft_conv_adrtohex(va_list ap);
int					ft_parse(char **str, t_flag *flag);
int					find_conv(char **str, t_flag *flag);
void				find_modifier(char **str, t_flag *flag);
void				find_flag(char **str, t_flag *flag);
int					find_precision(char **str);
void				ft_precision(char *str, t_flag *flag, char c);
int					is_sp(char c);
int					is_cdiouxxb(char c);
int					is_pf(char c);
int					is_modifier(char c);
int					is_flag(char c);
int					ft_match(char **str, char c);
int					ft_printf(char *arg0, ...);
char				*ft_char(va_list ap);
char				*ft_char2(char c);
char				*ft_str(va_list ap);
char				ft_shortshort(va_list ap);
short				ft_short(va_list ap);
int					ft_putchar_p(wchar_t ch, t_flag *flag);
void				ft_putstr_p(char const *s, t_flag *flag);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
#endif
