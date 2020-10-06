/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 00:16:58 by mbari             #+#    #+#             */
/*   Updated: 2019/12/28 13:24:04 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_point_star(va_list arg, t_print *val)
{
	int		zeros;
	int		size;
	t_args	value;

	if (val->type == '%')
		return (ft_putchar('%', val));
	zeros = va_arg(arg, int);
	value = ft_arg(arg, val);
	size = ft_value_len(&value, val);
	if (value.number < 0)
	{
		ft_putchar('-', val);
		value.number *= -1;
		size--;
	}
	if (value.number == 0 && zeros == 0)
		return ;
	if (val->type == 's')
		return (ft_print_string(zeros, value.string, val));
	ft_addespace(zeros - size, '0', val);
	ft_print_arg(&value, val);
}

void	ft_star_point(va_list arg, t_print *val)
{
	int		espace;
	int		size;
	t_args	value;

	espace = va_arg(arg, int);
	value = ft_arg(arg, val);
	size = ft_value_len(&value, val);
	if (val->type == 'p')
		return (ft_with_zeros_p(espace, ' ', value.string, val));
	if (val->type == 's')
	{
		if (espace < 0)
			espace *= -1;
		ft_addespace(espace, ' ', val);
		return ;
	}
	else
		ft_addespace(espace - size, ' ', val);
	ft_print_arg(&value, val);
	if (espace < 0)
		ft_addespace((-espace) - size, ' ', val);
}

void	ft_double_star(va_list arg, t_print *val)
{
	int		zeros;
	int		espace;
	int		size;
	t_args	value;

	espace = va_arg(arg, int);
	if (val->type == '%')
		return (ft_print_spercent(espace, val));
	if (val->left == 2 && espace > 0)
		espace *= -1;
	zeros = va_arg(arg, int);
	value = ft_arg(arg, val);
	size = ft_value_len(&value, val);
	if (value.number < 0 && val->type != 'u')
		return (ft_double_star_neg(espace, zeros, &value, val));
	(zeros <= 0) ? (zeros = size) : (zeros);
	if (val->type == 's')
		return (ft_double_str(value.string, espace, zeros, val));
	ft_addespace(espace - zeros, ' ', val);
	ft_addespace(zeros - size, '0', val);
	if (value.number == 0 && zeros == 0)
		return ;
	ft_print_arg(&value, val);
	ft_check_espace(espace, zeros, val);
}

void	ft_double_star_neg(int espace, int zeros, t_args *value, t_print *val)
{
	int		size;

	size = ft_value_len(value, val);
	if (zeros > 0)
		val->szero = ' ';
	zeros++;
	(zeros < size) ? (zeros = size) : (zeros);
	if (val->szero == '0' && zeros == size)
	{
		ft_putchar('-', val);
		ft_addespace(espace - zeros, val->szero, val);
	}
	else
	{
		ft_addespace(espace - zeros, val->szero, val);
		ft_putchar('-', val);
	}
	ft_addespace(zeros - size, '0', val);
	ft_putnbr(-value->number, val);
	if (espace < 0)
		ft_addespace((-espace) - zeros, ' ', val);
}

void	ft_double_str(char *str, int espace, int zeros, t_print *val)
{
	int		size;
	int		print;

	size = ft_strlen(str);
	if (zeros > size)
		print = size;
	else
		print = zeros;
	if (str == NULL)
		str = "(null)";
	if (str[0] == '\0')
		ft_addespace(espace, val->szero, val);
	else
		ft_addespace(espace - print, val->szero, val);
	ft_print_string(print, str, val);
	if (espace < 0)
		ft_addespace((-espace) - zeros, ' ', val);
}
