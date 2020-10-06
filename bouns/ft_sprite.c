/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:26:22 by mbari             #+#    #+#             */
/*   Updated: 2020/10/06 00:58:02 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int  count_sprotes(t_mlx *mlx)
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
            if(mlx->worldmap[i][j] == '2')
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

t_sprite *get_sprite(t_mlx *mlx)
{
    t_sprite *sprites;
    int i;
    int x;
    int y;
    
    mlx->sprite_num = count_sprotes(mlx);
    sprites = malloc(mlx->sprite_num * sizeof(t_sprite));
    mlx->sprite_order = malloc(mlx->sprite_num * sizeof(int));
    i = 0;
    x = 0;
    while (x < mlx->max_x)
    {
        y = 0;
        while (y < mlx->max_y)
        {
            if(mlx->worldmap[x][y] == '2')
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


void	sort_sprites(t_mlx *mlx)
{
	double		distance[mlx->sprite_num];
	int			tmp;
	int			disttmp;
	int			i;

	i = -1;
	while (++i < mlx->sprite_num)
	{
		distance[i] = ((mlx->posX - mlx->sp[i].x) * (mlx->posX -
		mlx->sp[i].x) + (mlx->posY - mlx->sp[i].y) * (mlx->posY -
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

void	sprite_height(t_sprtools *sprite, t_mlx *mlx)
{
	sprite->spriteheight = abs((int)(h / (sprite->transformy)));
	sprite->drawstarty = -sprite->spriteheight / 2 + h / 2;
	if (sprite->drawstarty < 0)
		sprite->drawstarty = 0;
	sprite->drawendy = sprite->spriteheight / 2 + h / 2;
	if (sprite->drawendy >= h)
		sprite->drawendy = h;
}

void	sprite_width(t_sprtools *sprite, t_mlx *mlx)
{
	sprite->spritewidth = abs((int)(h / (sprite->transformy)));
	sprite->drawstartx = -sprite->spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawstartx < 0)
		sprite->drawstartx = 0;
	sprite->drawendx = sprite->spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawendx >= w)
		sprite->drawendx = w;
}

void	drawspritelines(t_sprtools *sprite, t_mlx *mlx, t_ray *ray)
{
	sprite->x = sprite->drawstartx;
	while (sprite->x < sprite->drawendx)
	{
		sprite->tex_x = (int)((sprite->x - (-sprite->spritewidth / 2 +
		sprite->spritescreenx)) * mlx->tex.sp_w / sprite->spritewidth);
		sprite->y = sprite->drawstarty;
		if (sprite->transformy > 0 && sprite->x >= 0 &&
		sprite->x < w && sprite->transformy < (float)mlx->zbuffer[sprite->x])
			while (sprite->y < sprite->drawendy)
			{
				sprite->d = (sprite->y) * 256 - h * 128 +
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

void	drawsprites(t_mlx *mlx, t_ray *ray)
{
	int			i;
	t_sprite	sprite_ptr;
	t_sprtools	sprite;

	sort_sprites(mlx);
	i = 0;
	while (i < mlx->sprite_num)
	{
		sprite_ptr = mlx->sp[mlx->sprite_order[i++]];
		sprite.spritex = (sprite_ptr.x + 0.5) - mlx->posX;
		sprite.spritey = (sprite_ptr.y + 0.5) - mlx->posY;
		sprite.invdet = 1.0 / (mlx->planeX *
		mlx->dirY - mlx->dirX * mlx->planeY);
		sprite.transformx = sprite.invdet * (mlx->dirY *
		sprite.spritex - mlx->dirX * sprite.spritey);
		sprite.transformy = sprite.invdet *
		(-mlx->planeY * sprite.spritex + mlx->planeX * sprite.spritey);
		sprite.spritescreenx = (int)((w / 2) *
		(1 + sprite.transformx / sprite.transformy));
		sprite_height(&sprite, mlx);
		sprite_width(&sprite, mlx);
		drawspritelines(&sprite, mlx, ray);
	}
}

/*void ft_sprite(t_mlx *mlx, double *zbuffer)
{
    double spriteX = mlx->sp->x - mlx->posX;
    double spriteY = mlx->sp->y - mlx->posY;
    //printf("|%f|\n|%f|",mlx->sp.x,mlx->sp.y);
    double invDet = 1.0 / (mlx->planeX * mlx->dirY - mlx->dirX * mlx->planeY); //required for correct matrix multiplication

    double transformX = invDet * (mlx->dirY * spriteX - mlx->dirX * spriteY);
    double transformY = invDet * (-mlx->planeY * spriteX + mlx->planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

    int spriteScreenX = (int)((w / 2) * (1 + transformX / transformY));

    //calculate height of the sprite on screen
    int spriteHeight = abs((int)(h / transformY)); //using 'transformY' instead of the real distance prevents fisheye
    //calculate lowest and highest pixel to fill in current stripe
    int drawStartY = -spriteHeight / 2 + h / 2;
    if(drawStartY < 0) drawStartY = 0;
    int drawEndY = spriteHeight / 2 + h / 2;
    if(drawEndY >= h) drawEndY = h - 1;

    //calculate width of the sprite
    int spriteWidth = abs((int)(h / transformY));
    int drawStartX = -spriteWidth / 2 + spriteScreenX;
    if(drawStartX < 0) drawStartX = 0;
    int drawEndX = spriteWidth / 2 + spriteScreenX;
    if(drawEndX >= w) drawEndX = w - 1;
    for(int stripe = drawStartX; stripe < drawEndX; stripe++)
    {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) it's on the screen (left)
        //3) it's on the screen (right)
        //4) ZBuffer, with perpendicular distance
        if(transformY > 0 && stripe > 0 && stripe < w && transformY < zbuffer[stripe])
             for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
            {
                int d = (y) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
                int texY = ((d * texHeight) / spriteHeight) / 256;
                //long int color = mlx->tex.xpm_data[texWidth * mlx->tex.y + mlx->tex.x]; //get current color from the texture
                long int color = mlx->tex.sp_data[texWidth * texY + texX];
                if((color & 0x00FFFFFF) != 0) 
                    mlx->tex.img_data[y * w + stripe] = color; //paint pixel if it isn't black, black is the invisible color
            }
    }
}*/