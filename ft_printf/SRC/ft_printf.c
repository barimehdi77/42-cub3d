/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 01:16:56 by mbari             #+#    #+#             */
/*   Updated: 2020/10/17 13:17:57 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

int		ft_value_len(t_args *arg, t_print *val)
{
	if (val->type == 'd' || val->type == 'i' || val->type == 'u')
	{
		if (val->type == 'u' && arg->number < 0)
			return (10);
		return (ft_strlen(ft_itoa(arg->number)));
	}
	else if (val->type == 's' || val->type == 'x' ||
				val->type == 'X' || val->type == 'p')
		return (ft_strlen(arg->string));
	else if (val->type == 'c' || val->type == '%')
		return (1);
	return (0);
}

void	ft_print_arg(t_args *valofarg, t_print *val)
{
	if (valofarg->int_str == NUMBER)
	{
		if (val->type == 'u')
			ft_putunsignednbr(valofarg->number, val);
		else
			ft_putnbr(valofarg->number, val);
	}
	else if (valofarg->int_str == STRING)
		ft_putstr(valofarg->string, val);
	else
		ft_putchar(valofarg->number, val);
}

char	ft_type(const char *s)
{
	int i;

	i = 0;
	while (*(s + i) != 'c' && *(s + i) != 's' && *(s + i) != '%'
		&& *(s + i) != 'd' && *(s + i) != 'i' && *(s + i) != 'u' &&
		*(s + i) != 'x' && *(s + i) != 'X' && *(s + i) != 'p')
		i++;
	return (*(s + i));
}

void	ft_flags_count(const char *s, t_print *val)
{
	int i;

	i = 0;
	val->type = ft_type(s);
	while (s[i] != val->type)
	{
		if (ft_isdigit(*(s + i), val))
			val->whith = ON;
		else if (*(s + i) == '-')
			val->left = ON;
		else if (*(s + i) == '0')
			val->zeros = ON;
		else if (*(s + i) == '*')
			val->star += ON;
		else if (*(s + i) == '.')
			val->point = ON;
		i++;
	}
}

int		ft_printf(const char *s, ...)
{
	t_print		val;
	int			i;
	va_list		arg;

	i = -1;
	va_start(arg, s);
	val.count = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			ft_set_val(&val);
			if (ft_getflag(i, s))
				ft_normal_forms(arg, (s + i), &val);
			else if (ft_isdigit(*(s + i), &val) || *(s + i) == '0' ||
						*(s + i) == '*' || *(s + i) == '*')
				ft_flags(arg, (s + i), &val);
			i += ft_skip((char *)(s + i));
		}
		else
			ft_putchar(s[i], &val);
	}
	va_end(arg);
	return (val.count);
}
