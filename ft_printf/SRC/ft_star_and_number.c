/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star_and_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:37:13 by mbari             #+#    #+#             */
/*   Updated: 2020/05/20 23:41:49 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_star_number(va_list arg, char *s, t_print *val)
{
	int		espace;
	int		zeros;
	int		size;
	t_args	value;

	espace = va_arg(arg, int);
	if (val->type == '%')
		return (ft_print_percent(s, espace, val));
	if (*s == '0' || *s == '-')
		s++;
	zeros = ft_atoi(s + 2);
	value = ft_arg(arg, val);
	if (val->left == 2 && espace > 0)
		espace *= -1;
	size = ft_value_len(&value, val);
	if (value.number < 0)
		return (ft_neg_number(value.number, espace, zeros, val));
	if (val->type == 's')
		return (ft_star_string(espace, zeros, value.string, val));
	if (val->type == '%')
		return (ft_print_percent(s, espace, val));
	ft_addespace((espace - zeros), ' ', val);
	if (value.number == 0 && zeros == 0)
		return ;
	ft_star_number_rest(espace, (zeros - size), &value, val);
}

void	ft_star_number_rest(int espace, int zeros, t_args *value, t_print *val)
{
	if (val->type == '%')
		ft_addespace(zeros, ' ', val);
	else
		ft_addespace(zeros, '0', val);
	ft_print_arg(value, val);
	ft_check_espace(espace, zeros, val);
}

void	ft_neg_number(long long value, int espace, int zeros, t_print *val)
{
	int		size;

	size = ft_strlen(ft_itoa(value));
	if (val->type == 'd' || val->type == 'i')
	{
		zeros++;
		zeros = (zeros < 0) ? size : zeros;
		if (zeros == size && val->szero == '0')
		{
			ft_putchar('-', val);
			ft_addespace((espace - zeros), val->szero, val);
		}
		else
		{
			ft_addespace((espace - zeros), ' ', val);
			ft_putchar('-', val);
		}
		value *= -1;
		ft_addespace((zeros - size), '0', val);
		ft_putnbr(value, val);
	}
}

void	ft_neg_number_rest(int espace, int zeros, t_args *value, t_print *val)
{
	int size;

	size = ft_value_len(value, val);
	if (val->type == 'u')
	{
		if (value->int_str < 0)
			size = 10;
		zeros = (zeros < 0) ? size : zeros;
		if (zeros == size)
			ft_addespace((espace - zeros), val->szero, val);
		else
			ft_addespace((espace - zeros), ' ', val);
		ft_addespace((zeros - size), '0', val);
		ft_putunsignednbr(value->number, val);
	}
	if (espace < 0)
		ft_addespace(((-espace) - zeros), ' ', val);
}

void	ft_negative_number(int value, int espace, t_print *val, char type)
{
	int				size;

	size = ft_strlen(ft_itoa(value));
	if (val->type == 'd' || val->type == 'i')
	{
		if (espace == 0 && value == 0)
			return ;
		if (value < 0 && type == '0')
		{
			ft_putchar('-', val);
			(val->point == POINT_NUMBER) ? (size--) : (size);
		}
		if (val->point == NUMBER_POINT && value == 0)
		{
			size = 0;
			if (espace == 0)
				ft_putchar(' ', val);
		}
		ft_addespace(espace - size, type, val);
		ft_negative_number_rest(size, value, type, val);
	}
	ft_rest(espace, type, value, val);
}
