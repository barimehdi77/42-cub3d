/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:40:37 by mbari             #+#    #+#             */
/*   Updated: 2020/10/30 13:13:26 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_sprite_width(t_sprtools *sprite, t_mlx *mlx)
{
	sprite->spritewidth = abs((int)(mlx->win.heigth /
		(sprite->transformy))) / sprite->udiv;
	sprite->drawstartx = -sprite->spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawstartx < 0)
		sprite->drawstartx = 0;
	sprite->drawendx = sprite->spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawendx >= mlx->win.width)
		sprite->drawendx = mlx->win.width;
}

void	check_texofhwd(int dir, t_mlx *mlx)
{
	if (dir == 10)
	{
		if (mlx->tex_heart_done)
			ft_put_error("Heart Texture set more than once\n", mlx);
		else
			mlx->tex_heart_done = 1;
	}
	else if (dir == 11)
	{
		if (mlx->tex_died_done)
			ft_put_error("Died Screen Texture set more than once\n", mlx);
		else
			mlx->tex_died_done = 1;
	}
	else if (dir == 12)
	{
		if (mlx->tex_win_done)
			ft_put_error("Win Screen Texture set more than once\n", mlx);
		else
			mlx->tex_win_done = 1;
	}
}

void	check_texofcbc(int dir, t_mlx *mlx)
{
	if (dir == 7)
	{
		if (mlx->tex_ceiling_done)
			ft_put_error("CEILING Texture set more than once\n", mlx);
		else
			mlx->tex_ceiling_done = 1;
	}
	else if (dir == 8)
	{
		if (mlx->tex_coin_done)
			ft_put_error("COIN Texture set more than once\n", mlx);
		else
			mlx->tex_coin_done = 1;
	}
	else if (dir == 9)
	{
		if (mlx->tex_bomb_done)
			ft_put_error("BOMB Texture set more than once\n", mlx);
		else
			mlx->tex_bomb_done = 1;
	}
	else
		check_texofhwd(dir, mlx);
}

void	check_restoftex(int dir, t_mlx *mlx)
{
	if (dir == 4)
	{
		if (mlx->tex4_done)
			ft_put_error("EAST Texture set more than once\n", mlx);
		else
			mlx->tex4_done = 1;
	}
	else if (dir == 5)
	{
		if (mlx->spr_done)
			ft_put_error("SPRITE Texture set more than once\n", mlx);
		else
			mlx->spr_done = 1;
	}
	else if (dir == 6)
	{
		if (mlx->tex_floor_done)
			ft_put_error("FLOOR Texture set more than once\n", mlx);
		else
			mlx->tex_floor_done = 1;
	}
	else
		check_texofcbc(dir, mlx);
}

void	check_txt(int dir, t_mlx *mlx)
{
	if (dir == 1)
	{
		if (mlx->tex1_done)
			ft_put_error("NORTH Texture set more than once\n", mlx);
		else
			mlx->tex1_done = 1;
	}
	else if (dir == 2)
	{
		if (mlx->tex2_done)
			ft_put_error("SOUTH Texture set more than once\n", mlx);
		else
			mlx->tex2_done = 1;
	}
	else if (dir == 3)
	{
		if (mlx->tex3_done)
			ft_put_error("WEST Texture set more than once\n", mlx);
		else
			mlx->tex3_done = 1;
	}
	else
		check_restoftex(dir, mlx);
}
