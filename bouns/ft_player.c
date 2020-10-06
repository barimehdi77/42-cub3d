/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 00:53:22 by mbari             #+#    #+#             */
/*   Updated: 2020/10/06 00:57:33 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_mapvalue(int value, int x, int y, t_mlx *mlx)
{
	if (value != '1' && value != '2' && value != '0' && value != '7')
	{
		player_init(x, y, value, mlx);
		return (1);
	}
	return (0);
}

void	check_player(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	mlx->player_pos = 0;
	while (i <= mlx->max_x)
	{
		j = 0;
		while (j <= mlx->max_y)
		{
			mlx->player_pos += check_mapvalue(mlx->worldmap[i][j], i, j, mlx);
			j++;
		}
		i++;
	}
	if (mlx->player_pos == 0)
		ft_put_error("NO SPAWNPOINT\n", mlx);
}
