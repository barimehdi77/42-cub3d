/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:49:17 by mbari             #+#    #+#             */
/*   Updated: 2020/10/06 00:58:14 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void ft_inti(t_mlx *mlx)
{
    mlx->win.mlx_ptr = mlx_init();
    mlx->posX = 0;
	mlx->posY = 0;
	mlx->movespeed = 0.03;
	mlx->rotspeed = 0.02;
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
            mlx->tex.img_data[y * w + x] = mlx->sky_color;//0x87ceeb;
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
            mlx->tex.img_data[y * w + x] = mlx->floor_color;//0x6b6b6b;
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

void ft_texput(t_mlx *mlx)
{
    //wall Textures
    mlx->tex.txt1 = mlx_xpm_file_to_image(mlx->win.mlx_ptr, mlx->tex.txt1_path, &mlx->tex.txt1_w, &mlx->tex.txt1_h);
    mlx->tex.txt1_data = (int *)mlx_get_data_addr(mlx->tex.txt1, &mlx->tex.txt1_bp, &mlx->tex.txt1_sl, &mlx->tex.txt1_end);
    mlx->tex.txt2 = mlx_xpm_file_to_image(mlx->win.mlx_ptr, mlx->tex.txt2_path, &mlx->tex.txt2_w, &mlx->tex.txt2_h);
    mlx->tex.txt2_data = (int *)mlx_get_data_addr(mlx->tex.txt2, &mlx->tex.txt2_bp, &mlx->tex.txt2_sl, &mlx->tex.txt2_end);
    mlx->tex.txt3 = mlx_xpm_file_to_image(mlx->win.mlx_ptr, mlx->tex.txt3_path, &mlx->tex.txt3_w, &mlx->tex.txt3_h);
    mlx->tex.txt3_data = (int *)mlx_get_data_addr(mlx->tex.txt3, &mlx->tex.txt3_bp, &mlx->tex.txt3_sl, &mlx->tex.txt3_end);
    mlx->tex.txt4 = mlx_xpm_file_to_image(mlx->win.mlx_ptr, mlx->tex.txt4_path, &mlx->tex.txt4_w, &mlx->tex.txt4_h);
    mlx->tex.txt4_data = (int *)mlx_get_data_addr(mlx->tex.txt4, &mlx->tex.txt4_bp, &mlx->tex.txt4_sl, &mlx->tex.txt4_end);
    //sprite textures
    mlx->tex.sp = mlx_xpm_file_to_image(mlx->win.mlx_ptr, mlx->tex.sp_path, &mlx->tex.sp_w, &mlx->tex.sp_h);
    mlx->tex.sp_data = (int *)mlx_get_data_addr(mlx->tex.sp, &mlx->tex.sp_bp, &mlx->tex.sp_sl, &mlx->tex.sp_end);
}


void ft_start_game(char *fname, int save)
{
    t_mlx mlx;

    ft_inti(&mlx);
    ft_readmap(fname, &mlx);
    //load the tetures
    ft_texput(&mlx);
    //ft_printf("|%d||%d||%d||%d|", mlx.tex.txt1_w, mlx.tex.txt2_w, mlx.tex.txt3_w, mlx.tex.txt4_w);
    if (save == 1)
        return(screen_shot(&mlx));
    mlx_hook(mlx.win.win_ptr, 2, (1L << 0), key_pressed, &mlx);
    mlx_hook(mlx.win.win_ptr, 3, (1L << 1), key_released, &mlx);
    mlx_loop_hook(mlx.win.mlx_ptr, ft_loop, &mlx);
    mlx_loop(mlx.win.mlx_ptr);
}
int		ft_savecheck(char *arg, char *save)
{
	int	i;

	i = 0;
	while (arg[i] == save[i])
	{
		if (arg[i] == '\0' && save[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		ft_namecheck(char *arg, char *ext)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	if ((i > 4 && arg[i - 1] == ext[2] && arg[i - 2] == ext[1])
		&& (arg[i - 3] == ext[0] && arg[i - 4] == '.'))
		return (1);
	return (0);
}

int main(int ac, char **av)
{
    /*if (ac < 2)
       ft_printf("\nPlease choose The map\nthe maps in file named maps\n./cub3d maps/*.cub\n");
    else if (ac > 2)
        ft_printf("Too many args please check\n");
    else  
        ft_start_game(av[1]); */
        
    if (ac == 3 && ft_namecheck(av[1], "cub") && ft_savecheck(av[2], "--save"))
		ft_start_game(av[1], 1);
	else if (ac == 2 && ft_namecheck(av[1], "cub"))
		ft_start_game(av[1], 0);
	else
		write(2, "Error : Invalid arguments\n", 26);
    //ft_start_game("maps/3.cub", 0);
	return (0);
}
