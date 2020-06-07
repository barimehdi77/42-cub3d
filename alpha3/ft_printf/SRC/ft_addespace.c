/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addespace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 00:16:50 by mbari             #+#    #+#             */
/*   Updated: 2019/12/28 13:23:58 by mbari            ###   ########.fr       */
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
