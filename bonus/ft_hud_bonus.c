/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:24:59 by mbari             #+#    #+#             */
/*   Updated: 2020/11/24 13:32:11 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_choose_param_rest(char c, char *str, t_mlx *mlx)
{
	if (c == 'D' && *(str + 1) == 'S' && *(str + 2) == ' ')
		read_txt(11, str + 2, mlx);
	else if (c == 'W' && *(str + 1) == 'S' && *(str + 2) == ' ')
		read_txt(12, str + 2, mlx);
	else if (c == 'N' && *(str + 1) == 'C' && *(str + 2) == ' ')
		read_txt(9, str + 2, mlx);
	else if (c == 'H' && *(str + 1) == ' ')
		read_txt(10, str + 1, mlx);
	else if (c)
		ft_put_error("NON-EMPTY LINE WITH WRONG IDENTIFIER\n", mlx);
}

void	ft_checkmap_end(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	while (x < mlx->max_x)
	{
		y = 0;
		while (y < mlx->max_y)
		{
			if (x != 0 && y != 1 && mlx->worldmap[x][y] != '1'
				&& mlx->worldmap[x][y] != '7')
				checkmap(mlx, x, y);
			y++;
		}
		x++;
	}
}

void	ft_draw_hearts(t_mlx *mlx, long int color)
{
	int x;
	int y;
	int x_win;
	int y_win;

	x = 0;
	while (x < mlx->tex.heart_w * mlx->player.hearts)
	{
		y = 0;
		x_win = x + mlx->win.width - 192;
		while (y < mlx->tex.heart_h)
		{
			y_win = y;
			color = mlx->tex.heart_data[y * mlx->tex.heart_w + x];
			if ((color & 0x00FFFFFF) != 0)
				mlx->tex.img_data[y_win * mlx->win.width + x_win] = color;
			y++;
		}
		x++;
	}
}

void	ft_print_score(t_mlx *mlx)
{
	char	*temp;

	temp = (char *)malloc(17 * sizeof(char *));
	ft_memcpy(temp, "Score: ", ft_strlen("Score: ") + 1);
	ft_strcat(temp, ft_itoa(mlx->player.score));
	ft_strcat(temp, "/");
	ft_strcat(temp, ft_itoa(mlx->player.coin));
	mlx_string_put(mlx->win.mlx_ptr, mlx->win.win_ptr, mlx->win.width
			- 150, mlx->tex.heart_h, RGB_WHITE, temp);
	free(temp);
}

void	ft_draw_hud(t_mlx *mlx)
{
	ft_minmap(mlx);
	ft_collect(mlx);
	ft_draw_hearts(mlx, 0);
}
