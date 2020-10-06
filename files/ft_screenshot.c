/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 00:57:55 by mbari             #+#    #+#             */
/*   Updated: 2020/10/06 01:34:41 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../includes/cub3d.h"

void screen_shot(t_mlx *mlx)
{
    //ft_loop(mlx);
    ft_move(mlx);
    ft_update2(mlx);
    screno(mlx);
}
 
void    screno(t_mlx *mlx)
{
    //width, height, and bitcount are the key factors:
    int32_t width = w;
    int32_t height = h;
    uint16_t bitcount = 24;//<- 24-bit bitmap
 
    //take padding in to account
    int width_in_bytes = ((width * bitcount + 31) / 32) * 4;
 
    //total image size in bytes, not including header
    uint32_t imagesize = width_in_bytes * height;
 
    //this value is always 40, it's the sizeof(BITMAPINFOHEADER)
    const uint32_t biSize = 40;
 
    //bitmap bits start after headerfile, 
    //this is sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
    const uint32_t bfOffBits = 54; 
 
    //total file size:
    uint32_t filesize = 54 + imagesize;
 
    //number of planes is usually 1
    const uint16_t biPlanes = 1;
    //create header:
    //copy to buffer instead of BITMAPFILEHEADER and BITMAPINFOHEADER
    //to avoid problems with structure packing
    unsigned char header[54] = { 0 };
    memcpy(header, "BM", 2);
    memcpy(header + 2 , &filesize, 4);
    memcpy(header + 10, &bfOffBits, 4);
    memcpy(header + 14, &biSize, 4);
    memcpy(header + 18, &width, 4);
    memcpy(header + 22, &height, 4);
    memcpy(header + 26, &biPlanes, 2);
    memcpy(header + 28, &bitcount, 2);
    memcpy(header + 34, &imagesize, 4);
 
    /////////////////////////
    ///yow yow this is new///
    int x = 0;
    int y = 0;
    /////////////////////////
    //prepare pixel data:
    unsigned char* buf = malloc(imagesize);
    for(int row = height - 1; row >= 0; row--)
    {
        y = 0;
        for(int col = 0; col < width; col++)
        {
            //buf[row * width_in_bytes + col * 3 + 0] = 255;//blue
            //buf[row * width_in_bytes + col * 3 + 1] = 0;//green
            //buf[row * width_in_bytes + col * 3 + 2] = 0;//red
            int red = (mlx->tex.img_data[x * w + y] >> 16) & 0xFF;
            int green = (mlx->tex.img_data[x * w + y] >> 8) & 0xFF;
            int blue = mlx->tex.img_data[x * w + y] & 0xFF;
 
 
            buf[row * width_in_bytes + col * 3 + 0] = blue;
            buf[row * width_in_bytes + col * 3 + 1] = green;
            buf[row * width_in_bytes + col * 3 + 2] = red;
            y++;
        }
        x++;
    }
    ft_printf("Taking ScreenShoot....\n");
    FILE *fout = fopen("screenshot.bmp", "wb");
    ft_printf("ScreenShot Has been saved under The name 'screenshot.bmp'.]\n");
    fwrite(header, 1, 54, fout);
    fwrite((char*)buf, 1, imagesize, fout);
    fclose(fout);
    free(buf);
    //return(1);
}