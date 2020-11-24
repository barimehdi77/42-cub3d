/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 10:08:05 by mbari             #+#    #+#             */
/*   Updated: 2020/11/24 13:28:06 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	set_camerans(char dir, t_mlx *mlx)
{
	if (dir == 'N')
	{
		mlx->dirx = -1;
		mlx->diry = 0;
		mlx->planex = 0;
		mlx->planey = 0.66;
	}
	else if (dir == 'S')
	{
		mlx->dirx = 1;
		mlx->diry = 0;
		mlx->planex = 0;
		mlx->planey = -0.66;
	}
}

void	set_cameraew(char dir, t_mlx *mlx)
{
	if (dir == 'W')
	{
		mlx->dirx = 0;
		mlx->diry = -1;
		mlx->planex = -0.66;
		mlx->planey = 0;
	}
	else if (dir == 'E')
	{
		mlx->dirx = 0;
		mlx->diry = 1;
		mlx->planex = 0.66;
		mlx->planey = 0;
	}
}

void	init_params(t_mlx *mlx)
{
	mlx->screen_done = 0;
	mlx->tex1_done = 0;
	mlx->tex2_done = 0;
	mlx->tex3_done = 0;
	mlx->tex4_done = 0;
	mlx->spr_done = 0;
	mlx->tex_ceiling_done = 0;
	mlx->tex_floor_done = 0;
	mlx->tex_coin_done = 0;
	mlx->tex_bomb_done = 0;
	mlx->tex_heart_done = 0;
	mlx->tex_died_done = 0;
	mlx->tex_win_done = 0;
}

void	init_map(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	mlx->worldmap = malloc((mlx->max_x + 1) * sizeof(int *));
	while (i <= mlx->max_x)
	{
		mlx->worldmap[i] = malloc((mlx->max_y + 1) * sizeof(int));
		j = 0;
		while (j <= mlx->max_y)
		{
			mlx->worldmap[i][j] = '7';
			j++;
		}
		i++;
	}
}

int		player_init(int x, int y, char dir, t_mlx *mlx)
{
	if (dir != 'N' && dir != 'S' && dir != 'E' && dir != 'W')
		ft_put_error("INVALID MAP ITEM\n", mlx);
	if (mlx->player_pos > 0)
		ft_put_error("MULTIPLE SPAWNPOINTS SET\n", mlx);
	mlx->posx = x + 0.5;
	mlx->posy = y + 0.5;
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
