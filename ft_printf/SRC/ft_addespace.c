/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addespace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 00:16:50 by mbari             #+#    #+#             */
/*   Updated: 2020/10/17 13:19:02 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_addespace(int size, char c, t_print *val)
{
	if (size > 0)
	{
		while (size)
		{
			ft_putchar(c, val);
			size--;
		}
	}
}

void	ft_rest(int espace, char type, int value, t_print *val)
{
	int			size;

	size = ft_strlen(ft_itoa(value));
	if (val->type == 'u')
	{
		(value < 0) ? (size = 10) : (size);
		ft_addespace(espace - size, type, val);
		if (value == 0 && val->point == 6)
			ft_putchar(' ', val);
		else
			ft_putunsignednbr(value, val);
	}
	(espace < 0) ? (ft_addespace((-espace) - size, ' ', val)) : NULL;
}

int		ft_getflag(int i, const char *s)
{
	if (*(s + i) == 'c' || *(s + i) == 's' || *(s + i) == 'd'
					|| *(s + i) == 'i' || *(s + i) == 'u' || *(s + i) == 'x'
							|| *(s + i) == 'X' || *(s + i) == 'p')
		return (1);
	return (0);
}
