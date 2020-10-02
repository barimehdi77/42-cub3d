/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimaltohexadecimal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 00:55:24 by mbari             #+#    #+#             */
/*   Updated: 2019/12/28 13:24:20 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

char	*ft_decimaltohex(unsigned long dic, char type)
{
	char	*hexadecimal;
	int		i;
	int		rest;

	i = 0;
	hexadecimal = (char *)malloc(sizeof(char) * 17);
	if (dic == 0)
		hexadecimal[i++] = '0';
	else
		while (dic != 0)
		{
			rest = (dic % 16);
			if (rest < 10)
				hexadecimal[i] = rest + 48;
			else if (type == 'X')
				hexadecimal[i] = rest + 55;
			else if (type == 'x' || type == 'p')
				hexadecimal[i] = rest + 87;
			dic = dic / 16;
			i++;
		}
	hexadecimal[i] = '\0';
	hexadecimal[8] = (type == 'X' || type == 'x') ? '\0' : hexadecimal[8];
	ft_strrev(hexadecimal);
	return (hexadecimal);
}

char	*ft_pointer(void *p, t_print *val)
{
	unsigned long	hex;

	hex = (unsigned long)p;
	ft_putstr("0x", val);
	return (ft_decimaltohex(hex, 'p'));
}

void	ft_print_hex(const char *s, unsigned int dic, t_print *val)
{
	char	*ptr;

	ptr = (char *)s;
	if (val->type == 'x')
		ptr = ft_decimaltohex(dic, 'x');
	else if (val->type == 'X')
		ptr = ft_decimaltohex(dic, 'X');
	ft_putstr(ptr, val);
	free(ptr);
}
