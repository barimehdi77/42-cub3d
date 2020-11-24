/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 00:53:22 by mbari             #+#    #+#             */
/*   Updated: 2020/11/24 12:03:03 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	if (!(mlx->floor_done))
		ft_put_error("NO FLOOR COLOR INPUT\n", mlx);
	if (!(mlx->sky_done))
		ft_put_error("NO CEILING COLOR INPUT\n", mlx);
	if (!mlx->tex1_done || !mlx->tex2_done || !mlx->tex3_done ||
		!mlx->tex4_done || !mlx->spr_done)
		ft_put_error("MISSING TEXTURE PATH\n", mlx);
}

int		check_mapvalue(int value, int x, int y, t_mlx *mlx)
{
	if (value != '1' && value != '2' && value != '0' && value != '7')
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
		read_txt(4, str + 2, mlx);
	else if (c == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ')
		read_txt(3, str + 2, mlx);
	else if (c == 'F' && *(str + 1) == ' ')
		read_cf_color(str + 1, mlx, 'f');
	else if (c == 'C' && *(str + 1) == ' ')
		read_cf_color(str + 1, mlx, 'c');
	else if (c == 'S' && *(str + 1) == ' ')
		read_txt(5, str + 1, mlx);
	else if (c == '1' || c == '0' || c == '2')
		return (0);
	else if (c)
		ft_put_error("NON-EMPTY LINE WITH WRONG IDENTIFIER\n", mlx);
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
