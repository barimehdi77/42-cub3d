/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:36:00 by mbari             #+#    #+#             */
/*   Updated: 2020/10/30 13:21:35 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include "cub3d_bonus.h"
# include "/Users/mbari/.brew/include/SDL2/SDL_mixer.h"

typedef struct		s_window
{
	int				width;
	int				heigth;
	char			*title;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_window;

typedef struct		s_minmap
{
	int				x;
	int				y;
	int				new_x;
	int				new_y;
	int				max_x;
	int				max_y;
}					t_minmap;

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
	int				vmovescreen;
	int				udiv;
	int				vdiv;
	double			vmove;
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
	void			*txt_floor;
	int				*txt_floor_data;
	char			*txt_floor_path;
	int				txt_floor_w;
	int				txt_floor_h;
	int				txt_floor_bp;
	int				txt_floor_sl;
	int				txt_floor_end;
	void			*txt_ceiling;
	int				*txt_ceiling_data;
	char			*txt_ceiling_path;
	int				txt_ceiling_w;
	int				txt_ceiling_h;
	int				txt_ceiling_bp;
	int				txt_ceiling_sl;
	int				txt_ceiling_end;
	void			*sp;
	int				*sp_data;
	char			*sp_path;
	int				sp_w;
	int				sp_h;
	int				sp_bp;
	int				sp_sl;
	int				sp_end;
	void			*sprite;
	int				*sprite_data;
	char			*sprite_path;
	int				sprite_w;
	int				sprite_h;
	int				sprite_bp;
	int				sprite_sl;
	int				sprite_end;
	void			*coin;
	int				*coin_data;
	char			*coin_path;
	int				coin_w;
	int				coin_h;
	int				coin_bp;
	int				coin_sl;
	int				coin_end;
	void			*bomb;
	int				*bomb_data;
	char			*bomb_path;
	int				bomb_w;
	int				bomb_h;
	int				bomb_bp;
	int				bomb_sl;
	int				bomb_end;
	void			*heart;
	int				*heart_data;
	char			*heart_path;
	int				heart_w;
	int				heart_h;
	int				heart_bp;
	int				heart_sl;
	int				heart_end;
	void			*died;
	int				*died_data;
	char			*died_path;
	int				died_w;
	int				died_h;
	int				died_bp;
	int				died_sl;
	int				died_end;
	void			*win;
	int				*win_data;
	char			*win_path;
	int				win_w;
	int				win_h;
	int				win_bp;
	int				win_sl;
	int				win_end;
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
	float			raydirx0;
	float			raydiry0;
	float			raydirx1;
	float			raydiry1;
	float			posz;
	float			rowdistance;
	float			floorstepx;
	float			floorstepy;
	float			floorx;
	float			floory;
	int				cellx;
	int				celly;
	int				p;
}					t_texture;

typedef struct		s_player
{
	int				hearts;
	int				score;
	int				coin;
}					t_player;

typedef struct		s_music
{
	Mix_Chunk		*hit_coin;
	Mix_Chunk		*hit_domb;
	Mix_Music		*bg_music;
}					t_music;

typedef	struct		s_mlx
{
	t_window		win;
	t_draw			wall;
	t_ray			ray;
	t_texture		tex;
	t_sprite		*sp;
	t_sprtools		sptools;
	t_screenshot	*shot;
	t_minmap		map;
	t_player		player;
	t_music			music;
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
	int				tex_floor_done;
	int				tex_ceiling_done;
	int				spr_done;
	int				tex_coin_done;
	int				tex_bomb_done;
	int				tex_heart_done;
	int				tex_died_done;
	int				tex_win_done;
	int				sprite_num;
	int				*sprite_order;
	int				x;
	char			**worldmap;
	char			**lines;
	char			*this_lv;
}					t_mlx;

#endif
