/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:58:18 by mbari             #+#    #+#             */
/*   Updated: 2020/11/24 13:56:54 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	else if (dir == 4 || dir == 5)
		check_restoftex(dir, mlx);
}

void	read_txt(int dir, char *str, t_mlx *mlx)
{
	int fd;

	while (*str == ' ')
		str++;
	if ((fd = open(str, O_RDONLY)) < 0)
		ft_put_error("WRONG TEXTURE PATH INPUT\n", mlx);
	close(fd);
	if (dir == 1)
		mlx->tex.txt1_path = str;
	else if (dir == 2)
		mlx->tex.txt2_path = str;
	else if (dir == 3)
		mlx->tex.txt3_path = str;
	else if (dir == 4)
		mlx->tex.txt4_path = str;
	else if (dir == 5)
		mlx->tex.sp_path = str;
	check_txt(dir, mlx);
}

void	read_resolution(char *s, t_mlx *mlx)
{
	if (mlx->screen_done)
		ft_put_error("Multiple resolution inputs\n", mlx);
	mlx->screen_done = 1;
	while (*s == ' ')
		s++;
	mlx->win.width = my_atoi(&s);
	if (*s != ' ')
		ft_put_error("Wrong resolution input\n", mlx);
	while (*s == ' ')
		s++;
	mlx->win.heigth = my_atoi(&s);
	if ((mlx->win.width <= 0 || mlx->win.width > 2560))
		mlx->win.width = 2560;
	if ((mlx->win.heigth <= 0 || mlx->win.heigth > 1440))
		mlx->win.heigth = 1440;
	extra_param(s, mlx, "Too many resolution inputs");
}

void	ft_isfloor(char *s, t_mlx *mlx, char type, int color)
{
	if (type == 'f')
	{
		extra_param(s, mlx, "Too many Floor rgb inputs");
		mlx->floor_color = color;
		if (mlx->floor_color < 0)
			ft_put_error("Wrong values for floor color\n", mlx);
		mlx->floor_done = 1;
	}
	else if (type == 'c')
	{
		extra_param(s, mlx, "Too many ceiling rgb inputs");
		mlx->sky_color = color;
		if (mlx->floor_color < 0)
			ft_put_error("Wrong values for ceiling color\n", mlx);
		mlx->sky_done = 1;
	}
}

void	read_cf_color(char *s, t_mlx *mlx, char type)
{
	int			color;
	int			i;

	i = 3;
	color = 0;
	if (mlx->floor_done && type == 'f')
		ft_put_error("Multiple floor color inputs\n", mlx);
	if (mlx->sky_done && type == 'c')
		ft_put_error("Multiple ceiling color inputs\n", mlx);
	while (i > 0)
	{
		while (*s == ' ')
			s++;
		color = color * 256 + my_atoi(&s);
		while (*s == ' ')
			s++;
		if (*(s++) != ',' && i > 1)
			ft_put_error("Wrong floor color input\n", mlx);
		i--;
	}
	ft_isfloor(--s, mlx, type, color);
}
