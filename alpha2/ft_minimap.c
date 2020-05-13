/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 01:18:44 by mbari             #+#    #+#             */
/*   Updated: 2020/05/13 02:31:06 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_draw_square(t_minmap *img, int scale, int player, int color)
{
	//////////////////////////////////////////////////////////////////
	//    draw a sqaure starting from new_x and new_y               //
	//       you can put this in another function	                //
	//                   draw_square()		                //
	//////////////////////////////////////////////////////////////////
	img->max_x = img->new_x + scale;
	/**/while (img->new_x < img->max_x)				        //
	/**/{							        //
	/**/	img->new_y = img->y * scale; 				        //
	/**/	while (img->new_y < img->max_y)				        //
	/**/	{						        //
	/**/		img->img_data[img->new_x * 100 + img->new_y] = color; //	
	/**/		img->new_y++;				        //
	/**/	}						        //
	/**/	img->new_x++;					        //
	/**/}							        //
	//////////////////////////////////////////////////////////////////
}

void ft_fill_data(t_minmap *img, int iswall, int color)
{
	int scale = 10;
	img->new_x = img->x * scale;		//new starting x cordinate
	img->new_y = img->y * scale;		//new starting y cordinate

	img->max_x = img->new_x + scale;	//last x cordinate
	img->max_y = img->new_y + scale;  	//last y cordinate
	if (iswall == 1)
		ft_draw_square(img, scale, 0, color);
	else
		ft_draw_square(img, scale, 5, color);
	
}

void clear_image(t_mlx *mlx)
{
	int x;
	int y;
	
	while (x < 100)
	{
		y = -1;
		while (y < 100)
		{
				mlx->map.img_data[x * 100 + y] = 0x0000FF;
		}
	}
}

int ft_minmap(t_mlx *mlx)
{
	clear_image(mlx);
	///////////////////////////////////////	
	//				     //
	//	draw mini map		     //
	//				     //
	///////////////////////////////////////
    mlx->map.img_ptr = mlx_new_image(mlx->win.mlx_ptr, 100, 100);               //create a new empty image 
	mlx->map.img_data = (int*)mlx_get_data_addr(mlx->map.img_ptr, &mlx->map.bpp, 
                &mlx->map.size_line, &mlx->map.endian);  //get the data stored in the image
	mlx->map.x = 0;
	//////////////////////////
	//map loop "map[10][10]"//
	//////////////////////////
	worldMap[(int)mlx->posX][(int)mlx->posY] = '7';
	while (mlx->map.x < 10)
	{
		mlx->map.y = 0;
		while (mlx->map.y < 10)
		{
			if (worldMap[mlx->map.x][mlx->map.y] == '1')			//if there is a wall in {x,y} then draw square
				ft_fill_data(&mlx->map, 1, 0xFFFF00);
			else if (worldMap[mlx->map.x][mlx->map.y] == '0')
				ft_fill_data(&mlx->map, 1, 0x0000FF);
			else if (worldMap[mlx->map.x][mlx->map.y] == '7')
				ft_fill_data(&mlx->map, 0, 0XFFFFFF);
			mlx->map.y++;
		}
		mlx->map.x++;
	}
	mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr, mlx->map.img_ptr, 5, 5); //show the image on the window in x = 0 and y = 0 position
    return (0);
}