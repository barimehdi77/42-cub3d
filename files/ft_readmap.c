/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 17:03:00 by mbari             #+#    #+#             */
/*   Updated: 2020/11/24 13:11:54 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**get_filelines(char **lines, char **tmp, int fd)
{
	char	*s;
	int		i;
	int		j;
	int		ret;

	ret = 1;
	i = 1;
	while (ret)
	{
		ret = get_next_line(fd, &s);
		tmp = lines;
		j = 0;
		lines = malloc((i + 1) * sizeof(char *));
		if (tmp)
			while (tmp[j])
			{
				lines[j] = tmp[j];
				j++;
			}
		free(tmp);
		lines[j++] = s;
		lines[j] = 0;
		i++;
	}
	return (lines);
}

void	check_restoftex(int dir, t_mlx *mlx)
{
	if (dir == 4)
	{
		if (mlx->tex4_done)
			ft_put_error("EAST Texture set more than once\n", mlx);
		else
			mlx->tex4_done = 1;
	}
	else if (dir == 5)
	{
		if (mlx->spr_done)
			ft_put_error("SPRITE Texture set more than once\n", mlx);
		else
			mlx->spr_done = 1;
	}
}

char	**parse_parameters(t_mlx *mlx, char **lines)
{
	int i;
	int j;
	int map;

	i = 0;
	map = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j] == ' ')
			j++;
		if (!choose_param(lines[i][j], lines[i], mlx))
		{
			return (&lines[i]);
		}
		i++;
	}
	ft_put_error("NO MAP FOUND\n", mlx);
	return (lines);
}

void	make_map(char **lines, t_mlx *mlx)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		last_y;

	x = 0;
	i = -1;
	last_y = 0;
	while (lines[++i])
	{
		y = 0;
		j = 0;
		while (lines[i][j])
		{
			while (lines[i][j] == ' ')
				j++;
			if (lines[i][j])
				mlx->worldmap[x][y++] = lines[i][j++];
		}
		if (last_y < y)
			last_y = y;
		x++;
	}
	mlx->max_y = last_y;
}

void	ft_readmap(char *fname, t_mlx *mlx)
{
	int		fd;
	char	**tmp;
	char	**firstmap;

	tmp = NULL;
	if ((fd = open(fname, O_RDONLY)) < 0)
		ft_put_error("map file not found\n", mlx);
	mlx->lines = 0;
	mlx->lines = get_filelines(mlx->lines, tmp, fd);
	close(fd);
	init_params(mlx);
	firstmap = parse_parameters(mlx, mlx->lines);
	verify_params(mlx);
	mlx->max_x = countx(firstmap, mlx);
	mlx->max_y = county(firstmap);
	init_map(mlx);
	make_map(firstmap, mlx);
	check_player(mlx);
	ft_checkmap_end(mlx);
	mlx->sp = ft_get_sprite(mlx);
	mlx->win.win_ptr = mlx_new_window(mlx->win.mlx_ptr,
		mlx->win.width, mlx->win.heigth, "mbari Cub3D");
}
