/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 01:45:06 by mbari             #+#    #+#             */
/*   Updated: 2020/05/16 01:59:53 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_put_tex_to_image(t_mlx *mlx, int y1, int y2, int x)
{
    while (y1 < y2)
    {
         // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        mlx->tex.y = (int)mlx->tex.pos & (texHeight - 1);
        mlx->tex.pos += mlx->tex.step;
        long int color = mlx->map.xpm_data[texHeight * mlx->tex.y + mlx->tex.x];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(mlx->ray.side == 1) color = (color >> 1) & 8355711;
        mlx->map.img_data[y1 * w + x] = color;
        y1++;
    }   
}

void ft_texture(t_mlx *mlx, int x)
{
    //texturing calculations
    mlx->tex.num = worldMap[mlx->ray.mapx][mlx->ray.mapy] - 1; //1 subtracted from it so that texture 0 can be used!
    //calculate value of wallX
    //where exactly the wall was hit
    if (mlx->ray.side == 0) 
        mlx->tex.wallx = mlx->posY + mlx->ray.perpWallDist * mlx->ray.raydiry;
    else           
        mlx->tex.wallx = mlx->posX + mlx->ray.perpWallDist * mlx->ray.raydirx;
    mlx->tex.wallx -= floor((mlx->tex.wallx));

    //x coordinate on the texture
    mlx->tex.x = (int)(mlx->tex.wallx * (double)(texWidth));
    if(mlx->ray.side == 0 && mlx->ray.raydirx > 0) 
        mlx->tex.x = texWidth - mlx->tex.x - 1;
    if(mlx->ray.side == 1 && mlx->ray.raydiry < 0) 
        mlx->tex.x = texWidth - mlx->tex.x - 1;
    
        // How much to increase the texture coordinate per screen pixel
    mlx->tex.step = 1.0 * texHeight / mlx->wall.lineHeight;
    // Starting texture coordinate
    mlx->tex.pos = (mlx->wall.drawStart - h / 2 + mlx->wall.lineHeight / 2) * mlx->tex.step;
    /* for(int y = mlx->wall.drawStart; y < mlx->wall.drawEnd; y++)
    {
       
    } */
    ft_put_tex_to_image(mlx, mlx->wall.drawStart, mlx->wall.drawEnd, x);
}
