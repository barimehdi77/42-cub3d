/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 01:45:06 by mbari             #+#    #+#             */
/*   Updated: 2020/10/17 13:15:04 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	choose_texture(t_mlx *mlx, t_ray *ray)
{
	if (ray->walldir == 'N')
	{
		mlx->tex.xpm_data = mlx->tex.txt1_data;
		mlx->tex.txt_w = mlx->tex.txt1_w;
		mlx->tex.txt_h = mlx->tex.txt1_h;
	}
	else if (ray->walldir == 'S')
	{
		mlx->tex.xpm_data = mlx->tex.txt2_data;
		mlx->tex.txt_w = mlx->tex.txt2_w;
		mlx->tex.txt_h = mlx->tex.txt2_h;
	}
	else if (ray->walldir == 'E')
	{
		mlx->tex.xpm_data = mlx->tex.txt3_data;
		mlx->tex.txt_w = mlx->tex.txt3_w;
		mlx->tex.txt_h = mlx->tex.txt3_h;
	}
	else if (ray->walldir == 'W')
	{
		mlx->tex.xpm_data = mlx->tex.txt4_data;
		mlx->tex.txt_h = mlx->tex.txt4_h;
		mlx->tex.txt_w = mlx->tex.txt4_w;
	}
}

void	ft_texput(t_mlx *mlx)
{
	mlx->tex.txt1 = mlx_xpm_file_to_image(mlx->win.mlx_ptr,
		mlx->tex.txt1_path, &mlx->tex.txt1_w, &mlx->tex.txt1_h);
	mlx->tex.txt1_data = (int *)mlx_get_data_addr(mlx->tex.txt1,
		&mlx->tex.txt1_bp, &mlx->tex.txt1_sl, &mlx->tex.txt1_end);
	mlx->tex.txt2 = mlx_xpm_file_to_image(mlx->win.mlx_ptr,
		mlx->tex.txt2_path, &mlx->tex.txt2_w, &mlx->tex.txt2_h);
	mlx->tex.txt2_data = (int *)mlx_get_data_addr(mlx->tex.txt2,
		&mlx->tex.txt2_bp, &mlx->tex.txt2_sl, &mlx->tex.txt2_end);
	mlx->tex.txt3 = mlx_xpm_file_to_image(mlx->win.mlx_ptr,
		mlx->tex.txt3_path, &mlx->tex.txt3_w, &mlx->tex.txt3_h);
	mlx->tex.txt3_data = (int *)mlx_get_data_addr(mlx->tex.txt3,
		&mlx->tex.txt3_bp, &mlx->tex.txt3_sl, &mlx->tex.txt3_end);
	mlx->tex.txt4 = mlx_xpm_file_to_image(mlx->win.mlx_ptr,
		mlx->tex.txt4_path, &mlx->tex.txt4_w, &mlx->tex.txt4_h);
	mlx->tex.txt4_data = (int *)mlx_get_data_addr(mlx->tex.txt4,
		&mlx->tex.txt4_bp, &mlx->tex.txt4_sl, &mlx->tex.txt4_end);
	mlx->tex.sp = mlx_xpm_file_to_image(mlx->win.mlx_ptr,
		mlx->tex.sp_path, &mlx->tex.sp_w, &mlx->tex.sp_h);
	mlx->tex.sp_data = (int *)mlx_get_data_addr(mlx->tex.sp,
		&mlx->tex.sp_bp, &mlx->tex.sp_sl, &mlx->tex.sp_end);
}

void	ft_put_tex_to_image(t_mlx *mlx, int y1, int y2, int x)
{
	long int color;

	color = 0;
	while (y1 < y2)
	{
		mlx->tex.y = (int)mlx->tex.pos & (mlx->tex.txt_h - 1);
		mlx->tex.pos += mlx->tex.step;
		color = mlx->tex.xpm_data[mlx->tex.txt_h * mlx->tex.y + mlx->tex.x];
		if (mlx->ray.side == 1)
			color = (color >> 1) & 8355711;
		mlx->tex.img_data[y1 * mlx->win.width + x] = color;
		y1++;
	}
}

void	ft_getside(t_mlx *mlx)
{
	if (mlx->ray.side == 0)
	{
		if (mlx->ray.raydirx > 0)
			mlx->ray.walldir = 'N';
		else
			mlx->ray.walldir = 'S';
		mlx->tex.x = mlx->tex.txt_w - mlx->tex.x - 1;
	}
	if (mlx->ray.side == 1)
	{
		if (mlx->ray.raydiry > 0)
			mlx->ray.walldir = 'W';
		else
			mlx->ray.walldir = 'E';
		mlx->tex.x = mlx->tex.txt_w - mlx->tex.x - 1;
	}
}

void	ft_texture(t_mlx *mlx, int x)
{
	mlx->tex.num = mlx->worldmap[mlx->ray.mapx][mlx->ray.mapy] - 1;
	if (mlx->ray.side == 0)
		mlx->tex.wallx = mlx->posy + mlx->ray.perpwalldist * mlx->ray.raydiry;
	else
		mlx->tex.wallx = mlx->posx + mlx->ray.perpwalldist * mlx->ray.raydirx;
	ft_getside(mlx);
	mlx->tex.wallx -= floor((mlx->tex.wallx));
	mlx->tex.x = (int)(mlx->tex.wallx * (double)(mlx->tex.txt_w));
	mlx->tex.step = 1.0 * mlx->tex.txt_h / mlx->wall.lineheight;
	mlx->tex.pos = (mlx->wall.drawstart - mlx->win.heigth / 2 +
				mlx->wall.lineheight / 2) * mlx->tex.step;
	choose_texture(mlx, &mlx->ray);
	ft_put_tex_to_image(mlx, mlx->wall.drawstart, mlx->wall.drawend, x);
}
