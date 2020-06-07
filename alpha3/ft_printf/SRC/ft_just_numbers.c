/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_just_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 03:29:24 by mbari             #+#    #+#             */
/*   Updated: 2019/12/28 13:24:31 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_double_numbers(va_list arg, char *s, t_print *val)
{
	int		espace;
	int		zeros;
	int		skip;
	t_args	value;

	espace = ft_atoi(s);
	skip = ft_skip_number(s);
	zeros = ft_atoi(s + skip + 1);
	value = ft_arg(arg, val);
	if (value.number < 0 && val->type != 'u')
		return (ft_double_number_neg(espace, zeros, &value, val));
	if (val->type == '%')
		return (ft_print_percent(s, espace, val));
	else if (value.number == 0 && zeros == 0)
	{
		(espace < 0) ? (espace *= -1) : (espace *= 1);
		return (ft_addespace(espace, ' ', val));
	}
	else if (val->type == 's')
		return (ft_double_number_s(espace, zeros, &value, val));
	skip = ft_value_len(&value, val);
	(skip > zeros) ? (zeros = skip) : (zeros);
	ft_addespace(espace - zeros, ' ', val);
	ft_double_numbers_rest((zeros - skip), &value, val);
	ft_check_espace(espace, zeros, val);
}

void	ft_double_numbers_rest(int zeros, t_args *value, t_print *val)
{
	if (val->type == '%')
		ft_addespace(zeros, ' ', val);
	else
		ft_addespace(zeros, '0', val);
	if (zeros == 0 && value->string[0] == '0' && value->string[1] == '\0')
		ft_putchar(' ', val);
	else
		ft_print_arg(value, val);
}

void	ft_double_number_neg(int espace, int zeros, t_args *value, t_print *val)
{
	int		size;

	size = ft_value_len(value, val);
	if (val->type == 'd' || val->type == 'i')
	{
		zeros++;
		(zeros < size) ? (zeros = size) : (zeros);
		ft_addespace(espace - zeros, ' ', val);
		ft_putchar('-', val);
		ft_addespace(zeros - size, '0', val);
		ft_putnbr(-value->number, val);
	}
	if (espace < 0)
		ft_addespace((-espace) - zeros, ' ', val);
}

void	ft_double_number_s(int espace, int zeros,
			t_args *valofarg, t_print *val)
{
	int		size;
	char	*str;

	str = valofarg->string;
	size = ft_strlen(str);
	if (str == NULL)
	{
		str = "(null)";
		size = ft_strlen(str);
		if (espace < zeros)
			ft_addespace(espace - size, val->szero, val);
		ft_addespace(espace - zeros, val->szero, val);
		ft_print_string(zeros, str, val);
	}
	else if (str[0] == '\0')
		ft_addespace(espace, val->szero, val);
	else
	{
		(size < zeros) ? (zeros = size) : (zeros);
		ft_addespace(espace - zeros, val->szero, val);
		ft_print_string(zeros, str, val);
	}
	(zeros > size) ? (zeros = size) : (zeros);
	if (espace < 0)
		ft_addespace((-espace) - zeros, val->szero, val);
}

t_args	ft_arg(va_list arg, t_print *val)
{
	t_args	ret;

	ft_initialized(&ret);
	ret.int_str = CHAR;
	if (val->type == 'c')
		ret.number = va_arg(arg, int);
	else if (val->type == 's')
		ret.string = va_arg(arg, char *);
	else if (val->type == 'd' || val->type == 'i' || val->type == 'u')
		ret.number = va_arg(arg, int);
	else if (val->type == 'x' || val->type == 'X')
		ret.string = ft_decimaltohex(va_arg(arg, int), val->type);
	else if (val->type == 'p')
		ret.string = ft_decimaltohex((unsigned long)va_arg(arg, void *),
			val->type);
	else if (val->type == '%')
		ret.number = '%';
	if (val->type == 's' || val->type == 'x' ||
			val->type == 'X' || val->type == 'p')
		ret.int_str = STRING;
	else if (val->type == 'd' || val->type == 'i' || val->type == 'u')
		ret.int_str = NUMBER;
	(ret.int_str == STRING) ? (ret.number = 1) : (ret.number);
	(ret.int_str == NUMBER) ? (ret.string = "NO") : (ret.string);
	return (ret);
}
