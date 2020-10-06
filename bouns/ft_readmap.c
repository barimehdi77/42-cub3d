/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 17:03:00 by mbari             #+#    #+#             */
/*   Updated: 2020/10/06 00:57:44 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


char	**get_filelines(char **lines, char **tmp, int fd)
{
	//this func read the map file and return it to mlx->lines
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

void	extra_param(char *str, t_mlx *mlx, char *message)
{
	while (*str <= '9' && *str >= '0')
		str++;
	while (*str == ' ')
		str++;
	if (*str)
		ft_put_error(message, mlx);
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
	//this func give The path of every texture to the param in mlx
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
	check_txt(dir,mlx);
}

void read_resolution(char *s, t_mlx *mlx)
{
	if (mlx->screen_done)
		ft_put_error("Multiple resolution inputs\n", mlx);
	mlx->screen_done = 1;
	//this func read the resolution of the window
	while (*s == ' ')
		s++;
	mlx->win.width = ft_atoi(s);
	s += ft_intsize(mlx->win.width);
	if (*s != ' ')
		ft_put_error("Wrong height input\n", mlx);
	while (*s == ' ')
		s++;
	mlx->win.heigth = ft_atoi(s);
	if (w <= 0 || h <= 0)
		ft_put_error("Incorrect resolution values\n", mlx);
	if (mlx->win.width > 1366) mlx->win.width = 1366;//change it to 2560
	if (mlx->win.heigth > 768) mlx->win.heigth = 768;//change it to 1440
	extra_param(s, mlx, "Too many resolution inputs");
}

void	read_cf_color(char *s, t_mlx *mlx, char type)
{
	//this func read the RGB color of The sky and floor
	long int color;
	char *stor;
	int i;

	i = 3;
	if (mlx->floor_done && type == 'f')
		ft_put_error("Multiple floor color inputs\n", mlx);
	if (mlx->sky_done && type == 'c')
		ft_put_error("Multiple ceiling color inputs\n", mlx);
	stor = (char *)malloc(sizeof(char) * 10);
	while (i > 0)
	{
		while (*s == ' ')
			s++;
		color = ft_atoi(s);
		s += ft_intsize(color);
		stor = ft_strjoin(stor, ft_itoa(color));
		while (*s == ' ')
			s++;
		if (*(s++) != ',' && i > 1)
			ft_put_error("Wrong floor color input\n", mlx);
		i--;
	}
	if (type == 'f')
	{
		extra_param(s, mlx, "Too many Floor rgb inputs");
		mlx->floor_color = ft_atoi(stor);
		if(mlx->floor_color < 0)
			ft_put_error("Wrong values for floor color\n", mlx);
		mlx->floor_done = 1;
	}
	else if (type == 'c')
	{
		extra_param(s, mlx, "Too many ceiling rgb inputs");
		mlx->sky_color = ft_atoi(stor);
		if(mlx->floor_color < 0)
			ft_put_error("Wrong values for ceiling color\n", mlx);
		mlx->sky_done = 1;
	}
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
	else if (c == '1' || c == '0' || c == '2')
		return (0);
	else  if (c)
		ft_put_error("NON-EMPTY LINE WITH WRONG IDENTIFIER\n", mlx);
	return (1);
}

char	**parse_parameters(t_mlx *mlx , char **lines)
{
	//this func read the map values and send it to choose_param().
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

int	countx(char **lines, t_mlx *mlx)
{
	int i;
	int j;
	int	emptyline;

	i = 0;
	emptyline = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j] == ' ')
			j++;
		if (!lines[i][j])
			emptyline = 1;
		if (lines[i][j] && emptyline)
			ft_put_error("Additional Input after map\n", mlx);
		i++;
	}
	return (i);
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

/*char **edit_map(char **oldmamlx, t_mlx *mlx)
{
	//this func edit/delet The unexpicted char from the map.
	int i;
	int j;
	int imax;
	char **newmap;

	imax = countx(oldmamlx);
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
					else if (newmap[i][j] == '2')
					{
						mlx->sp.x = i + 0.5;
						mlx->sp.y = j + 0.5;
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
	return (newmamlx);
}*/


void init_map(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	mlx->worldmap = malloc((mlx->max_x + 1) * sizeof(int *));
	while (i <= mlx->max_x)
	{
		mlx->worldmap[i] = malloc((mlx->max_y + 1) * sizeof(int));
		j = 0;
		while (j <= mlx->max_y)
		{
			mlx->worldmap[i][j] = '7';
			j++;
		}
		i++;
	}
}

void		make_map(char **lines, t_mlx *mlx)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		last_y;

	x = 0;
	i = 0;
	last_y = 0;
	while (lines[i])
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
		j = 0;
		i++;
		x++;
	}
	//ft_printf("|%d|\t",mlx->max_y);
	mlx->max_y = last_y;
	//ft_printf("|%d|\n",mlx->max_y);
}

void init_params(t_mlx *mlx)
{
	mlx->floor_done = 0;
	mlx->sky_done = 0;
	mlx->screen_done = 0;
	mlx->tex1_done = 0;
	mlx->tex2_done = 0;
	mlx->tex3_done = 0;
	mlx->tex4_done = 0;
}

void verify_params(t_mlx *mlx)
{
	if (!(mlx->screen_done))
		ft_put_error("NO RESOLUTION INPUT\n", mlx);
	if (!(mlx->floor_done))
		ft_put_error("NO FLOOR COLOR INPUT\n", mlx);
	if (!(mlx->sky_done))
		ft_put_error("NO CEILING COLOR INPUT\n", mlx);
	if (!mlx->tex1_done || !mlx->tex2_done || !mlx->tex3_done ||
		!mlx->tex4_done || !mlx->spr_done)
		ft_put_error("MISSING TEXTURE PATH\n", mlx);
}

void	checkmap(t_mlx *mlx, int x, int y)
{
	char	**map;

	mlx->player_pos = 0;
	map = mlx->worldmap;
	if (map[x][y] == '1' || map[x][y] == '0' || map[x][y] == '2')
		return ;
	if (x == 0 || y == 0 || x == mlx->max_x)
		ft_put_error("MAP NOT CLOSED AROUND SPAWN\n", mlx);
	if (map[x][y] == '7')
		ft_put_error("MAP NOT CLOSED AROUND SPAWN\n", mlx);
	if (map[x][y] == '3')
		map[x][y] = '0';
	if (map[x][y] == '4')
		map[x][y] = '2';
	checkmap(mlx, x + 1, y);
	checkmap(mlx, x, y + 1);
	checkmap(mlx, x - 1, y);
	checkmap(mlx, x, y - 1);
}


void ft_readmap(char *fname, t_mlx *mlx)
{
    int fd;
    char **tmp;
	char **firstmap;


    //fd = open(av[1], O_RDONLY);
    if ((fd = open(fname, O_RDONLY)) < 0)
		ft_put_error("map file not found\n", mlx);
    mlx->lines = 0;
    mlx->lines = get_filelines(mlx->lines, tmp, fd);
	close(fd);
	init_params(mlx);
    firstmap = parse_parameters(mlx, mlx->lines);
	verify_params(mlx);
	//mlx->worldmap = edit_map(mlx->worldmamlx, mlx);
	mlx->max_x = countx(firstmap, mlx);
	mlx->max_y = county(firstmap);
	init_map(mlx);
	make_map(firstmap,mlx);
	check_player(mlx);
	checkmap(mlx, mlx->posX, mlx->posY);
	mlx->sp = get_sprite(mlx);
	mlx->win.win_ptr = mlx_new_window(mlx->win.mlx_ptr, w, h, "cub3d alpha3");
	
}