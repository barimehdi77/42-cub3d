/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 18:24:29 by mbari             #+#    #+#             */
/*   Updated: 2020/10/06 00:57:41 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		close_game(t_mlx *mlx)
{
	int i;

	i = 0;
	if (mlx->lines)
	{
		while (mlx->lines[i])
		{
			free(mlx->lines[i]);
			i++;
		}
		free(mlx->lines);
	}
	exit(EXIT_SUCCESS);
}


void ft_put_error(char *error,t_mlx *mlx)
{
    ft_printf("Error:\n\t%s\n",error);
    close_game(mlx);
}