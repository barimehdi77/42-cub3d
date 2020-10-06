/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 00:46:11 by mbari             #+#    #+#             */
/*   Updated: 2020/10/06 00:57:12 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_camerans(char dir, t_mlx *mlx)
{
	if (dir == 'N')
	{
		mlx->dirX = -1;
		mlx->dirY = 0;
		mlx->planeX = 0;
		mlx->planeY = 0.66;
	}
	else if (dir == 'S')
	{
		mlx->dirX = 1;
		mlx->dirY = 0;
		mlx->planeX = 0;
		mlx->planeY = -0.66;
	}
}

void	set_cameraew(char dir, t_mlx *mlx)
{
	if (dir == 'W')
	{
		mlx->dirX = 0;
		mlx->dirY = -1;
		mlx->planeX = -0.66;
		mlx->planeY = 0;
	}
	else if (dir == 'E')
	{
		mlx->dirX = 0;
		mlx->dirY = 1;
		mlx->planeX = 0.66;
		mlx->planeY = 0;
	}
}

int		player_init(int x, int y, char dir, t_mlx *mlx)
{
	if (dir != 'N' && dir != 'S' && dir != 'E' && dir != 'W')
		ft_put_error("INVALID MAP ITEM\n", mlx);
	if (mlx->player_pos > 0)
		ft_put_error("MULTIPLE SPAWNPOINTS SET\n", mlx);
	mlx->posX = x + 0.5;
	mlx->posY = y + 0.5;
	if (dir == 'N' || dir == 'S')
		set_camerans(dir, mlx);
	else
		set_cameraew(dir, mlx);
	mlx->forward = 0;
	mlx->backward = 0;
	mlx->left = 0;
	mlx->right = 0;
	mlx->rotright = 0;
	mlx->rotleft = 0;
	return (1);
}
