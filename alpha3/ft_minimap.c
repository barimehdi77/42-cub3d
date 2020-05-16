/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 01:18:44 by mbari             #+#    #+#             */
/*   Updated: 2020/05/16 01:33:28 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_draw_square(t_minmap *img, int scale, int player, int color)
{
	//////////////////////////////////////////////////////////////////
	//    draw a sqaure starting from new_x and new_y               //
	//       you can put this in another function	                //
	//                   draw_square()		                        //
	//////////////////////////////////////////////////////////////////
	img->max_x = img->new_x + scale;
	while (img->new_x < img->max_x)				        
	{							        
		img->new_y = img->y * scale; 				        
		while (img->new_y < img->max_y)				        
		{						        
			img->img_data[img->new_x * w + img->new_y] = color; 	
			img->new_y++;				        
		}						        
		img->new_x++;					     
	}							        
}

void ft_fill_data(t_minmap *img, int iswall, int color)
{
	int scale = 10;
	img->new_x = img->x * scale;		//new starting x cordinate
	img->new_y = img->y * scale;		//new starting y cordinate

	img->max_x = img->new_x + scale;	//last x cordinate
	img->max_y = img->new_y + scale;  	//last y cordinate
	if (iswall == 1)
		ft_draw_square(img, scale, 0, color); // if (iswall == 1) so draw a wall in minimap
	else
		ft_draw_square(img, scale, 5, color); // if (iswall == 0) so draw a player psoition in minimap
	
}

void	draw_player(t_mlx *mlx)
{
	mlx->map.x = (int)mlx->posX;
	mlx->map.y = (int)mlx->posY;
	ft_fill_data(&mlx->map, 0, 0x42EFF5); //fill the player position square
}

int ft_minmap(t_mlx *mlx)
{
	mlx->map.x = 0;
	while (mlx->map.x < mapWidth)
	{
		mlx->map.y = 0;
		while (mlx->map.y < mapHeight)
		{
			if (worldMap[mlx->map.x][mlx->map.y] == '1')			//if there is a wall in {x,y} then draw square
				ft_fill_data(&mlx->map, 1, RGB_Red);
			else if (worldMap[mlx->map.x][mlx->map.y] == '2')			//if there is a wall in {x,y} then draw square
				ft_fill_data(&mlx->map, 1, RGB_Green);
			else if (worldMap[mlx->map.x][mlx->map.y] == '3')			//if there is a wall in {x,y} then draw square
				ft_fill_data(&mlx->map, 1, RGB_Blue);
			else if (worldMap[mlx->map.x][mlx->map.y] == '4')			//if there is a wall in {x,y} then draw square
				ft_fill_data(&mlx->map, 1, RGB_White);
			else if (worldMap[mlx->map.x][mlx->map.y] == '0')
				ft_fill_data(&mlx->map, 1, 0xFF30FF);
			else
				ft_fill_data(&mlx->map, 1, RGB_Yellow);
			mlx->map.y++;
		}
		mlx->map.x++;
	}
	draw_player(mlx);
    return (0);
}
