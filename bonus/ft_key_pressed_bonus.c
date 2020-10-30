/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_pressed_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 10:06:06 by mbari             #+#    #+#             */
/*   Updated: 2020/10/30 13:16:27 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_spirte_resize(t_mlx *mlx, t_sprtools *sp)
{
	mlx->tex.sp_data = mlx->tex.sprite_data;
	mlx->tex.sp_w = mlx->tex.sprite_w;
	mlx->tex.sp_h = mlx->tex.sprite_h;
	mlx->tex.sp_sl = mlx->tex.sprite_sl;
	sp->vmovescreen = 0;
	sp->vdiv = 1;
	sp->udiv = 1;
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

int		key_pressed(int key, t_mlx *mlx)
{
	if (key == 53)
		ft_put_error("The game is closed", mlx);
	if (key == 13)
		mlx->forward = 1;
	if (key == 1)
		mlx->backward = 1;
	if (key == 0)
		mlx->left = 1;
	if (key == 2)
		mlx->right = 1;
	if (key == 123)
		mlx->rotleft = 1;
	if (key == 124)
		mlx->rotright = 1;
	return (0);
}

int		key_released(int key, t_mlx *mlx)
{
	if (key == 13)
		mlx->forward = 0;
	if (key == 1)
		mlx->backward = 0;
	if (key == 0)
		mlx->left = 0;
	if (key == 2)
		mlx->right = 0;
	if (key == 123)
		mlx->rotleft = 0;
	if (key == 124)
		mlx->rotright = 0;
	return (0);
}
