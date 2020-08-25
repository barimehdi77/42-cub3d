/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:53:06 by mbari             #+#    #+#             */
/*   Updated: 2019/10/23 19:00:44 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long n, t_print *val)
{
	unsigned int a;

	a = n;
	if (n < 0)
	{
		ft_putchar('-', val);
		a = -n;
	}
	if (a > 9)
	{
		ft_putnbr((a / 10), val);
		ft_putchar((a % 10) + '0', val);
	}
	else
		ft_putchar(a + '0', val);
}
