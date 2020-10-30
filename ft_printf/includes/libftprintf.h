/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 01:17:40 by mbari             #+#    #+#             */
/*   Updated: 2020/10/17 13:18:56 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

typedef	struct	s_print
{
	int			count;
	int			star;
	int			point;
	int			whith;
	int			zeros;
	int			left;
	char		type;
	char		szero;
}				t_print;

typedef	struct	s_arg
{
	char		*string;
	long long	number;
	int			int_str;
}				t_args;

# define ON 1
# define OFF 0
# define STAR_NUMBER 2
# define NUMBER_STAR 3
# define JUST_NUMBERS 4
# define STAR_POINT 5
# define NUMBER_POINT 6
# define POINT_STAR 7
# define POINT_NUMBER 8

# define STRING 1
# define NUMBER 0
# define CHAR 2

int				ft_printf(const char *s, ...);
void			ft_select_flag(va_list arg, const char *s, t_print *val);
void			ft_which_point(char *s, t_print *val);
void			ft_print_point(va_list arg, char *s, t_print *val);
void			ft_just_point(va_list arg, t_print *val);
void			ft_normal_forms(va_list arg, const char *s, t_print *val);
void			ft_number_star(va_list arg, char *s, t_print *val);
void			ft_flags_count(const char *s, t_print *val);
char			ft_type(const char *s);
void			ft_print_arg(t_args *valofarg, t_print *val);
int				ft_value_len(t_args *arg, t_print *val);
void			ft_double_numbers(va_list arg, char *s, t_print *val);
void			ft_double_number_neg(int espace, int zeros, t_args *value,
					t_print *val);
void			ft_double_number_s(int espace, int zeros,
					t_args *valofarg, t_print *val);
int				ft_skip_number(char *s);
int				ft_skip(char *s);
void			ft_set_val(t_print *val);
void			ft_flags(va_list arg, const char *s, t_print *val);
void			ft_initialized(t_args *arg);
t_args			ft_arg(va_list arg, t_print *val);
void			ft_addespace(int size, char c, t_print *val);
void			ft_point_star(va_list arg, t_print *val);
void			ft_star_point(va_list arg, t_print *val);
void			ft_double_star(va_list arg, t_print *val);
void			ft_double_str(char *str, int espace, int zeros, t_print *val);
char			*ft_decimaltohex(unsigned long dic, char type);
char			*ft_pointer(void *p, t_print *val);
void			ft_print_hex(const char *s, unsigned int dic, t_print *val);
void			ft_print_string(int size, char *str, t_print *val);
void			ft_star_string(int espace, int size, char *str, t_print *val);
void			ft_just_star(const char *s, va_list arg, t_print *val);
void			ft_left(va_list arg, char *s, t_print *val);
void			ft_with_zeros(va_list arg, char *s, t_print *val, char type);
void			ft_with_string(char *s, char type, t_args *value, t_print *val);
void			ft_negative_number(int value, int espace,
					t_print *val, char type);
void			ft_with_point(va_list arg, char *s, t_print *val, char type);
void			ft_star_number(va_list arg, char *s, t_print *val);
void			ft_neg_number(long long value, int espace,
					int zeros, t_print *val);
void			ft_rest(int espace, char type, int value, t_print *val);
void			ft_iszero_left(char *s, t_print *val);
void			ft_print_percent(char *s, int espace, t_print *val);
void			ft_print_spercent(int espace, t_print *val);
void			ft_double_star_neg(int espace, int zeros,
					t_args *value, t_print *val);
void			ft_with_zeros_p(int espace, char type, char *s, t_print *val);
void			ft_check_espace(int espace, int zeros, t_print *val);
int				ft_getflag(int i, const char *s);
void			ft_double_numbers_rest(int zeros, t_args *value, t_print *val);
void			ft_star_number_rest(int espace, int zeros,
					t_args *value, t_print *val);
void			ft_neg_number_rest(int espace, int zeros,
					t_args *value, t_print *val);
void			ft_negative_number_rest(int size, int number,
					char type, t_print *val);

#endif
