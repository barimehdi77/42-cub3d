/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 01:18:44 by mbari             #+#    #+#             */
/*   Updated: 2020/06/21 15:53:47 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_draw_square(t_mlx *mlx, int scale, int player, int color)
{
	//////////////////////////////////////////////////////////////////
	//    draw a sqaure starting from new_x and new_y               //
	//       you can put this in another function	                //
	//                   draw_square()		                        //
	//////////////////////////////////////////////////////////////////
	mlx->map.max_x = mlx->map.new_x + scale;
	while (mlx->map.new_x < mlx->map.max_x)				        
	{							        
		mlx->map.new_y = mlx->map.y * scale; 				        
		while (mlx->map.new_y < mlx->map.max_y)				        
		{						        
			mlx->tex.img_data[mlx->map.new_x * w + mlx->map.new_y] = color; 	
			mlx->map.new_y++;				        
		}						        
		mlx->map.new_x++;					     
	}							        
}

void ft_fill_data(t_mlx *mlx, int iswall, int color)
{
	int scale = 7;
	mlx->map.new_x = mlx->map.x * scale;		//new starting x cordinate
	mlx->map.new_y = mlx->map.y * scale;		//new starting y cordinate

	mlx->map.max_x = mlx->map.new_x + scale;	//last x cordinate
	mlx->map.max_y = mlx->map.new_y + scale;  	//last y cordinate
	if (iswall == 1)
		ft_draw_square(mlx, scale, 0, color); // if (iswall == 1) so draw a wall in minimap
	else
		ft_draw_square(mlx, scale, 5, color); // if (iswall == 0) so draw a player psoition in minimap
	
}

void	draw_player(t_mlx *mlx)
{
	mlx->map.x = (int)mlx->posX;
	mlx->map.y = (int)mlx->posY;
	ft_fill_data(mlx, 0, 0x42EFF5); //fill the player position square
}

int ft_minmap(t_mlx *mlx)
{
	mlx->map.x = 0;
	while (mlx->map.x < mlx->max_x)
	{
		mlx->map.y = 0;
		while (mlx->map.y < mlx->max_y)
		{
			if (mlx->worldmap[mlx->map.x][mlx->map.y] == '1')			//if there is a wall in {x,y} then draw square
				ft_fill_data(mlx, 1, RGB_Blue);
			else if (mlx->worldmap[mlx->map.x][mlx->map.y] == '2')			//if there is a wall in {x,y} then draw square
				ft_fill_data(mlx, 1, RGB_Green);
			else if (mlx->worldmap[mlx->map.x][mlx->map.y] == '3')			//if there is a wall in {x,y} then draw square
				ft_fill_data(mlx, 1, RGB_Blue);
			else if (mlx->worldmap[mlx->map.x][mlx->map.y] == '4')			//if there is a wall in {x,y} then draw square
				ft_fill_data(mlx, 1, RGB_White);
			else if (mlx->worldmap[mlx->map.x][mlx->map.y] == '0'  ||
						 mlx->worldmap[mlx->map.x][mlx->map.y] == 'N')
				ft_fill_data(mlx, 1, mlx->floor_color);
			else
				ft_fill_data(mlx, 1, RGB_Yellow);
			mlx->map.y++;
		}
		mlx->map.x++;
	}
	draw_player(mlx);
    return (0);
}
