/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:36:24 by mbari             #+#    #+#             */
/*   Updated: 2020/04/29 16:36:45 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *s)
{
	while (*s != '\0')
		ft_putchar(*s++);
}
void ft_putnbr(int nbr)
{
    if (nbr < 0)
    {
        nbr *= -1;
        ft_putchar('-');
    }
    if (nbr > 9)
    {
        ft_putnbr(nbr / 10);
        ft_putchar(nbr % 10 + '0');
    }
    else
        ft_putchar(nbr + 48);
}