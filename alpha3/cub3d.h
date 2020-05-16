/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by mbari             #+#    #+#             */
/*   Updated: 2020/05/16 02:04:00 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB1D_H
#define CUB1d_H

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>


#define texWidth 64
#define texHeight 64
#define mapWidth 15
#define mapHeight 16 //the second map 15
#define h 600//480 
#define w 900//640
#define RGB_Red 	0xFF0000 
#define RGB_Green 	0x008000
#define RGB_Blue 	0x0000FF
#define RGB_White 	0xFFFFFF
#define RGB_Yellow	0xFFFF00

/* static char worldMap[mapWidth][mapHeight] = 
			{  
				"1111111111",
			   	"1000000001",
			   	"1002000001",
			   	"1000000001",
			   	"1000003001",
			   	"1000000001",
			   	"1040000001",
			   	"1000005001",
			   	"1000000001",
			   	"1111111111"
			}; */

static char worldMap[mapWidth][mapHeight] = 
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
			};

typedef struct	s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	//void	*img_ptr;
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
}				t_ray;

typedef struct	s_minmap
{
	void *img_ptr;
	int	 *img_data;
	void *img_xpm;
	int  *xpm_data;
	int  bpp;
	int  size_line;
	int	 endian;
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

typedef struct	s_textuer
{
	int num;
	double wallx;
	int x;
	int y;
	double step;
	double pos;
}				t_texture;


typedef	struct	s_mlx
{
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
	int x;
}				t_mlx;

static char worldMap[mapWidth][mapHeight];
void ft_putchar(char c);
void ft_putstr(char *s);
void ft_putnbr(int nbr);
int ft_loop(t_mlx *mlx);
int ft_update(t_mlx *mlx);
void ft_steps(t_mlx *mlx, int x);
void ft_inti(t_mlx *mlx);
int ft_draw(t_mlx *mlx, int x);
void ft_drawawall(int x, int y1, int y2, int color, t_mlx *mlx);                 //bdelltha
int	ft_move(t_mlx *mlx);
void ft_rotate(t_mlx *mlx);
void ft_draw_square(t_minmap *img, int scale, int player, int color);
void ft_fill_data(t_minmap *img, int iswall, int color);
int ft_minmap(t_mlx *mlx);
void ft_draw_floorsky(t_mlx *mlx);
void ft_texture(t_mlx *mlx, int x);
void ft_put_tex_to_image(t_mlx *mlx, int y1, int y2, int x);
int key_pressed(int key, t_mlx *mlx);
int key_released(int key, t_mlx *mlx);

#endif
