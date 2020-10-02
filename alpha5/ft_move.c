/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:34:38 by mbari             #+#    #+#             */
/*   Updated: 2020/09/02 16:24:41 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void ft_rotate(t_mlx *mlx)
{
	double oldPlaneX;
	double oldDirX;
    
	oldPlaneX = mlx->planeX;
	oldDirX = mlx->dirX;
	//rotate to the right
    if (mlx->rotright)
    {
      //both camera direction and camera plane must be rotated
      mlx->dirX = mlx->dirX * cos(-mlx->rotspeed) - mlx->dirY * sin(-mlx->rotspeed);
      mlx->dirY = oldDirX * sin(-mlx->rotspeed) + mlx->dirY * cos(-mlx->rotspeed);
      mlx->planeX = mlx->planeX * cos(-mlx->rotspeed) - mlx->planeY * sin(-mlx->rotspeed);
      mlx->planeY = oldPlaneX * sin(-mlx->rotspeed) + mlx->planeY * cos(-mlx->rotspeed);
    }
    //rotate to the left
    if (mlx->rotleft)
    {
      //both camera direction and camera plane must be rotated
      mlx->dirX = mlx->dirX * cos(mlx->rotspeed) - mlx->dirY * sin(mlx->rotspeed);
      mlx->dirY = oldDirX * sin(mlx->rotspeed) + mlx->dirY * cos(mlx->rotspeed);
      mlx->planeX = mlx->planeX * cos(mlx->rotspeed) - mlx->planeY * sin(mlx->rotspeed);
      mlx->planeY = oldPlaneX * sin(mlx->rotspeed) + mlx->planeY * cos(mlx->rotspeed);
    }	
}

int	ft_move(t_mlx *mlx)
{
	if (mlx->forward)
	{
		if(mlx->worldmap[(int)(mlx->posX + mlx->dirX * mlx->movespeed)][(int)(mlx->posY)] == '0')
			mlx->posX += mlx->dirX * mlx->movespeed * 0.5;
      	if(mlx->worldmap[(int)(mlx->posX)][(int)(mlx->posY + mlx->dirY * mlx->movespeed)] == '0')
		  	mlx->posY += mlx->dirY * mlx->movespeed * 0.5;
		//printf("|posx= %f||posy= %f|",mlx->posX,mlx->posY);
	}
	if (mlx->backward)
	{
		if(mlx->worldmap[(int)(mlx->posX - mlx->dirX * mlx->movespeed)][(int)(mlx->posY)] == '0')
			mlx->posX -= mlx->dirX * mlx->movespeed * 0.5;
      	if(mlx->worldmap[(int)(mlx->posX)][(int)(mlx->posY - mlx->dirY * mlx->movespeed)] == '0')
		  	mlx->posY -= mlx->dirY * mlx->movespeed * 0.5;
	}
	if (mlx->left)//move left
	{
		if(mlx->worldmap[(int)(mlx->posX)][(int)(mlx->posY + mlx->dirX * mlx->movespeed)] == '0')
		  	mlx->posY += mlx->dirX * mlx->movespeed * 0.5;
		if(mlx->worldmap[(int)(mlx->posX - mlx->dirY * mlx->movespeed)][(int)(mlx->posY)] == '0')
			mlx->posX -= mlx->dirY * mlx->movespeed * 0.5;
	}
	if (mlx->right)//move right
	{
		if(mlx->worldmap[(int)(mlx->posX)][(int)(mlx->posY - mlx->dirX * mlx->movespeed)] == '0')
		  	mlx->posY -= mlx->dirX * mlx->movespeed * 0.5;
		if(mlx->worldmap[(int)(mlx->posX + mlx->dirY * mlx->movespeed)][(int)(mlx->posY)] == '0')
			mlx->posX += mlx->dirY * mlx->movespeed * 0.5;
	}
	if (mlx->rotleft || mlx->rotright)
		ft_rotate(mlx);
}