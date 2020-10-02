/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_and_star.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:07:21 by mbari             #+#    #+#             */
/*   Updated: 2019/12/28 13:24:45 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_number_star(va_list arg, char *s, t_print *val)
{
	int		espace;
	int		zeros;
	int		size;
	t_args	value;

	zeros = va_arg(arg, int);
	espace = ft_atoi(s);
	value = ft_arg(arg, val);
	size = ft_value_len(&value, val);
	if (value.number < 0)
		return (ft_neg_number(value.number, espace, zeros, val));
	if (val->type == '%')
		return (ft_print_percent(s, espace, val));
	zeros = (zeros < 0) ? size : zeros;
	if (val->type == 's')
		return (ft_star_string(espace, zeros, value.string, val));
	if (zeros == size)
		ft_addespace((espace - zeros), val->szero, val);
	else
		ft_addespace((espace - zeros), ' ', val);
	if (value.number == 0 && zeros == 0)
		return ;
	ft_addespace((zeros - size), '0', val);
	ft_print_arg(&value, val);
	ft_check_espace(espace, zeros, val);
}

void	ft_check_espace(int espace, int zeros, t_print *val)
{
	if (espace < 0)
		ft_addespace(((-espace) - zeros), ' ', val);
}

void	ft_print_percent(char *s, int espace, t_print *val)
{
	if (*s == '-' && espace > 0)
		espace *= -1;
	if (espace > 0 && *s == '0')
		ft_addespace(espace - 1, '0', val);
	else if (espace < 0)
	{
		ft_putchar('%', val);
		ft_addespace((-espace) - 1, ' ', val);
		return ;
	}
	else
		ft_addespace(espace - 1, ' ', val);
	ft_putchar('%', val);
	if (espace < 0)
		ft_addespace((-espace) - 1, ' ', val);
}

void	ft_print_spercent(int espace, t_print *val)
{
	if (val->left == 2 && espace > 0)
		espace *= -1;
	if (espace > 0 && val->szero == '0')
		ft_addespace(espace - 1, '0', val);
	else if (espace < 0)
	{
		ft_putchar('%', val);
		ft_addespace((-espace) - 1, ' ', val);
		return ;
	}
	else
		ft_addespace(espace - 1, ' ', val);
	ft_putchar('%', val);
	if (espace < 0)
		ft_addespace((-espace) - 1, ' ', val);
}
