/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_cf_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:18:32 by mbari             #+#    #+#             */
/*   Updated: 2020/10/30 13:07:13 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_diedwinscreen_texput(t_mlx *mlx)
{
	mlx->tex.died = mlx_xpm_file_to_image(mlx->win.mlx_ptr,
		mlx->tex.died_path, &mlx->tex.died_w, &mlx->tex.died_h);
	mlx->tex.died_data = (int *)mlx_get_data_addr(mlx->tex.died,
		&mlx->tex.died_bp, &mlx->tex.died_sl, &mlx->tex.died_end);
	mlx->tex.win = mlx_xpm_file_to_image(mlx->win.mlx_ptr,
		mlx->tex.win_path, &mlx->tex.win_w, &mlx->tex.win_h);
	mlx->tex.win_data = (int *)mlx_get_data_addr(mlx->tex.win,
		&mlx->tex.win_bp, &mlx->tex.win_sl, &mlx->tex.win_end);
}

void	ft_sprite_textput(t_mlx *mlx)
{
	mlx->tex.sprite = mlx_xpm_file_to_image(mlx->win.mlx_ptr,
		mlx->tex.sprite_path, &mlx->tex.sprite_w, &mlx->tex.sprite_h);
	mlx->tex.sprite_data = (int *)mlx_get_data_addr(mlx->tex.sprite,
		&mlx->tex.sprite_bp, &mlx->tex.sprite_sl, &mlx->tex.sprite_end);
	mlx->tex.coin = mlx_xpm_file_to_image(mlx->win.mlx_ptr,
		mlx->tex.coin_path, &mlx->tex.coin_w, &mlx->tex.coin_h);
	mlx->tex.coin_data = (int *)mlx_get_data_addr(mlx->tex.coin,
		&mlx->tex.coin_bp, &mlx->tex.coin_sl, &mlx->tex.coin_end);
	mlx->tex.bomb = mlx_xpm_file_to_image(mlx->win.mlx_ptr,
		mlx->tex.bomb_path, &mlx->tex.bomb_w, &mlx->tex.bomb_h);
	mlx->tex.bomb_data = (int *)mlx_get_data_addr(mlx->tex.bomb,
		&mlx->tex.bomb_bp, &mlx->tex.bomb_sl, &mlx->tex.bomb_end);
}

void	ft_sky_floor_texput(t_mlx *mlx)
{
	mlx->tex.txt_floor = mlx_xpm_file_to_image(mlx->win.mlx_ptr,
		mlx->tex.txt_floor_path, &mlx->tex.txt_floor_w, &mlx->tex.txt_floor_h);
	mlx->tex.txt_floor_data = (int *)mlx_get_data_addr(mlx->tex.txt_floor,
		&mlx->tex.txt_floor_bp, &mlx->tex.txt_floor_sl,
			&mlx->tex.txt_floor_end);
	mlx->tex.txt_ceiling = mlx_xpm_file_to_image(mlx->win.mlx_ptr,
		mlx->tex.txt_ceiling_path, &mlx->tex.txt_ceiling_w,
			&mlx->tex.txt_ceiling_h);
	mlx->tex.txt_ceiling_data = (int *)mlx_get_data_addr(mlx->tex.txt_ceiling,
		&mlx->tex.txt_ceiling_bp, &mlx->tex.txt_ceiling_sl,
			&mlx->tex.txt_ceiling_end);
}

void	ft_sky_floor_put(t_mlx *mlx, int y)
{
	int			x;
	int			ty;
	int			tx;
	uint32_t	color;

	x = 0;
	while (x < mlx->win.width)
	{
		mlx->tex.cellx = (int)(mlx->tex.floorx);
		mlx->tex.celly = (int)(mlx->tex.floory);
		tx = (int)(mlx->tex.txt_floor_w * (mlx->tex.floorx -
				mlx->tex.cellx)) & (mlx->tex.txt_floor_w - 1);
		ty = (int)(mlx->tex.txt_floor_h * (mlx->tex.floory -
				mlx->tex.celly)) & (mlx->tex.txt_floor_h - 1);
		mlx->tex.floorx += mlx->tex.floorstepx;
		mlx->tex.floory += mlx->tex.floorstepy;
		color = mlx->tex.txt_floor_data[mlx->tex.txt_floor_w * ty + tx];
		color = (color >> 1) & 8355711;
		mlx->tex.img_data[y * mlx->win.width + x] = color;
		color = mlx->tex.txt_ceiling_data[mlx->tex.txt_ceiling_w * ty + tx];
		color = (color >> 1) & 8355711;
		mlx->tex.img_data[(mlx->win.heigth - y - 1) *
			mlx->win.width + x] = color;
		x++;
	}
}

void	ft_sky_floor_texture(t_mlx *mlx)
{
	int y;

	y = 0;
	while (y < mlx->win.heigth)
	{
		mlx->tex.raydirx0 = mlx->dirx - mlx->planex;
		mlx->tex.raydiry0 = mlx->diry - mlx->planey;
		mlx->tex.raydirx1 = mlx->dirx + mlx->planex;
		mlx->tex.raydiry1 = mlx->diry + mlx->planey;
		mlx->tex.p = y - mlx->win.heigth / 2;
		mlx->tex.posz = 0.5 * mlx->win.heigth;
		mlx->tex.rowdistance = mlx->tex.posz / mlx->tex.p;
		mlx->tex.floorstepx = mlx->tex.rowdistance * (mlx->tex.raydirx1 -
			mlx->tex.raydirx0) / mlx->win.width;
		mlx->tex.floorstepy = mlx->tex.rowdistance * (mlx->tex.raydiry1 -
			mlx->tex.raydiry0) / mlx->win.width;
		mlx->tex.floorx = mlx->posx + mlx->tex.rowdistance * mlx->tex.raydirx0;
		mlx->tex.floory = mlx->posy + mlx->tex.rowdistance * mlx->tex.raydiry0;
		ft_sky_floor_put(mlx, y);
		y++;
	}
}
