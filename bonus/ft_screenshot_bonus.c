/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 00:57:55 by mbari             #+#    #+#             */
/*   Updated: 2020/11/17 14:06:39 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void				ft_takescreen(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr,
				mlx->tex.img_ptr, 0, 0);
	mlx_destroy_image(mlx->win.mlx_ptr, mlx->tex.img_ptr);
}

t_screenshot		*ft_init_shot(t_mlx *mlx)
{
	t_screenshot	*takeshot;

	takeshot = malloc(1 * sizeof(t_screenshot));
	takeshot->width = mlx->win.width;
	takeshot->height = mlx->win.heigth;
	takeshot->bitcount = 24;
	takeshot->blue = 255;
	takeshot->green = 0;
	takeshot->red = 0;
	takeshot->width_in_bytes = ((takeshot->width *
			takeshot->bitcount + 31) / 32) * 4;
	takeshot->imagesize = takeshot->width_in_bytes * takeshot->height;
	takeshot->buf = malloc(takeshot->imagesize);
	return (takeshot);
}

void				ft_screen_shot(t_mlx *mlx)
{
	if (sizeof(t_bitmapheader) != 14 && sizeof(t_bitmapinfo) != 40)
	{
		ft_put_error("bitmap structures not packed properly\n", mlx);
		return ;
	}
	ft_update(mlx, YES);
	mlx->shot = ft_init_shot(mlx);
	ft_printf("[Taking ScreenShoot....]\n");
	ft_screno(mlx);
	ft_printf("ScreenShot Has been saved under The name 'screenshot.bmp'.\n");
	close_game(mlx);
}

void				ft_fill_image(t_mlx *mlx, unsigned char *buf)
{
	int x;
	int col;
	int row;

	row = mlx->shot->height;
	x = 0;
	while (--row >= 0)
	{
		col = -1;
		while (++col < mlx->shot->width)
		{
			mlx->shot->red = (mlx->tex.img_data[x *
					mlx->win.width + col] >> 16) & 0xFF;
			mlx->shot->green = (mlx->tex.img_data[x *
					mlx->win.width + col] >> 8) & 0xFF;
			mlx->shot->blue = mlx->tex.img_data[x *
					mlx->win.width + col] & 0xFF;
			buf[row * mlx->shot->width_in_bytes +
					col * 3 + 0] = mlx->shot->blue;
			buf[row * mlx->shot->width_in_bytes +
					col * 3 + 1] = mlx->shot->green;
			buf[row * mlx->shot->width_in_bytes + col * 3 + 2] = mlx->shot->red;
		}
		x++;
	}
}

void				ft_screno(t_mlx *mlx)
{
	FILE			*image;
	t_bitmapheader	filehdr;
	t_bitmapinfo	infohdr;

	filehdr = (t_bitmapheader){ 0 };
	infohdr = (t_bitmapinfo){ 0 };
	image = fopen("screenshot.bmp", "wb");
	memcpy(&filehdr, "BM", 2);
	filehdr.bfsize = 54 + mlx->shot->imagesize;
	filehdr.bfoffbits = 54;
	infohdr.bisize = 40;
	infohdr.biplanes = 1;
	infohdr.biwidth = mlx->shot->width;
	infohdr.biheight = mlx->shot->height;
	infohdr.bibitcount = mlx->shot->bitcount;
	infohdr.bisizeimage = mlx->shot->imagesize;
	ft_fill_image(mlx, mlx->shot->buf);
	fwrite(&filehdr, sizeof(filehdr), 1, image);
	fwrite(&infohdr, sizeof(infohdr), 1, image);
	fwrite((char*)mlx->shot->buf, 1, mlx->shot->imagesize, image);
	fclose(image);
	free(mlx->shot->buf);
}
