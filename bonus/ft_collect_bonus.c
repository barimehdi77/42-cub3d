/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:02:15 by mbari             #+#    #+#             */
/*   Updated: 2020/10/30 12:23:23 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int		ft_get_coin(t_mlx *mlx)
{
	int		i;
	int		j;
	int		coin;
	char	**map;

	i = 0;
	coin = 0;
	map = mlx->worldmap;
	while (i < mlx->max_x)
	{
		j = 0;
		while (j < mlx->max_y)
		{
			if (map[i][j] == 'C')
				coin++;
			j++;
		}
		i++;
	}
	return (coin);
}

void	ft_put_winscreen(t_mlx *mlx, long int color)
{
	int x;
	int y;
	int x_tex;
	int y_tex;

	x = 0;
	while (x < mlx->win.width)
	{
		y = 0;
		x_tex = x / (mlx->win.width / (float)mlx->tex.win_w);
		while (y < mlx->win.heigth)
		{
			y_tex = y / (mlx->win.heigth / (float)mlx->tex.win_h);
			color = mlx->tex.win_data[y_tex * mlx->tex.win_w + x_tex];
			mlx->tex.img_data[y * mlx->win.width + x] = color;
			y++;
		}
		x++;
	}
}

void	ft_put_diedscreen(t_mlx *mlx, long int color)
{
	int x;
	int y;
	int x_tex;
	int y_tex;

	x = 0;
	while (x < mlx->win.width)
	{
		y = 0;
		x_tex = x / (mlx->win.width / (float)mlx->tex.win_w);
		while (y < mlx->win.heigth)
		{
			y_tex = y / (mlx->win.heigth / (float)mlx->tex.win_h);
			color = mlx->tex.died_data[y_tex * mlx->tex.died_w + x_tex];
			mlx->tex.img_data[y * mlx->win.width + x] = color;
			y++;
		}
		x++;
	}
}

void	ft_win_or_died(t_mlx *mlx)
{
	if (mlx->player.score == mlx->player.coin)
		ft_put_winscreen(mlx, 0);
	if (mlx->player.hearts == 0)
		ft_put_diedscreen(mlx, 0);
}

void	ft_collect(t_mlx *mlx)
{
	char **map;

	map = mlx->worldmap;
	if (map[(int)mlx->posx][(int)mlx->posy] == 'C')
	{
		map[(int)mlx->posx][(int)mlx->posy] = '0';
		mlx->player.score++;
		Mix_PlayChannel(-1, mlx->music.hit_coin, 0);
	}
	if (map[(int)mlx->posx][(int)mlx->posy] == 'X')
	{
		map[(int)mlx->posx][(int)mlx->posy] = '0';
		mlx->player.hearts--;
		Mix_PlayChannel(-1, mlx->music.hit_domb, 0);
	}
	mlx->sp = ft_get_sprite(mlx);
	ft_win_or_died(mlx);
}
