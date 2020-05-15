/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:02:42 by mbari             #+#    #+#             */
/*   Updated: 2020/05/15 05:58:27 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_steps(t_mlx *mlx, int x)
{
    double camirax;

    camirax = 2 * x / (double)w - 1;
    mlx->ray.raydirx = mlx->dirX + mlx->planeX * camirax;
    mlx->ray.raydiry = mlx->dirY + mlx->planeY * camirax;
    mlx->ray.mapx = mlx->posX;
    mlx->ray.mapy = mlx->posY;
    mlx->ray.deltaDistX = fabs(1 / mlx->ray.raydirx);
    mlx->ray.deltaDistY = fabs(1 / mlx->ray.raydiry);
    mlx->ray.hit = 0;
    //calculate step and initial sideDist
    if (mlx->ray.raydirx < 0)
    {
        mlx->ray.stepX = -1;
        mlx->ray.sideDistX = (mlx->posX - mlx->ray.mapx) * mlx->ray.deltaDistX;
    }
    else
    {
        mlx->ray.stepX = 1;
        mlx->ray.sideDistX = (mlx->ray.mapx + 1.0 - mlx->posX) * mlx->ray.deltaDistX;
    }
    if (mlx->ray.raydiry < 0)
    {
        mlx->ray.stepY = -1;
        mlx->ray.sideDistY = (mlx->posY - mlx->ray.mapy) * mlx->ray.deltaDistY;
    }
    else
    {
        mlx->ray.stepY = 1;
        mlx->ray.sideDistY = (mlx->ray.mapy + 1.0 - mlx->posY) * mlx->ray.deltaDistY;
    }
}

/* void ft_drawawall(int x, int y1, int y2, int color, t_mlx *mlx)
{
	if(y2 < y1) {y1 += y2; y2 = y1 - y2; y1 -= y2;} //swap y1 and y2
	if(y2 < 0 || y1 >= h  || x < 0 || x >= w) return ; //no single point of the line is on screen
	if(y1 < 0) y1 = 0; //clip
	if(y2 >= w) y2 = h - 1; //clip
	while (y1 <= y2)
	{
		mlx->map.img_data[y1 * 640 + x] = color;
        y1++;
	}
} */

int ft_draw(t_mlx *mlx, int x)
{
	long int color;
	
        color = RGB_Red;
	//Calculate height of line to draw on screen
	mlx->wall.lineHeight = (int)(h / mlx->ray.perpWallDist);
	//calculate lowest and highest pixel to fill in current stripe
	mlx->wall.drawStart = -mlx->wall.lineHeight / 2 + h / 2;
	if(mlx->wall.drawStart < 0)
		mlx->wall.drawStart = 0;
	mlx->wall.drawEnd = mlx->wall.lineHeight / 2 + h / 2;
	if(mlx->wall.drawEnd >= h)
		mlx->wall.drawEnd = h - 1;
    ft_texture(mlx, x);
}

int ft_update(t_mlx *mlx)
{
    mlx->map.img_ptr = mlx_new_image(mlx->win.mlx_ptr, 640, 480);               //create a new empty image 
    mlx->map.img_data = (int *)mlx_get_data_addr(mlx->map.img_ptr, &mlx->map.bpp,&mlx->map.size_line, &mlx->map.endian);  //get the data stored in the image
    ft_draw_floorsky(mlx);
    int x;
    x = 0;
    while (x < w)
    {
        ft_steps(mlx, x);
        //perform DDA
        while (mlx->ray.hit == 0)
        {
            //jump to next map square, OR in x-direction, OR in y-direction
            if (mlx->ray.sideDistX < mlx->ray.sideDistY)
            {
                mlx->ray.sideDistX += mlx->ray.deltaDistX;
                mlx->ray.mapx += mlx->ray.stepX;
                mlx->ray.side = 0;
            }
            else
            {
                mlx->ray.sideDistY += mlx->ray.deltaDistY;
                mlx->ray.mapy += mlx->ray.stepY;
                mlx->ray.side = 1;
            }
            //Check if ray has hit a wall
            if (worldMap[mlx->ray.mapx][mlx->ray.mapy] != '0')
                mlx->ray.hit = 1;
        }
        //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
        if (mlx->ray.side == 0)
            mlx->ray.perpWallDist = (mlx->ray.mapx - mlx->posX + (1 - mlx->ray.stepX) / 2) / mlx->ray.raydirx;
        else
            mlx->ray.perpWallDist = (mlx->ray.mapy - mlx->posY + (1 - mlx->ray.stepY) / 2) / mlx->ray.raydiry;
        ft_draw(mlx, x);
        x++;
    }
    ///////////////////////////////////////////////
    //                                           //
    //	Draw the minimap after drawing the walls //
    //	                                         //
    ///////////////////////////////////////////////
    ft_minmap(mlx);                              //
    ///////////////////////////////////////////////
    
    mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr, mlx->map.img_ptr, 0, 0); //show the image on the window
    mlx_destroy_image (mlx->win.mlx_ptr, mlx->map.img_ptr);   
    return (0);
}
