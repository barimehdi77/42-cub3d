/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 05:15:34 by mbari             #+#    #+#             */
/*   Updated: 2019/12/01 05:15:36 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsignednbr(unsigned int n, t_print *val)
{
	unsigned int	size;
	unsigned int	temp;

	size = 1;
	temp = n;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = n;
	while (size)
	{
		ft_putchar((temp / size) + '0', val);
		temp %= size;
		size /= 10;
	}
}
