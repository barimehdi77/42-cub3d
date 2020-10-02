#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"


char	**get_lines(char **lines, char **tmp, int fd)
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

int		choose_param(char c, char *str/* , t_param *p */)
{
	while (*str == ' ')
		str++;
	/*if (c == 'R' && *(str + 1) == ' ')
		make_resolution(str + 1, p);
	 else if (c == 'F' && *(str + 1) == ' ')
		make_floor(str + 1, p);
	else if (c == 'C' && *(str + 1) == ' ')
		make_sky(str + 1, p);
	else if (c == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ')
		make_txt(1, str + 2, p);
	else if (c == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ')
		make_txt(2, str + 2, p);
	else if (c == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ')
		make_txt(4, str + 2, p);
	else if (c == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ')
		make_txt(3, str + 2, p);
	else if (c == 'S' && *(str + 1) == ' ')
		make_txt(5, str + 1, p); */
	if (c == '1' || c == '0' || c == '2')
		return (0);
	/* else if (c)
		put_error("ERROR\nNON-EMPTY LINE WITH WRONG IDENTIFIER\n", p); */
	return (1);
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
		if (!choose_param(lines[i][j], lines[i]/* , p */))
		{
			return (&lines[i]);
		}
		i++;
	}
	//put_error("ERROR\nNO MAP FOUND\n", p);
	return (lines);
}

char **edit_map(char **oldmap)
{
	int i;
	int j;
	char **newmap;

	i = 0;
	j = 0;
	while(oldmap[i][j])
	{
		j = 0;
		while(oldmap[i][j] == ' ')
		{
			newmap[i][j] = oldmap[i][j];
			j++;
		}
		while(oldmap[i][j] != ' ')
			j++;
		i++;
	}
	return (newmap);
}

int main(int ac, char **av)
{
    int i;
    int fd;
    char **tmp;
    char **lines;
    char **map;
    int ret;


    //fd = open(av[1], O_RDONLY);
    fd = open("../3.cub", O_RDONLY);
    lines = 0;
    lines = get_lines(lines, tmp, fd);
    map = parse_parameters(lines);
    int j = 0;
    while (map[j])
    {
        printf("%s\n", map[j]);
        j++;
    }
	printf("\n\nnewmap:\n\n");
	map = edit_map(map);
	j = 0;
    while (map[j])
    {
        printf("%s\n", map[j]);
        j++;
    }
}