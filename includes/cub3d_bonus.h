/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:24:02 by mbari             #+#    #+#             */
/*   Updated: 2020/11/17 14:06:53 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdint.h>
# include "structs_bonus.h"
# include "/Users/mbari/.brew/include/SDL2/SDL_mixer.h"
# include "../ft_printf/includes/libftprintf.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/libft/libft.h"

# define RGB_RED 	0xFF0000
# define RGB_GREEN 	0x008000
# define RGB_BLUE 	0x0000FF
# define RGB_WHITE 	0xFFFFFF
# define RGB_YELLOW	0xFFFF00
# define UDIV 3
# define VDIV 3
# define NO 0
# define YES 1

t_screenshot	*ft_init_shot(t_mlx *mlx);
t_sprite		*ft_get_sprite(t_mlx *mlx);
int				main(int ac, char **av);
int				ft_count_sprotes(t_mlx *mlx);
int				ft_draw(t_mlx *mlx, int x);
int				player_init(int x, int y, char dir, t_mlx *mlx);
int				ft_namecheck(char *arg, char *ext);
int				key_pressed(int key, t_mlx *mlx);
int				key_released(int key, t_mlx *mlx);
int				ft_savecheck(char *arg, char *save);
int				can_move(int pos);
int				ft_move(t_mlx *mlx);
int				check_mapvalue(char value, int x, int y, t_mlx *mlx);
int				choose_param(char c, char *str, t_mlx *mlx);
int				countx(char **lines, t_mlx *mlx);
int				county(char **map);
int				close_game(t_mlx *mlx);
int				ft_loop(t_mlx *mlx);
char			**get_filelines(char **lines, char **tmp, int fd);
char			**parse_parameters(t_mlx *mlx, char **lines);
void			check_txt(int dir, t_mlx *mlx);
void			read_txt(int dir, char *str, t_mlx *mlx);
void			read_resolution(char *s, t_mlx *mlx);
void			ft_isfloor(char *s, t_mlx *mlx, char type, char *stor);
void			read_cf_color(char *s, t_mlx *mlx, char type);
void			ft_drawspritelines(t_sprtools *sprite, t_mlx *mlx);
void			checkmap(t_mlx *mlx, int x, int y);
void			ft_draw_square(t_mlx *mlx, int scale, int color);
void			set_camerans(char dir, t_mlx *mlx);
void			set_cameraew(char dir, t_mlx *mlx);
void			init_params(t_mlx *mlx);
void			init_map(t_mlx *mlx);
void			ft_rotleft(t_mlx *mlx, double oldplanex, double olddirx);
void			ft_rotate(t_mlx *mlx);
void			ft_moverightleft(t_mlx *mlx);
void			extra_param(char *str, t_mlx *mlx, char *message);
void			verify_params(t_mlx *mlx);
void			check_player(t_mlx *mlx);
void			ft_put_error(char *error, t_mlx *mlx);
void			check_restoftex(int dir, t_mlx *mlx);
void			make_map(char **lines, t_mlx *mlx);
void			ft_readmap(char *fname, t_mlx *mlx);
void			ft_screen_shot(t_mlx *mlx);
void			ft_fill_image(t_mlx *mlx, unsigned char *buf);
void			ft_screno(t_mlx *mlx);
void			ft_sort_sprites(t_mlx *mlx);
void			ft_sprite_height(t_sprtools *sprite, t_mlx *mlx);
void			ft_sprite_width(t_sprtools *sprite, t_mlx *mlx);
void			ft_drawsprites(t_mlx *mlx);
void			choose_texture(t_mlx *mlx, t_ray *ray);
void			ft_texput(t_mlx *mlx);
void			ft_put_tex_to_image(t_mlx *mlx, int y1, int y2, int x);
void			ft_getside(t_mlx *mlx);
void			ft_texture(t_mlx *mlx, int x);
void			ft_steps_y(t_mlx *mlx);
void			ft_steps(t_mlx *mlx, int x);
void			ft_wallhit(t_mlx *mlx);
void			ft_wallside(t_mlx *mlx, int x);
void			ft_inti(t_mlx *mlx);
void			ft_draw_floorsky(t_mlx *mlx);
void			ft_start_game(char *fname, int save);
void			ft_fill_data(t_mlx *mlx, int iswall, int color);
void			ft_update(t_mlx *mlx, int screenshot);
void			draw_player(t_mlx *mlx);
int				ft_minmap(t_mlx *mlx);
void			ft_sky_floor_texture(t_mlx *mlx);
void			ft_sky_floor_texput(t_mlx *mlx);
void			ft_sprite_textput(t_mlx *mlx);
void			ft_draw_hud(t_mlx *mlx);
int				ft_get_coin(t_mlx *mlx);
void			ft_collect(t_mlx *mlx);
void			ft_print_score(t_mlx *mlx);
void			ft_draw_hearts(t_mlx *mlx, long int color);
void			ft_put_winscreen(t_mlx *mlx, long int color);
void			ft_put_diedscreen(t_mlx *mlx, long int color);
void			ft_win_or_died(t_mlx *mlx);
void			ft_read_txt_rest(int dir, char *str, t_mlx *mlx);
void			ft_choose_param_rest(char c, char *str, t_mlx *mlx);
void			ft_checkmap_end(t_mlx *mlx);
void			check_restoftex(int dir, t_mlx *mlx);
void			check_texofcbc(int dir, t_mlx *mlx);
void			check_texofhwd(int dir, t_mlx *mlx);
void			ft_load_music(t_mlx *mlx);
void			ft_diedwinscreen_texput(t_mlx *mlx);
void			ft_spirte_resize(t_mlx *mlx, t_sprtools *sp);
void			ft_takescreen(t_mlx *mlx);

#endif
