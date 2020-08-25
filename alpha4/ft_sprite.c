/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:26:22 by mbari             #+#    #+#             */
/*   Updated: 2020/08/21 00:45:35 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void ft_sprite(t_mlx *mlx, double *zbuffer)
{
    double spriteX = mlx->sp.x - mlx->posX;
    double spriteY = mlx->sp.y - mlx->posY;
    double invDet = 1.0 / (mlx->planeX * mlx->dirY - mlx->dirX * mlx->planeY); //required for correct matrix multiplication

    double transformX = invDet * (mlx->dirY * spriteX - mlx->dirX * spriteY);
    double transformY = invDet * (-mlx->planeY * spriteX + mlx->planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

    int spriteScreenX = (int)(w / 2) * (1 + transformX / transformY);

    //calculate height of the sprite on screen
    int spriteHeight = abs((int)(h / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
    //calculate lowest and highest pixel to fill in current stripe
    int drawStartY = -spriteHeight / 2 + h / 2;
    if(drawStartY < 0) drawStartY = 0;
    int drawEndY = spriteHeight / 2 + h / 2;
    if(drawEndY >= h) drawEndY = h - 1;

    //calculate width of the sprite
    int spriteWidth = abs((int)(h / (transformY)));
    int drawStartX = -spriteWidth / 2 + spriteScreenX;
    if(drawStartX < 0) drawStartX = 0;
    int drawEndX = spriteWidth / 2 + spriteScreenX;
    if(drawEndX >= w) drawEndX = w - 1;
    for(int stripe = drawStartX; stripe < drawEndX; stripe++)
    {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) it's on the screen (left)
        //3) it's on the screen (right)
        //4) ZBuffer, with perpendicular distance
        if(transformY > 0 && stripe > 0 && stripe < w && transformY < zbuffer[stripe])
             for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
            {
                int d = (y) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
                mlx->tex.y = ((d * texHeight) / spriteHeight) / 256;
                //long int color = mlx->tex.xpm_data[texWidth * mlx->tex.y + mlx->tex.x]; //get current color from the texture
                long int color = mlx->tex.sp_data[texWidth * mlx->tex.y + texX];
                if((color & 0x00FFFFFF) != 0) 
                    mlx->tex.img_data[y * w + stripe] = color; //paint pixel if it isn't black, black is the invisible color
            }
    }
}