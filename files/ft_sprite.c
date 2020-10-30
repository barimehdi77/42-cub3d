/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:26:22 by mbari             #+#    #+#             */
/*   Updated: 2020/10/17 13:14:09 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	x = 0;
	while (x < mlx->max_x)
	{
		y = 0;
		while (y < mlx->max_y)
		{
			if (mlx->worldmap[x][y] == '2')
			{
				sprites[i].x = x;
				sprites[i++].y = y;
			}
			y++;
		}
		x++;
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
	sprite->spriteheight = abs((int)(mlx->win.heigth / (sprite->transformy)));
	sprite->drawstarty = -sprite->spriteheight / 2 + mlx->win.heigth / 2;
	if (sprite->drawstarty < 0)
		sprite->drawstarty = 0;
	sprite->drawendy = sprite->spriteheight / 2 + mlx->win.heigth / 2;
	if (sprite->drawendy >= mlx->win.heigth)
		sprite->drawendy = mlx->win.heigth;
}

void		ft_sprite_width(t_sprtools *sprite, t_mlx *mlx)
{
	sprite->spritewidth = abs((int)(mlx->win.heigth / (sprite->transformy)));
	sprite->drawstartx = -sprite->spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawstartx < 0)
		sprite->drawstartx = 0;
	sprite->drawendx = sprite->spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawendx >= mlx->win.width)
		sprite->drawendx = mlx->win.width;
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
