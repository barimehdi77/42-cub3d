/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:58:18 by mbari             #+#    #+#             */
/*   Updated: 2020/11/24 13:33:23 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	read_txt(int dir, char *str, t_mlx *mlx)
{
	int fd;

	while (*str == ' ')
		str++;
	if ((fd = open(str, O_RDONLY)) < 0)
		ft_put_error("WRONG TEXTURE PATH INPUT\n", mlx);
	close(fd);
	if (dir == 1)
		mlx->tex.txt1_path = str;
	else if (dir == 2)
		mlx->tex.txt2_path = str;
	else if (dir == 3)
		mlx->tex.txt3_path = str;
	else if (dir == 4)
		mlx->tex.txt4_path = str;
	else if (dir == 5)
		mlx->tex.sprite_path = str;
	else if (dir == 6)
		mlx->tex.txt_floor_path = str;
	else
		ft_read_txt_rest(dir, str, mlx);
	check_txt(dir, mlx);
}

void	ft_load_music(t_mlx *mlx)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		ft_printf("Mix_OpenAudio: %s\n", Mix_GetError());
		ft_put_error("UNPLAYABLE AUDIO", mlx);
	}
	mlx->music.bg_music = Mix_LoadMUS("./sounds/music1.wav");
	mlx->music.hit_domb = Mix_LoadWAV("./sounds/hit.wav");
	mlx->music.hit_coin = Mix_LoadWAV("./sounds/coin.wav");
	Mix_PlayMusic(mlx->music.bg_music, -1);
}

void	read_resolution(char *s, t_mlx *mlx)
{
	if (mlx->screen_done)
		ft_put_error("Multiple resolution inputs\n", mlx);
	mlx->screen_done = 1;
	while (*s == ' ')
		s++;
	mlx->win.width = my_atoi(&s);
	if (*s != ' ')
		ft_put_error("Wrong resolution input\n", mlx);
	while (*s == ' ')
		s++;
	mlx->win.heigth = my_atoi(&s);
	if ((mlx->win.width < 300 || mlx->win.width > 2560))
		mlx->win.width = 2560;
	if ((mlx->win.heigth < 300 || mlx->win.heigth > 1440))
		mlx->win.heigth = 1440;
	extra_param(s, mlx, "Too many resolution inputs");
}
