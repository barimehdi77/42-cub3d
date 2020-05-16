/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_pressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:04:49 by mbari             #+#    #+#             */
/*   Updated: 2020/05/16 02:03:46 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_pressed(int key, t_mlx *mlx)
{
    if (key == 65307)
	    mlx_destroy_window(mlx->win.mlx_ptr, mlx->win.win_ptr);
    if (key == 119)
        mlx->forward = 1;
    if (key == 115)
        mlx->backward = 1;
    if (key == 97)
        mlx->left = 1;
    if (key == 100)
        mlx->right = 1;
    if (key == 65361)
        mlx->rotleft = 1;
    if (key == 65363)
        mlx->rotright = 1;
	return (0);
}

int key_released(int key, t_mlx *mlx)
{
    //ft_putnbr(key);
    if (key == 119)
        mlx->forward = 0;
    if (key == 115)
        mlx->backward = 0;
    if (key == 97)
        mlx->left = 0;
    if (key == 100)
        mlx->right = 0;
    if (key == 65361)
        mlx->rotleft = 0;
    if (key == 65363)
        mlx->rotright = 0;
	return (0);
}