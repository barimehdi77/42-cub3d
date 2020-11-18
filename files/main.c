/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:49:17 by mbari             #+#    #+#             */
/*   Updated: 2020/11/17 14:14:02 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_inti(t_mlx *mlx)
{
	mlx->win.mlx_ptr = mlx_init();
	mlx->posx = 0;
	mlx->posy = 0;
	mlx->movespeed = 0.08;
	mlx->rotspeed = 0.02;
	mlx->lines = NULL;
}

void	ft_draw_floorsky(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	while (x < mlx->win.width)
	{
		y = 0;
		while (y < mlx->win.heigth / 2)
		{
			mlx->tex.img_data[y * mlx->win.width + x] = mlx->sky_color;
			y++;
		}
		x++;
	}
	x = 0;
	while (x < mlx->win.width)
	{
		y = mlx->win.heigth / 2;
		while (y < mlx->win.heigth)
		{
			mlx->tex.img_data[y * mlx->win.width + x] = mlx->floor_color;
			y++;
		}
		x++;
	}
}

int		ft_loop(t_mlx *mlx)
{
	ft_move(mlx);
	ft_update(mlx, NO);
	return (0);
}

void	ft_start_game(char *fname, int save)
{
	t_mlx mlx;

	ft_inti(&mlx);
	ft_readmap(fname, &mlx);
	ft_texput(&mlx);
	if (save == 1)
		return (ft_screen_shot(&mlx));
	ft_printf("[Starting The Game...!]\n");
	mlx_hook(mlx.win.win_ptr, 2, (1L << 0), key_pressed, &mlx);
	mlx_hook(mlx.win.win_ptr, 3, (1L << 1), key_released, &mlx);
	mlx_hook(mlx.win.win_ptr, 17, 1L << 5, close_game, &mlx);
	mlx_loop_hook(mlx.win.mlx_ptr, ft_loop, &mlx);
	mlx_loop(mlx.win.mlx_ptr);
}

int		main(int ac, char **av)
{
	if (ac == 3 && ft_namecheck(av[1], "cub") && ft_savecheck(av[2], "--save"))
		ft_start_game(av[1], YES);
	else if (ac == 2 && ft_namecheck(av[1], "cub"))
		ft_start_game(av[1], NO);
	else
		write(2, "Error : Invalid arguments\n", 26);
	return (0);
}
