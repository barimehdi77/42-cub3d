/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whith_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 05:45:33 by mbari             #+#    #+#             */
/*   Updated: 2019/12/28 13:25:18 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_left(va_list arg, char *s, t_print *val)
{
	int		espace;
	int		size;
	t_args	valofarg;

	valofarg = ft_arg(arg, val);
	while (*s == '-')
		s++;
	espace = ft_atoi(s);
	size = ft_value_len(&valofarg, val);
	if (val->type == 'p')
	{
		ft_putstr("0x", val);
		ft_print_arg(&valofarg, val);
		ft_addespace(espace - size - 2, ' ', val);
	}
	else
	{
		ft_print_arg(&valofarg, val);
		ft_addespace(espace - size, ' ', val);
	}
}

void	ft_with_zeros(va_list arg, char *s, t_print *val, char type)
{
	int		espace;
	int		size;
	t_args	valofarg;

	valofarg = ft_arg(arg, val);
	espace = ft_atoi(s);
	size = ft_value_len(&valofarg, val);
	if (val->type == 'd' || val->type == 'i' || val->type == 'u')
		return (ft_negative_number(valofarg.number, espace, val, type));
	else if (val->type == 'p')
		return (ft_with_zeros_p(espace, type, valofarg.string, val));
	else if (val->type == 's' && val->point == NUMBER_POINT)
		return (ft_with_string(s, type, &valofarg, val));
	else
		ft_addespace(espace - size, type, val);
	ft_print_arg(&valofarg, val);
	if (espace < 0)
		ft_addespace((-espace) - size, ' ', val);
}

void	ft_with_zeros_p(int espace, char type, char *s, t_print *val)
{
	int		size;

	size = ft_strlen(s);
	if ((s[0] == '0' && s[1] == '\0') &&
			(val->point == NUMBER_POINT || val->point == STAR_POINT))
	{
		size--;
		ft_addespace(espace - size - 2, type, val);
		ft_putstr("0x", val);
		return ;
	}
	ft_addespace(espace - size - 2, type, val);
	ft_putstr("0x", val);
	ft_putstr(s, val);
}

void	ft_with_string(char *s, char type, t_args *value, t_print *val)
{
	int		espace;
	char	*str;

	if (*s == '0')
		type = '0';
	espace = ft_atoi(s);
	str = value->string;
	ft_addespace(espace, type, val);
	if (espace < 0)
		ft_addespace(-espace, type, val);
	if (str == NULL || str[0] == '\0')
		return ;
}

void	ft_with_point(va_list arg, char *s, t_print *val, char type)
{
	int			espace;
	int			size;
	t_args		valofarg;

	valofarg = ft_arg(arg, val);
	if (*s == '-')
		s++;
	espace = ft_atoi(s + 1);
	size = ft_value_len(&valofarg, val);
	if (val->type != '%')
	{
		if (val->type == 'd' || val->type == 'i' || val->type == 'u')
			return (ft_negative_number(valofarg.number, espace, val, type));
		else if (val->type == 'p')
		{
			ft_addespace(espace - size - 2, type, val);
			ft_putstr("0x", val);
		}
		else if (val->type == 's')
			return (ft_print_string(espace, valofarg.string, val));
		ft_addespace(espace - size, type, val);
	}
	if (espace == 0 && valofarg.string[0] == '0' && valofarg.string[1] == '\0')
		return ;
	ft_print_arg(&valofarg, val);
}
