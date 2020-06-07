/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:49:17 by mbari             #+#    #+#             */
/*   Updated: 2020/06/07 21:00:01 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_inti(t_mlx *mlx)
{
    mlx->win.mlx_ptr = mlx_init();
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
            mlx->tex.img_data[y * w + x] = 0x87ceeb;
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
            mlx->tex.img_data[y * w + x] = 0x6b6b6b;
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

void ft_start_game(char *fname)
{
    t_mlx mlx;

    ft_inti(&mlx);
    ft_readmap(fname, &mlx);
    mlx.tex.txt1 = mlx_xpm_file_to_image(mlx.win.mlx_ptr, mlx.tex.txt1_path, &mlx.tex.txt1_w, &mlx.tex.txt1_h);
    mlx.tex.txt1_data = (int *)mlx_get_data_addr(mlx.tex.txt1, &mlx.tex.txt1_bp, &mlx.tex.txt1_sl, &mlx.tex.txt1_end);
    mlx.tex.txt2 = mlx_xpm_file_to_image(mlx.win.mlx_ptr, mlx.tex.txt2_path, &mlx.tex.txt2_w, &mlx.tex.txt2_h);
    mlx.tex.txt2_data = (int *)mlx_get_data_addr(mlx.tex.txt2, &mlx.tex.txt2_bp, &mlx.tex.txt1_sl, &mlx.tex.txt2_end);
    mlx.tex.txt3 = mlx_xpm_file_to_image(mlx.win.mlx_ptr, mlx.tex.txt3_path, &mlx.tex.txt3_w, &mlx.tex.txt3_h);
    mlx.tex.txt3_data = (int *)mlx_get_data_addr(mlx.tex.txt3, &mlx.tex.txt3_bp, &mlx.tex.txt1_sl, &mlx.tex.txt3_end);
    mlx.tex.txt4 = mlx_xpm_file_to_image(mlx.win.mlx_ptr, mlx.tex.txt4_path, &mlx.tex.txt4_w, &mlx.tex.txt4_h);
    mlx.tex.txt4_data = (int *)mlx_get_data_addr(mlx.tex.txt4, &mlx.tex.txt4_bp, &mlx.tex.txt1_sl, &mlx.tex.txt4_end);
    ft_printf("|%d||%d||%d||%d|", mlx.tex.txt1_w, mlx.tex.txt2_w, mlx.tex.txt3_w, mlx.tex.txt4_w);
    mlx_hook(mlx.win.win_ptr, 2, (1L << 0), key_pressed, &mlx);
    mlx_hook(mlx.win.win_ptr, 3, (1L << 1), key_released, &mlx);
    mlx_loop_hook(mlx.win.mlx_ptr, ft_loop, &mlx);
    mlx_loop(mlx.win.mlx_ptr);
}

int main(int ac, char **av)
{
    if (ac < 2)
       ft_printf("\nPlease choose The map\nthe maps in file named maps\n./cub3d maps/*.cub\n");
    else if (ac > 2)
        ft_printf("Too many args please check\n");
    else 
        ft_start_game(av[1]);
    //ft_start_game("maps/1.cub"); 
}
