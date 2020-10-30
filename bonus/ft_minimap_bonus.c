/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 10:08:21 by mbari             #+#    #+#             */
/*   Updated: 2020/10/28 14:46:23 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_fill_data(t_mlx *mlx, int iswall, int color)
{
	int scale;

	scale = mlx->win.width / 150;
	if (scale > 7)
		scale = 7;
	else if (scale < 5)
		scale = 5;
	mlx->map.new_x = mlx->map.x * scale;
	mlx->map.new_y = mlx->map.y * scale;
	mlx->map.max_x = mlx->map.new_x + scale;
	mlx->map.max_y = mlx->map.new_y + scale;
	if (iswall == 1)
		ft_draw_square(mlx, scale, color);
	else
		ft_draw_square(mlx, scale, color);
}

void	draw_player(t_mlx *mlx)
{
	mlx->map.x = (int)mlx->posx;
	mlx->map.y = (int)mlx->posy;
	ft_fill_data(mlx, 0, RGB_RED);
}

int		ft_minmap(t_mlx *mlx)
{
	mlx->map.x = 0;
	while (mlx->map.x < mlx->max_x)
	{
		mlx->map.y = 0;
		while (mlx->map.y < mlx->max_y)
		{
			if (mlx->worldmap[mlx->map.x][mlx->map.y] == '1')
				ft_fill_data(mlx, 1, RGB_BLUE);
			else if (mlx->worldmap[mlx->map.x][mlx->map.y] == '2')
				ft_fill_data(mlx, 1, RGB_WHITE);
			else if (mlx->worldmap[mlx->map.x][mlx->map.y] == '7')
				ft_fill_data(mlx, 1, RGB_BLUE);
			else if (mlx->worldmap[mlx->map.x][mlx->map.y] == '4')
				ft_fill_data(mlx, 1, RGB_YELLOW);
			else if (mlx->worldmap[mlx->map.x][mlx->map.y] == '0' ||
						mlx->worldmap[mlx->map.x][mlx->map.y] == 'N')
				ft_fill_data(mlx, 1, RGB_WHITE);
			else
				ft_fill_data(mlx, 1, RGB_WHITE);
			mlx->map.y++;
		}
		mlx->map.x++;
	}
	draw_player(mlx);
	return (0);
}
