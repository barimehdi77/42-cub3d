/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:02:42 by mbari             #+#    #+#             */
/*   Updated: 2020/04/29 17:02:43 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


void ft_steps(t_mlx *mlx, int x)
{
    double camirax;

    camirax = 2 * x / (double)w - 1;
    mlx->ray.raydirx = mlx->dirX + mlx->planeX * camirax;
    mlx->ray.raydiry = mlx->dirY + mlx->planeY * camirax;
    mlx->ray.mapx = mlx->posX;
    mlx->ray.mapy = mlx->posY;
    mlx->ray.deltaDistX = abs(1 / mlx->ray.raydirx);
    mlx->ray.deltaDistY = abs(1 / mlx->ray.raydiry);
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

void ft_drawawall(int x, int y1, int y2, int color, t_window *win)
{
	if(y2 < y1) {y1 += y2; y2 = y1 - y2; y1 -= y2;} //swap y1 and y2
	if(y2 < 0 || y1 >= h  || x < 0 || x >= w) return ; //no single point of the line is on screen
	if(y1 < 0) y1 = 0; //clip
	if(y2 >= w) y2 = h - 1; //clip
	while (y1 <= y2)
	{
    	mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y1, color);
		y1++;
	}
}

int ft_draw(t_mlx *mlx, int x)
{
	long int color;
	
	//Calculate height of line to draw on screen
	mlx->wall.lineHeight = (int)(h / mlx->ray.perpWallDist);
	//calculate lowest and highest pixel to fill in current stripe
	mlx->wall.drawStart = -mlx->wall.lineHeight / 2 + h / 2;
	if(mlx->wall.drawStart < 0)
		mlx->wall.drawStart = 0;
	mlx->wall.drawEnd = mlx->wall.lineHeight / 2 + h / 2;
	if(mlx->wall.drawEnd >= h)
		mlx->wall.drawEnd = h - 1;
	//choose wall color
	switch(worldMap[mlx->ray.mapx][mlx->ray.mapy])
	{
	case 1:  color = RGB_Red;  break; //red
	case 2:  color = RGB_Green;  break; //green
	case 3:  color = RGB_Blue;   break; //blue
	case 4:  color = RGB_White;  break; //white
	default: color = RGB_Yellow; break; //yellow
	}

	//give x and y sides different brightness
	if (mlx->ray.side == 1) {color = color / 2;}

	//draw the pixels of the stripe as a vertical line
	ft_drawawall(x, mlx->wall.drawStart, mlx->wall.drawEnd, color, &mlx->win);
}

int ft_update(t_mlx *mlx)
{
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
            if (worldMap[mlx->ray.mapx][mlx->ray.mapy] > 0)
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
    return (0);
}