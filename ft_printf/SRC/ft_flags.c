/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:54:06 by mbari             #+#    #+#             */
/*   Updated: 2019/12/28 13:24:26 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_select_flag(va_list arg, const char *s, t_print *val)
{
	if (val->point == ON)
	{
		ft_which_point((char *)s, val);
		ft_print_point(arg, (char *)s, val);
	}
	else if (val->star == ON && val->point == OFF)
		ft_just_star(s, arg, val);
	else if (val->whith == ON && *s != '0' && val->left == OFF)
		ft_with_zeros(arg, (char *)s, val, ' ');
	else if (val->zeros == ON && *s == '0')
		ft_with_zeros(arg, (char *)s, val, '0');
	else if (val->left == ON)
		ft_left(arg, (char *)s, val);
}

void	ft_which_point(char *s, t_print *val)
{
	while (*s != val->type)
	{
		if (*s == '.')
		{
			if (*(s - 1) == '*' && ft_isdigit(*(s + 1), val))
				val->point = STAR_NUMBER;
			else if (ft_isdigit(*(s - 1), val) && *(s + 1) == '*')
				val->point = NUMBER_STAR;
			else if (ft_isdigit(*(s - 1), val) && ft_isdigit(*(s + 1), val))
				val->point = JUST_NUMBERS;
			else if (*(s - 1) == '*' && *(s + 1) == val->type)
				val->point = STAR_POINT;
			else if (*(s + 1) == '*' && *(s - 1) == '%')
				val->point = POINT_STAR;
			else if (ft_isdigit(*(s - 1), val) && *(s + 1) == val->type)
				val->point = NUMBER_POINT;
			else if (ft_isdigit(*(s + 1), val) && *(s - 1) == '%')
				val->point = POINT_NUMBER;
			else if (ft_isdigit(*(s + 1), val) && *(s - 1) == '-')
				val->point = POINT_NUMBER;
		}
		s++;
	}
}

void	ft_print_point(va_list arg, char *s, t_print *val)
{
	ft_iszero_left(s, val);
	if (val->point == ON && val->star != 2)
		ft_just_point(arg, val);
	else if (val->star == 2)
		ft_double_star(arg, val);
	else if (val->point == STAR_NUMBER)
		ft_star_number(arg, s, val);
	else if (val->point == NUMBER_STAR)
		ft_number_star(arg, s, val);
	else if (val->point == JUST_NUMBERS)
		ft_double_numbers(arg, s, val);
	else if (val->point == STAR_POINT)
		ft_star_point(arg, val);
	else if (val->point == NUMBER_POINT)
		ft_with_zeros(arg, s, val, ' ');
	else if (val->point == POINT_STAR)
		ft_point_star(arg, val);
	else if (val->point == POINT_NUMBER)
		ft_with_point(arg, s, val, '0');
}

void	ft_iszero_left(char *s, t_print *val)
{
	if (*s == '0')
		val->szero = '0';
	if (*s == '-')
		val->left = 2;
}

void	ft_just_point(va_list arg, t_print *val)
{
	t_args value;

	value = ft_arg(arg, val);
	if (val->type == 'p' && value.string[0] == '0' && value.string[1] == '\0')
		return (ft_putstr("0x", val));
	else if (val->type == 'p' && value.string[0] != '0' &&
					value.string[1] != '\0')
		ft_putstr("0x", val);
	if (val->type == 's')
		return ;
	if (value.int_str == NUMBER)
	{
		if (value.number == 0)
			return ;
	}
	else if (value.int_str == STRING)
	{
		if (value.string[0] == '0' && value.string[1] == '\0')
			return ;
	}
	ft_print_arg(&value, val);
}
