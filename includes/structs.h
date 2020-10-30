/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:36:00 by mbari             #+#    #+#             */
/*   Updated: 2020/10/17 16:59:43 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct		s_window
{
	int				width;
	int				heigth;
	char			*title;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_window;

typedef struct		s_ray
{
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	char			walldir;
}					t_ray;

typedef	struct		s_draw
{
	int				lineheight;
	int				drawstart;
	int				drawend;
}					t_draw;

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				texture;
}					t_sprite;

typedef struct		s_sprtools
{
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				tex_x;
	int				tex_y;
	int				x;
	int				y;
	int				d;
}					t_sprtools;

# pragma pack(push, 1)

typedef struct		s_bitmapheader
{
	uint16_t		bftype;
	uint32_t		bfsize;
	uint16_t		bfreserved1;
	uint16_t		bfreserved2;
	uint32_t		bfoffbits;
}					t_bitmapheader;

typedef struct		s_bitmapinfo
{
	uint32_t		bisize;
	int32_t			biwidth;
	int32_t			biheight;
	uint16_t		biplanes;
	uint16_t		bibitcount;
	uint32_t		bicompression;
	uint32_t		bisizeimage;
	int32_t			bixpelspermeter;
	int32_t			biypelspermeter;
	uint32_t		biclrused;
	uint32_t		biclrimportant;
}					t_bitmapinfo;
# pragma pack(pop)

typedef struct		s_screenshot
{
	int				width;
	int				height;
	int				bitcount;
	int				red;
	int				blue;
	int				green;
	int				width_in_bytes;
	uint32_t		imagesize;
	unsigned char	*buf;
}					t_screenshot;

typedef struct		s_textuer
{
	int				num;
	double			wallx;
	int				x;
	int				y;
	double			step;
	double			pos;
	void			*txt1;
	int				*txt1_data;
	char			*txt1_path;
	int				txt1_w;
	int				txt1_h;
	int				txt1_bp;
	int				txt1_sl;
	int				txt1_end;
	void			*txt2;
	int				*txt2_data;
	char			*txt2_path;
	int				txt2_w;
	int				txt2_h;
	int				txt2_bp;
	int				txt2_sl;
	int				txt2_end;
	void			*txt3;
	int				*txt3_data;
	char			*txt3_path;
	int				txt3_w;
	int				txt3_h;
	int				txt3_bp;
	int				txt3_sl;
	int				txt3_end;
	void			*txt4;
	int				*txt4_data;
	char			*txt4_path;
	int				txt4_w;
	int				txt4_h;
	int				txt4_bp;
	int				txt4_sl;
	int				txt4_end;
	void			*sp;
	int				*sp_data;
	char			*sp_path;
	int				sp_w;
	int				sp_h;
	int				sp_bp;
	int				sp_sl;
	int				sp_end;
	void			*img_ptr;
	int				*img_data;
	void			*img_xpm;
	int				*xpm_data;
	int				txt_sl;
	int				txt_w;
	int				txt_h;
	int				txt_x;
	int				bpp;
	int				size_line;
	int				endian;
}					t_texture;

typedef	struct		s_mlx
{
	t_window		win;
	t_draw			wall;
	t_ray			ray;
	t_texture		tex;
	t_sprite		*sp;
	t_sprtools		sptools;
	t_screenshot	*shot;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			movespeed;
	double			rotspeed;
	double			*zbuffer;
	long int		floor_color;
	long int		sky_color;
	int				max_x;
	int				max_y;
	int				player_pos;
	int				forward;
	int				backward;
	int				left;
	int				right;
	int				rotleft;
	int				rotright;
	int				screen_done;
	int				floor_done;
	int				sky_done;
	int				tex1_done;
	int				tex2_done;
	int				tex3_done;
	int				tex4_done;
	int				spr_done;
	int				sprite_num;
	int				*sprite_order;
	int				x;
	char			**worldmap;
	char			**lines;
}					t_mlx;

#endif
