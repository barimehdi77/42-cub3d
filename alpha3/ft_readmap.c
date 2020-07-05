/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 17:03:00 by mbari             #+#    #+#             */
/*   Updated: 2020/06/21 16:31:02 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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

void	read_txt(int dir, char *str, t_mlx *mlx)
{
	int fd;

	while (*str == ' ')
		str++;
	/* if ((fd = open(str, O_RDONLY)) < 0)
		put_error("ERROR\nWRONG TEXTURE PATH INPUT", p); */
	close(fd);
	if (dir == 1)
		mlx->tex.txt1_path = str;
	if (dir == 2)
		mlx->tex.txt2_path = str;
	if (dir == 3)
		mlx->tex.txt3_path = str;
	if (dir == 4)
		mlx->tex.txt4_path = str;
	/*if (dir == 5)
		mlx->tex.spr_path = str;
	checold_i_txt(dir, p);*/
}

void read_resolution(char *s, t_mlx *mlx)
{
	while (*s == ' ')
		s++;
	mlx->win.width = ft_atoi(s);
	s += ft_intsize(mlx->win.width);
	while (*s == ' ')
		s++;
	mlx->win.heigth = ft_atoi(s);
	if (mlx->win.width > 1366) mlx->win.width = 1366;
	if (mlx->win.heigth > 768) mlx->win.heigth = 768;
}

void	read_cf_color(char *s, t_mlx *mlx, char type)
{
	long int color;
	char *stor;
	int i;

	i = 3;
	stor = (char *)malloc(sizeof(char) * 10);
	while (i > 0)
	{
		while (*s == ' ' || *s == ',')
			s++;
		color = ft_atoi(s);
		s += ft_intsize(color);
		stor = ft_strjoin(stor, ft_itoa(color));
		i--;
	}
	if (type == 'f')
		mlx->floor_color = ft_atoi(stor);
	else if (type == 'c')
		mlx->sky_color = ft_atoi((stor));
	free(stor);
}

int		choose_param(char c, char *str , t_mlx *mlx)
{
	while (*str == ' ')
		str++;
	if (c == 'R' && *(str + 1) == ' ')
		read_resolution(str + 1, mlx);
	else if (c == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ')
		read_txt(1, str + 2, mlx);
	else if (c == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ')
		read_txt(2, str + 2, mlx);
	else if (c == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ')
		read_txt(4, str + 2, mlx);
	else if (c == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ')
		read_txt(3, str + 2, mlx);
	else if (c == 'F' && *(str + 1) == ' ')
		read_cf_color(str + 1, mlx, 'f');
	else if (c == 'C' && *(str + 1) == ' ')
		read_cf_color(str + 1, mlx, 'c');
	else if (c == 'S' && *(str + 1) == ' ')
		read_txt(5, str + 1, mlx); 
	if (c == '1' || c == '0' || c == '2')
		return (0);
	/* else if (c)
		put_error("ERROR\nNON-EMPTY LINE WITH WRONG IDENTIFIER\n", p); */
	return (1);
}

char	**parse_parameters(t_mlx *mlx , char **lines)
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
	//put_error("ERROR\nNO MAP FOUND\n", p);
	return (lines);
}

int	countx(char **map)
{
	int i;
	int max_x;

	i = 0;
	max_x = 0;
	while (map[i])
	{
		i++;
		max_x++;
	}
	return (max_x);
}

int county(char **map)
{
	int i;
	int j;
	int max_y;

	i = 0;
	j = 0;
	max_y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (max_y < j)
			max_y = j;
		i++;
	}
	return (max_y);
}

char **edit_map(char **oldmap, t_mlx *mlx)
{
	int i;
	int j;
	int imax;
	char **newmap;

	imax = countx(oldmap);
	newmap = (char **)malloc(imax * sizeof(char **));
	i = -1;
	while (i++ < imax)
		newmap[i] = (char *)malloc(ft_strlen(oldmap[i]) + 1);
	i = 0;
	j = 0;
	int old_i = 0;
	int old_j = 0;
	
	while(oldmap[old_i] != NULL)
	{
		j = 0;
		old_j = 0;
		if (oldmap[old_i][0] == '\0')
			old_i++;
		else
		{
			while(oldmap[old_i][old_j] != '\0')
			{
				if (oldmap[old_i][old_j] == ' ')
					old_j++;
				else
				{
					newmap[i][j] = oldmap[old_i][old_j];
					if (newmap[i][j] == 'N')
					{
						mlx->posX = i;
						mlx->posY = j;
					}
					j++;
					old_j++;
				}
			}
			newmap[i][j] = '\0';
			i++;
			old_i++;
		}
	}
	newmap[i] = NULL;
	return (newmap);
}
void ft_readmap(char *fname, t_mlx *mlx)
{
    int i;
    int fd;
    char **tmp;
    int ret;


    //fd = open(av[1], O_RDONLY);
    fd = open(fname, O_RDONLY);
    mlx->lines = 0;
    mlx->lines = get_filelines(mlx->lines, tmp, fd);
    mlx->worldmap = parse_parameters(mlx, mlx->lines);
	mlx->worldmap = edit_map(mlx->worldmap, mlx);
	mlx->max_x = countx(mlx->worldmap);
	mlx->max_y = county(mlx->worldmap);
	mlx->win.win_ptr = mlx_new_window(mlx->win.mlx_ptr, w, h, "cub3d alpha3");
	/* int j = 0;
    while (mlx->worldmap[j])
    {
        printf("|%d|%s\n", j, mlx->worldmap[j]);
        j++;
    }
	printf("|max_x = %d||max_y = %d|\n", mlx->max_x, mlx->max_y); */
}