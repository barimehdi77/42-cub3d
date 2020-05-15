/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 01:45:06 by mbari             #+#    #+#             */
/*   Updated: 2020/05/15 05:33:54 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void ft_texture(t_mlx *mlx, int x)
{
    //texturing calculations
    mlx->tex.texnum = worldMap[mlx->ray.mapx][mlx->ray.mapy] - 1; //1 subtracted from it so that texture 0 can be used!

    //calculate value of wallX
    //where exactly the wall was hit
    if (mlx->ray.side == 0) 
        mlx->tex.wallx = mlx->posY + mlx->ray.perpWallDist * mlx->ray.raydiry;
    else           
        mlx->tex.wallx = mlx->posX + mlx->ray.perpWallDist * mlx->ray.raydirx;
    mlx->tex.wallx -= floor((mlx->tex.wallx));

    //x coordinate on the texture
    mlx->tex.texx = (int)(mlx->tex.wallx * (double)(texWidth));
    if(mlx->ray.side == 0 && mlx->ray.raydirx > 0) 
        mlx->tex.texx = texWidth - mlx->tex.texx - 1;
    if(mlx->ray.side == 1 && mlx->ray.raydiry < 0) 
        mlx->tex.texx = texWidth - mlx->tex.texx - 1;
    
        // How much to increase the texture coordinate per screen pixel
    mlx->tex.step = 1.0 * texHeight / mlx->wall.lineHeight;
    // Starting texture coordinate
    mlx->tex.texpos = (mlx->wall.drawStart - h / 2 + mlx->wall.lineHeight / 2) * mlx->tex.step;
    for(int y = mlx->wall.drawStart; y < mlx->wall.drawEnd; y++)
    {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        mlx->tex.texy = (int)mlx->tex.texpos & (texHeight - 1);
        mlx->tex.texpos += mlx->tex.step;
        long int color = mlx->map.xpm_data[texHeight * mlx->tex.texy + mlx->tex.texx];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(mlx->ray.side == 1) color = (color >> 1) & 8355711;
        mlx->map.img_data[y * 640 + x] = color;
    }
}
