/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 09:07:15 by mbari             #+#    #+#             */
/*   Updated: 2020/10/17 17:19:17 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_drawspritelines(t_sprtools *sprite, t_mlx *mlx)
{
	sprite->x = sprite->drawstartx;
	while (sprite->x < sprite->drawendx)
	{
		sprite->tex_x = (int)((sprite->x - (-sprite->spritewidth / 2 +
		sprite->spritescreenx)) * mlx->tex.sp_w / sprite->spritewidth);
		sprite->y = sprite->drawstarty;
		if (sprite->transformy > 0 && sprite->x >= 0 &&
				sprite->x < mlx->win.width && sprite->transformy
					< (float)mlx->zbuffer[sprite->x])
			while (sprite->y < sprite->drawendy)
			{
				sprite->d = (sprite->y) * 256 - mlx->win.heigth * 128 +
				sprite->spriteheight * 128;
				sprite->tex_y = ((sprite->d * mlx->tex.sp_h) /
				sprite->spriteheight) / 256;
				if (*(mlx->tex.sp_data + sprite->tex_x + sprite->tex_y *
				mlx->tex.sp_sl / 4))
					*(mlx->tex.img_data + sprite->x + sprite->y *
					mlx->tex.size_line / 4) = *(mlx->tex.sp_data +
					sprite->tex_x + sprite->tex_y * mlx->tex.sp_sl / 4);
				sprite->y++;
			}
		sprite->x++;
	}
}

int		ft_count_sprotes(t_mlx *mlx)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < mlx->max_x)
	{
		j = 0;
		while (j < mlx->max_y)
		{
			if (mlx->worldmap[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_draw_square(t_mlx *mlx, int scale, int color)
{
	mlx->map.max_x = mlx->map.new_x + scale;
	while (mlx->map.new_x < mlx->map.max_x)
	{
		mlx->map.new_y = mlx->map.y * scale;
		while (mlx->map.new_y < mlx->map.max_y)
		{
			mlx->tex.img_data[mlx->map.new_x *
				mlx->win.width + mlx->map.new_y] = color;
			mlx->map.new_y++;
		}
		mlx->map.new_x++;
	}
}

int		ft_draw(t_mlx *mlx, int x)
{
	long int color;

	color = RGB_RED;
	mlx->wall.lineheight = (int)(mlx->win.heigth / mlx->ray.perpwalldist);
	mlx->wall.drawstart = -mlx->wall.lineheight / 2 + mlx->win.heigth / 2;
	if (mlx->wall.drawstart < 0)
		mlx->wall.drawstart = 0;
	mlx->wall.drawend = mlx->wall.lineheight / 2 + mlx->win.heigth / 2;
	if (mlx->wall.drawend >= mlx->win.heigth)
		mlx->wall.drawend = mlx->win.heigth - 1;
	ft_texture(mlx, x);
	return (0);
}
