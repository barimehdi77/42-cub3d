/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 00:53:22 by mbari             #+#    #+#             */
/*   Updated: 2020/11/24 13:55:30 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	extra_param(char *str, t_mlx *mlx, char *message)
{
	while (*str <= '9' && *str >= '0')
		str++;
	while (*str == ' ')
		str++;
	if (*str)
		ft_put_error(message, mlx);
}

void	verify_params(t_mlx *mlx)
{
	if (!(mlx->screen_done))
		ft_put_error("NO RESOLUTION INPUT\n", mlx);
	if (!(mlx->tex_floor_done))
		ft_put_error("NO FLOOR TEXTURE\n", mlx);
	if (!(mlx->tex_ceiling_done))
		ft_put_error("NO CEILING TEXTURE\n", mlx);
	if (!mlx->tex1_done || !mlx->tex2_done || !mlx->tex3_done ||
		!mlx->tex4_done || !mlx->spr_done)
		ft_put_error("WALL TEXTURE PATH IS MISSING\n", mlx);
	if (!mlx->tex_died_done || !mlx->tex_win_done ||
				!mlx->tex_heart_done)
		ft_put_error("SOME TEXTURES ARE MISSING\n", mlx);
	if (!mlx->tex_bomb_done || !mlx->tex_coin_done)
		ft_put_error("THE OBJECTS OR TRAPS TEXTURES ARE MISSING\n", mlx);
}

int		check_mapvalue(char value, int x, int y, t_mlx *mlx)
{
	if (value != '1' && value != '2' && value != '0'
		&& value != '7' && value != 'C' && value != 'X')
	{
		player_init(x, y, value, mlx);
		return (1);
	}
	return (0);
}

int		choose_param(char c, char *str, t_mlx *mlx)
{
	while (*str == ' ')
		str++;
	if (c == 'R' && *(str + 1) == ' ')
		read_resolution(str + 1, mlx);
	else if (c == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ')
		read_txt(1, str + 2, mlx);
	else if (c == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ')
		read_txt(2, str + 2, mlx);
	else if (c == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ')
		read_txt(3, str + 2, mlx);
	else if (c == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ')
		read_txt(4, str + 2, mlx);
	else if (c == 'S' && *(str + 1) == ' ')
		read_txt(5, str + 1, mlx);
	else if (c == 'F' && *(str + 1) == 'T' && *(str + 2) == ' ')
		read_txt(6, str + 2, mlx);
	else if (c == 'C' && *(str + 1) == 'T' && *(str + 2) == ' ')
		read_txt(7, str + 2, mlx);
	else if (c == 'C' && *(str + 1) == 'O' && *(str + 2) == ' ')
		read_txt(8, str + 2, mlx);
	else if (c == '1' || c == '0' || c == '2')
		return (0);
	else
		ft_choose_param_rest(c, str, mlx);
	return (1);
}

void	check_player(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	mlx->player_pos = 0;
	while (i <= mlx->max_x)
	{
		j = 0;
		while (j <= mlx->max_y)
		{
			mlx->player_pos += check_mapvalue(mlx->worldmap[i][j], i, j, mlx);
			j++;
		}
		i++;
	}
	if (mlx->player_pos == 0)
		ft_put_error("NO SPAWNPOINT\n", mlx);
}
