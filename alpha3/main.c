/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:49:17 by mbari             #+#    #+#             */
/*   Updated: 2020/05/16 02:03:52 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_inti(t_mlx *mlx)
{
    mlx->win.mlx_ptr = mlx_init();
    mlx->win.win_ptr = mlx_new_window(mlx->win.mlx_ptr, w, h, "cub3d alpha3");
    mlx->posX = 10;
	mlx->posY = 9.5;
	mlx->dirX = -1;
	mlx->dirY = 0;
	mlx->planeX = 0;
	mlx->planeY = 0.66;
	mlx->movespeed = 0.03;
	mlx->rotspeed = 0.02;
    mlx->forward = 0;
    mlx->backward = 0;
    mlx->left = 0;
    mlx->right = 0;
    mlx->rotleft = 0;
    mlx->rotright = 0;
}

/* void ft_texture()
{
    int buffer[h][w]; // y-coordinate first because it works per scanline
    int texture[8];
    for(int i = 0; i < 8; i++) 
        texture[i].resize(texWidth * texHeight);
}*/

void ft_draw_floorsky(t_mlx *mlx)
{
    int x;
    int y;

    x = 0;
    while (x < w)
    {
        y = 0;
        while (y < h / 2)
        {
            mlx->map.img_data[y * w + x] = 0x87ceeb;
            y++;
        }
        x++;
    }
    x = 0;
    while (x < w)
    {
        y = h / 2;
        while (y < h)
        {
            mlx->map.img_data[y * w + x] = 0x6b6b6b;
            y++;
        }
        x++;
    }
}

int ft_loop(t_mlx *mlx)
{
    ft_move(mlx);
    ft_update(mlx);
    return (0);
}

int main()
{
    t_mlx mlx;
    
    int i, j;
    int bpp, size_line, endian;
    ft_inti(&mlx);
    mlx.map.img_xpm = mlx_xpm_file_to_image(mlx.win.mlx_ptr, "greystone.xpm", &i, &j);
    mlx.map.xpm_data = (int *)mlx_get_data_addr(mlx.map.img_xpm, &bpp, &size_line, &endian);
    mlx_hook(mlx.win.win_ptr, 2, (1L << 0), key_pressed, &mlx);
    mlx_hook(mlx.win.win_ptr, 3, (1L << 1), key_released, &mlx);
    mlx_loop_hook(mlx.win.mlx_ptr, ft_loop, &mlx);
    mlx_loop(mlx.win.mlx_ptr);
}
