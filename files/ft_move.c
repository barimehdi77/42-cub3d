/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 10:08:28 by mbari             #+#    #+#             */
/*   Updated: 2020/10/21 09:53:49 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_rotleft(t_mlx *mlx, double oldplanex, double olddirx)
{
	mlx->dirx = mlx->dirx * cos(mlx->rotspeed)
			- mlx->diry * sin(mlx->rotspeed);
	mlx->diry = olddirx * sin(mlx->rotspeed)
			+ mlx->diry * cos(mlx->rotspeed);
	mlx->planex = mlx->planex * cos(mlx->rotspeed)
			- mlx->planey * sin(mlx->rotspeed);
	mlx->planey = oldplanex * sin(mlx->rotspeed)
			+ mlx->planey * cos(mlx->rotspeed);
}

void	ft_rotate(t_mlx *mlx)
{
	double oldplanex;
	double olddirx;

	oldplanex = mlx->planex;
	olddirx = mlx->dirx;
	if (mlx->rotright)
	{
		mlx->dirx = mlx->dirx * cos(-mlx->rotspeed)
				- mlx->diry * sin(-mlx->rotspeed);
		mlx->diry = olddirx * sin(-mlx->rotspeed)
				+ mlx->diry * cos(-mlx->rotspeed);
		mlx->planex = mlx->planex * cos(-mlx->rotspeed)
				- mlx->planey * sin(-mlx->rotspeed);
		mlx->planey = oldplanex * sin(-mlx->rotspeed)
				+ mlx->planey * cos(-mlx->rotspeed);
	}
	if (mlx->rotleft)
		ft_rotleft(mlx, oldplanex, olddirx);
}

int		can_move(char pos)
{
	if (pos == '1' || pos == '2')
		return (0);
	return (1);
}

void	ft_moverightleft(t_mlx *mlx)
{
	if (mlx->left)
	{
		if (can_move(mlx->worldmap[(int)(mlx->posx)][(int)(mlx->posy +
				mlx->dirx * mlx->movespeed)]))
			mlx->posy += mlx->dirx * mlx->movespeed * 0.5;
		if (can_move(mlx->worldmap[(int)(mlx->posx -
				mlx->diry * mlx->movespeed)][(int)(mlx->posy)]))
			mlx->posx -= mlx->diry * mlx->movespeed * 0.5;
	}
	if (mlx->right)
	{
		if (can_move(mlx->worldmap[(int)(mlx->posx)][(int)(mlx->posy
				- mlx->dirx * mlx->movespeed)]))
			mlx->posy -= mlx->dirx * mlx->movespeed * 0.5;
		if (can_move(mlx->worldmap[(int)(mlx->posx + mlx->diry
				* mlx->movespeed)][(int)(mlx->posy)]))
			mlx->posx += mlx->diry * mlx->movespeed * 0.5;
	}
}

int		ft_move(t_mlx *mlx)
{
	if (mlx->forward)
	{
		if (can_move(mlx->worldmap[(int)(mlx->posx +
				mlx->dirx * mlx->movespeed)][(int)(mlx->posy)]))
			mlx->posx += mlx->dirx * mlx->movespeed * 0.5;
		if (can_move(mlx->worldmap[(int)(mlx->posx)][(int)(mlx->posy
				+ mlx->diry * mlx->movespeed)]))
			mlx->posy += mlx->diry * mlx->movespeed * 0.5;
	}
	if (mlx->backward)
	{
		if (can_move(mlx->worldmap[(int)(mlx->posx -
				mlx->dirx * mlx->movespeed)][(int)(mlx->posy)]))
			mlx->posx -= mlx->dirx * mlx->movespeed * 0.5;
		if (can_move(mlx->worldmap[(int)(mlx->posx)][(int)(mlx->posy
				- mlx->diry * mlx->movespeed)]))
			mlx->posy -= mlx->diry * mlx->movespeed * 0.5;
	}
	if (mlx->right || mlx->left)
		ft_moverightleft(mlx);
	if (mlx->rotleft || mlx->rotright)
		ft_rotate(mlx);
	return (0);
}
