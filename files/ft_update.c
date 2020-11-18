/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:02:42 by mbari             #+#    #+#             */
/*   Updated: 2020/11/17 12:52:14 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_steps_y(t_mlx *mlx)
{
	if (mlx->ray.raydiry < 0)
	{
		mlx->ray.stepy = -1;
		mlx->ray.sidedisty = (mlx->posy - mlx->ray.mapy) * mlx->ray.deltadisty;
	}
	else
	{
		mlx->ray.stepy = 1;
		mlx->ray.sidedisty = (mlx->ray.mapy + 1.0 -
				mlx->posy) * mlx->ray.deltadisty;
	}
}

void	ft_steps(t_mlx *mlx, int x)
{
	double camirax;

	camirax = 2 * x / (double)mlx->win.width - 1;
	mlx->ray.raydirx = mlx->dirx + mlx->planex * camirax;
	mlx->ray.raydiry = mlx->diry + mlx->planey * camirax;
	mlx->ray.mapx = mlx->posx;
	mlx->ray.mapy = mlx->posy;
	mlx->ray.deltadistx = fabs(1 / mlx->ray.raydirx);
	mlx->ray.deltadisty = fabs(1 / mlx->ray.raydiry);
	mlx->ray.hit = 0;
	if (mlx->ray.raydirx < 0)
	{
		mlx->ray.stepx = -1;
		mlx->ray.sidedistx = (mlx->posx - mlx->ray.mapx) * mlx->ray.deltadistx;
	}
	else
	{
		mlx->ray.stepx = 1;
		mlx->ray.sidedistx = (mlx->ray.mapx + 1.0 -
				mlx->posx) * mlx->ray.deltadistx;
	}
	ft_steps_y(mlx);
}

void	ft_wallhit(t_mlx *mlx)
{
	while (mlx->ray.hit == 0)
	{
		if (mlx->ray.sidedistx < mlx->ray.sidedisty)
		{
			mlx->ray.sidedistx += mlx->ray.deltadistx;
			mlx->ray.mapx += mlx->ray.stepx;
			mlx->ray.side = 0;
		}
		else
		{
			mlx->ray.sidedisty += mlx->ray.deltadisty;
			mlx->ray.mapy += mlx->ray.stepy;
			mlx->ray.side = 1;
		}
		if (mlx->worldmap[mlx->ray.mapx][mlx->ray.mapy] == '1')
			mlx->ray.hit = 1;
	}
}

void	ft_wallside(t_mlx *mlx, int x)
{
	if (mlx->ray.side == 0)
		mlx->ray.perpwalldist = (mlx->ray.mapx - mlx->posx +
				(1 - mlx->ray.stepx) / 2) / mlx->ray.raydirx;
	else
		mlx->ray.perpwalldist = (mlx->ray.mapy - mlx->posy +
			(1 - mlx->ray.stepy) / 2) / mlx->ray.raydiry;
	mlx->zbuffer[x] = mlx->ray.perpwalldist;
}

int		ft_update(t_mlx *mlx, int screenshot)
{
	int x;

	x = -1;
	mlx->tex.img_ptr = mlx_new_image(mlx->win.mlx_ptr,
			mlx->win.width, mlx->win.heigth);
	mlx->tex.img_data = (int *)mlx_get_data_addr(mlx->tex.img_ptr,
			&mlx->tex.bpp, &mlx->tex.size_line, &mlx->tex.endian);
	ft_draw_floorsky(mlx);
	mlx->zbuffer = malloc(sizeof(double) * mlx->win.width + 1);
	while (x++ < mlx->win.width)
	{
		ft_steps(mlx, x);
		ft_wallhit(mlx);
		ft_wallside(mlx, x);
		ft_draw(mlx, x);
	}
	ft_drawsprites(mlx);
	free(mlx->zbuffer);
	if (screenshot == NO)
	{
		mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr,
				mlx->tex.img_ptr, 0, 0);
		mlx_destroy_image(mlx->win.mlx_ptr, mlx->tex.img_ptr);
	}
	return (0);
}
