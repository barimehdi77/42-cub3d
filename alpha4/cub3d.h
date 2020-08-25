/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by mbari             #+#    #+#             */
/*   Updated: 2020/08/20 14:40:04 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB1D_H
#define CUB1d_H

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "ft_printf/includes/libftprintf.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/libft/libft.h"


#define texWidth mlx->tex.txt_w
#define texHeight mlx->tex.txt_h
#define mapWidth 15
#define mapHeight 16 //the second map 15
#define w mlx->win.width//600 
#define h mlx->win.heigth//900
#define RGB_Red 	0xFF0000 
#define RGB_Green 	0x008000
#define RGB_Blue 	0x0000FF
#define RGB_White 	0xFFFFFF
#define RGB_Yellow	0xFFFF00

/* static char worldMap[mapWidth][mapHeight] = 
			{  
				"1111111111111111",
				"1000000000000001",
			   	"1000440004444001",
			   	"1004040000004001",
			   	"1000040004444001",
			   	"1000040000004001",
			   	"1000444004444001",
			   	"1000000000000001",
				"1004444004444001",
				"1000004000004001",
				"1004444000004001",
				"1000004000004001",
				"1004444000004001",
			   	"1000000000000001",
			   	"1111111111111111"
			}; */

typedef struct	s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		heigth;
	char	*title;
}				t_window;

typedef struct	s_ray
{
	//ray direction
	double raydirx;
	double raydiry;
	//the current squar of the map the ray is in
	int mapx;
	int mapy;
	//length of ray from current position to next x or y-side
	double sideDistX;
    double sideDistY;
	//length of ray from one x or y-side to next x or y-side
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	//what direction to step in x or y-direction (either +1 or -1)
	int stepX;
	int stepY;
	int hit; //was there a wall hit?
	int side; //was a NS or a EW wall hit?
	char walldir;
}				t_ray;

typedef struct	s_minmap
{
	int x;
	int y;
	int new_x;
	int new_y;
	int max_x;
	int max_y;
}				t_minmap;

typedef	struct	s_draw
{
	int lineHeight;
	int drawStart;
	int drawEnd;
}				t_draw;
typedef struct s_sprite
{
  double x;
  double y;
  int texture;
  int sprite_num;
}			t_sprite;

typedef struct	s_textuer
{
	int num;
	double wallx;
	int x;
	int y;
	double step;
	double pos;
	void			*txt1;
	int				*txt1_data;
	char *txt1_path;
	int  txt1_w;
	int  txt1_h;
	int  txt1_bp;
	int  txt1_sl;
	int  txt1_end;
	void			*txt2;
	int				*txt2_data;
	char *txt2_path;
	int  txt2_w;
	int  txt2_h;
	int  txt2_bp;
	int  txt2_sl;
	int  txt2_end;
	void			*txt3;
	int				*txt3_data;
	char *txt3_path;
	int  txt3_w;
	int  txt3_h;
	int  txt3_bp;
	int  txt3_sl;
	int  txt3_end;
	void			*txt4;
	int				*txt4_data;
	char *txt4_path;
	int  txt4_w;
	int  txt4_h;
	int  txt4_bp;
	int  txt4_sl;
	int  txt4_end;
	void			*sp;
	int				*sp_data;
	char *sp_path;
	int  sp_w;
	int  sp_h;
	int  sp_bp;
	int  sp_sl;
	int  sp_end;
	void *img_ptr;
	int	 *img_data;
	void *img_xpm;
	int  *xpm_data;
	int				txt_sl;
	int				txt_w;
	int				txt_h;
	int				txt_x;
	int  bpp;
	int  size_line;
	int	 endian;
}				t_texture;


typedef	struct	s_mlx
{
	char	**worldmap;
	char	**lines;
	long int floor_color;
	long int sky_color;
	int		max_x;
	int		max_y;
	//x and y start position
	double posX; 
	double posY;
	//initial direction vector
  	double dirX;
	double dirY;
	//the 2d raycaster version of camera plane 
  	double planeX;
	double planeY;
	double movespeed;//the constant value is in squares/second
	double rotspeed;//the constant value is in radians/second
	int forward;
	int backward;
	int left;
	int right;
	int rotleft;
	int rotright;
	t_window win;
	t_draw wall;
	t_ray ray;
	t_minmap map;
	t_texture tex;
	t_sprite sp;
	int x;
}				t_mlx;

/* static char worldMap[mapWidth][mapHeight];
void ft_putchar(char c);
void ft_putstr(char *s);
void ft_putnbr(int nbr); */
int ft_loop(t_mlx *mlx);
int ft_update(t_mlx *mlx);
void ft_steps(t_mlx *mlx, int x);
void ft_inti(t_mlx *mlx);
int ft_draw(t_mlx *mlx, int x);
void ft_drawawall(int x, int y1, int y2, int color, t_mlx *mlx);                 //bdelltha
int	ft_move(t_mlx *mlx);
void ft_rotate(t_mlx *mlx);
void ft_draw_square(t_mlx *mlx, int scale, int player, int color);
void ft_fill_data(t_mlx *mlx, int iswall, int color);
int ft_minmap(t_mlx *mlx);
void ft_draw_floorsky(t_mlx *mlx);
void	choose_texture(t_mlx *mlx, t_ray *ray);
void ft_texture(t_mlx *mlx, int x);
void ft_put_tex_to_image(t_mlx *mlx, int y1, int y2, int x);
int key_pressed(int key, t_mlx *mlx);
int key_released(int key, t_mlx *mlx);
void ft_readmap(char *fname, t_mlx *mlx);
char	**get_filelines(char **lines, char **tmp, int fd);
int		choose_param(char c, char *str , t_mlx *mlx);
char	**parse_parameters(t_mlx *mlx, char **lines);
char **edit_map(char **oldmap, t_mlx *mlx);
void	read_cf_color(char *s, t_mlx *mlx, char type);
void ft_sprite(t_mlx *mlx, double *zbuffer);

#endif
