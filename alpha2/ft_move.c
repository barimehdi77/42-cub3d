/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:34:38 by mbari             #+#    #+#             */
/*   Updated: 2020/04/29 17:03:23 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void ft_rotate(int key, t_mlx *mlx)
{
	double oldPlaneX;
	double oldDirX;
    
	oldPlaneX = mlx->planeX;
	oldDirX = mlx->dirX;
    mlx_clear_window(mlx->win.mlx_ptr, mlx->win.win_ptr);
	//rotate to the right
    if (key == 100)
    {
      //both camera direction and camera plane must be rotated
      mlx->dirX = mlx->dirX * cos(-mlx->rotspeed) - mlx->dirY * sin(-mlx->rotspeed);
      mlx->dirY = oldDirX * sin(-mlx->rotspeed) + mlx->dirY * cos(-mlx->rotspeed);
      mlx->planeX = mlx->planeX * cos(-mlx->rotspeed) - mlx->planeY * sin(-mlx->rotspeed);
      mlx->planeY = oldPlaneX * sin(-mlx->rotspeed) + mlx->planeY * cos(-mlx->rotspeed);
    }
    //rotate to the left
    else if (key == 97)
    {
      //both camera direction and camera plane must be rotated
      mlx->dirX = mlx->dirX * cos(mlx->rotspeed) - mlx->dirY * sin(mlx->rotspeed);
      mlx->dirY = oldDirX * sin(mlx->rotspeed) + mlx->dirY * cos(mlx->rotspeed);
      mlx->planeX = mlx->planeX * cos(mlx->rotspeed) - mlx->planeY * sin(mlx->rotspeed);
      mlx->planeY = oldPlaneX * sin(mlx->rotspeed) + mlx->planeY * cos(mlx->rotspeed);
    }	
}

int	ft_move(int key, t_mlx *mlx)
{
	ft_putnbr(key);
	if (key == 65307)
		mlx_destroy_window(mlx->win.mlx_ptr, mlx->win.win_ptr);
	else if (key == 119)
	{
        mlx_clear_window(mlx->win.mlx_ptr, mlx->win.win_ptr);
		if(worldMap[(int)(mlx->posX + mlx->dirX * mlx->movespeed)][(int)(mlx->posY)] == 0)
			mlx->posX += mlx->dirX * mlx->movespeed;
      	if(worldMap[(int)(mlx->posX)][(int)(mlx->posY + mlx->dirY * mlx->movespeed)] == 0)
		  	mlx->posY += mlx->dirY * mlx->movespeed;
	}
	else if (key == 115)
	{
        mlx_clear_window(mlx->win.mlx_ptr, mlx->win.win_ptr);
		if(worldMap[(int)(mlx->posX - mlx->dirX * mlx->movespeed)][(int)(mlx->posY)] == 0)
			mlx->posX -= mlx->dirX * mlx->movespeed;
      	if(worldMap[(int)(mlx->posX)][(int)(mlx->posY - mlx->dirY * mlx->movespeed)] == 0)
		  	mlx->posY -= mlx->dirY * mlx->movespeed;
	}
	else if (key == 97 || key == 100)
		ft_rotate(key, mlx);
}