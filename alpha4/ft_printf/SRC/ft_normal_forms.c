/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal_forms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:07:53 by mbari             #+#    #+#             */
/*   Updated: 2019/12/28 13:24:38 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_normal_forms(va_list arg, const char *s, t_print *val)
{
	ft_flags_count(s, val);
	if (*s == '%')
		ft_putchar('%', val);
	else if (*s == 'c')
		ft_putchar(va_arg(arg, int), val);
	else if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(arg, int), val);
	else if (*s == 'u')
		ft_putunsignednbr(va_arg(arg, unsigned int), val);
	else if (*s == 's')
		ft_putstr(va_arg(arg, char *), val);
	else if (*s == 'p')
		ft_putstr(ft_pointer(va_arg(arg, void *), val), val);
	else if (*s == 'X')
		ft_print_hex((char *)(s - 1), va_arg(arg, int), val);
	else if (*s == 'x')
		ft_print_hex((char *)(s - 1), va_arg(arg, int), val);
}
