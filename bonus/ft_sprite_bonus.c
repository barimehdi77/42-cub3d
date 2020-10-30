/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:26:22 by mbari             #+#    #+#             */
/*   Updated: 2020/10/30 13:17:09 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

t_sprite	*ft_get_sprite(t_mlx *mlx)
{
	t_sprite	*sprites;
	int			i;
	int			x;
	int			y;

	mlx->sprite_num = ft_count_sprotes(mlx);
	sprites = malloc(mlx->sprite_num * sizeof(t_sprite));
	mlx->sprite_order = malloc(mlx->sprite_num * sizeof(int));
	i = 0;
	x = -1;
	while (++x < mlx->max_x)
	{
		y = -1;
		while (++y < mlx->max_y)
		{
			if (mlx->worldmap[x][y] == '2' ||
				mlx->worldmap[x][y] == 'C' ||
				mlx->worldmap[x][y] == 'X')
			{
				sprites[i].x = x;
				sprites[i++].y = y;
			}
		}
	}
	return (sprites);
}

void		ft_sort_sprites(t_mlx *mlx)
{
	double	distance[mlx->sprite_num];
	int		tmp;
	int		disttmp;
	int		i;

	i = -1;
	while (++i < mlx->sprite_num)
	{
		distance[i] = ((mlx->posx - mlx->sp[i].x) * (mlx->posx -
		mlx->sp[i].x) + (mlx->posy - mlx->sp[i].y) * (mlx->posy -
		mlx->sp[i].y));
		mlx->sprite_order[i] = i;
	}
	i = -1;
	while (++i < mlx->sprite_num - 1)
		if (distance[i] < distance[i + 1])
		{
			disttmp = distance[i];
			distance[i] = distance[i + 1];
			distance[i + 1] = disttmp;
			tmp = mlx->sprite_order[i];
			mlx->sprite_order[i] = mlx->sprite_order[i + 1];
			mlx->sprite_order[i + 1] = tmp;
			i = -1;
		}
}

void		ft_sprite_height(t_sprtools *sprite, t_mlx *mlx)
{
	sprite->spriteheight = abs((int)(mlx->win.heigth /
			(sprite->transformy))) / sprite->vdiv;
	sprite->drawstarty = -sprite->spriteheight / 2 +
		mlx->win.heigth / 2 + sprite->vmovescreen;
	if (sprite->drawstarty < 0)
		sprite->drawstarty = 0;
	sprite->drawendy = sprite->spriteheight / 2 + mlx->win.heigth /
		2 + sprite->vmovescreen;
	if (sprite->drawendy >= mlx->win.heigth)
		sprite->drawendy = mlx->win.heigth;
}

void		ft_sprite_size(t_sprtools *sp, t_mlx *mlx, int i)
{
	sp->vmovescreen = (int)(sp->vmove / sp->transformy);
	sp->vdiv = VDIV;
	sp->udiv = UDIV;
	if (mlx->worldmap[(int)mlx->sp[i].x][(int)mlx->sp[i].y] == 'C')
	{
		mlx->tex.sp_data = mlx->tex.coin_data;
		mlx->tex.sp_w = mlx->tex.coin_w;
		mlx->tex.sp_h = mlx->tex.coin_h;
		mlx->tex.sp_sl = mlx->tex.coin_sl;
	}
	else if (mlx->worldmap[(int)mlx->sp[i].x][(int)mlx->sp[i].y] == 'X')
	{
		mlx->tex.sp_data = mlx->tex.bomb_data;
		mlx->tex.sp_w = mlx->tex.bomb_w;
		mlx->tex.sp_h = mlx->tex.bomb_h;
		mlx->tex.sp_sl = mlx->tex.bomb_sl;
	}
	else
		ft_spirte_resize(mlx, sp);
}

void		ft_drawsprites(t_mlx *mlx)
{
	int			i;
	t_sprite	sprite_ptr;
	t_sprtools	sprite;

	ft_sort_sprites(mlx);
	i = 0;
	while (i < mlx->sprite_num)
	{
		sprite_ptr = mlx->sp[mlx->sprite_order[i++]];
		ft_sprite_size(&sprite, mlx, mlx->sprite_order[i - 1]);
		sprite.spritex = (sprite_ptr.x + 0.5) - mlx->posx;
		sprite.spritey = (sprite_ptr.y + 0.5) - mlx->posy;
		sprite.invdet = 1.0 / (mlx->planex *
		mlx->diry - mlx->dirx * mlx->planey);
		sprite.transformx = sprite.invdet * (mlx->diry *
		sprite.spritex - mlx->dirx * sprite.spritey);
		sprite.transformy = sprite.invdet *
		(-mlx->planey * sprite.spritex + mlx->planex * sprite.spritey);
		sprite.spritescreenx = (int)((mlx->win.width / 2) *
		(1 + sprite.transformx / sprite.transformy));
		ft_sprite_height(&sprite, mlx);
		ft_sprite_width(&sprite, mlx);
		ft_drawspritelines(&sprite, mlx);
	}
}
