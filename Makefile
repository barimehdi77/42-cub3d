# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbari <mbari@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 08:34:17 by mbari             #+#    #+#              #
#    Updated: 2020/10/30 12:50:56 by mbari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#!/bin/bash

MLX = -lmlx -lm -framework OpenGL -framework AppKit -L /Users/mbari/.brew/lib `sdl2-config --libs` -lSDL2_mixer

NAME = cub3D

NAMELIB = printflib.a

SRCS = 	files/ft_init.c \
		files/ft_key_pressed.c \
		files/ft_move.c \
		files/ft_player.c \
		files/ft_puterror.c \
		files/ft_readmap.c \
		files/ft_screenshot.c \
		files/ft_sprite.c \
		files/ft_texture.c \
		files/ft_update.c \
		files/ft_check.c \
		files/ft_draw.c \
		files/main.c

B_SRCS	=	bonus/ft_init_bonus.c \
			bonus/ft_key_pressed_bonus.c \
			bonus/ft_move_bonus.c \
			bonus/ft_minimap_bonus.c \
			bonus/ft_player_bonus.c \
			bonus/ft_puterror_bonus.c \
			bonus/ft_readmap_bonus.c \
			bonus/ft_screenshot_bonus.c \
			bonus/ft_sprite_bonus.c \
			bonus/ft_texture_bonus.c \
			bonus/ft_update_bonus.c \
			bonus/ft_check_bonus.c \
			bonus/ft_draw_bonus.c \
			bonus/ft_text_cf_bonus.c \
			bonus/ft_collect_bonus.c \
			bonus/ft_hud_bonus.c \
			bonus/ft_check_tex_bonus.c \
			bonus/main_bonus.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

GETNEXT =	get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

OBJ = $(SRCS:.c=.o)
B_OBJ = $(B_SRCS:%.c=%.o) 
OBJGET	= $(GETNEXT:.c=.o)

$(NAME) : $(OBJ) $(OBJGET)
	@echo "\033[31m[Remove last version Of Cub3D...]"
	@rm -rf Cub3D
	@$(MAKE) -C ./ft_printf
	@mv ./ft_printf/printflib.a .
	@echo "\033[32m[Cub3D compilation...]"
	@$(CC) $(OBJ) $(OBJGET) -I ./includes -Wall -Wextra -Werror $(MLX) $(NAMELIB) -o $(NAME) -g
	@echo "\033[34m[Done !]"

bonus :  $(B_OBJ) $(OBJGET)
	@echo "\033[31m[Remove last version Of Cub3D...]"
	@rm -rf Cub3D
	@$(MAKE) -C ./ft_printf
	@mv ./ft_printf/printflib.a .
	@echo "\033[32m[Cub3D compilation...]"
	@$(CC) $(B_OBJ) $(OBJGET) -I ./includes -Wall -Wextra -Werror $(MLX) $(NAMELIB) -o $(NAME) -g
	@echo "\033[34m[Done !]"

all : $(NAME)

clean :
	@echo "\033[31m[Cleaning The Old Files...!]\033[34m"
	@rm -rf $(OBJ) $(B_OBJ)
	@$(MAKE) clean -C ./ft_printf

fclean : clean
	@echo "\033[31m[Cleaning printf Files...!]"
	@$(MAKE) fclean -C ./ft_printf
	@rm -rf printflib.a
	@echo "\033[31m[Cleaning Cub3D Files...!]"
	@rm -rf $(NAME) $(OBJ) $(OBJGET)
	@echo "\033[31m[Deleting Old Screenshot...!]"
	@rm -rf Screenshot.bmp

re : fclean all
