/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:49:17 by mbari             #+#    #+#             */
/*   Updated: 2020/05/13 02:19:40 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_inti(t_mlx *mlx)
{
    mlx->win.mlx_ptr = mlx_init();
    mlx->win.win_ptr = mlx_new_window(mlx->win.mlx_ptr, w, h, "cub3d alpha2");
    mlx->posX = 6;//22
	mlx->posY = 4.5;//12
	mlx->dirX = -1;
	mlx->dirY = 0;
	mlx->planeX = 0;
	mlx->planeY = 0.66;
	mlx->movespeed = 0.5;
	mlx->rotspeed = 0.5;
}

void ft_texture()
{
    int buffer[h][w]; // y-coordinate first because it works per scanline
    int texture[8];
    /* for(int i = 0; i < 8; i++) 
        texture[i].resize(texWidth * texHeight); */
}
int move(int key, t_mlx *mlx)
{
    ft_move(key, mlx);
    ft_update(mlx);
    ft_minmap(mlx);
}
int main()
{
    t_mlx mlx;
    
    ft_inti(&mlx);
    ft_update(&mlx);
    ft_minmap(&mlx);
    mlx_key_hook(mlx.win.win_ptr, move, &mlx);
    mlx_loop_hook(mlx.win.mlx_ptr, ft_update, &mlx);
    mlx_loop(mlx.win.mlx_ptr);
}