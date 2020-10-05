# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbari <mbari@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/20 23:42:54 by mbari             #+#    #+#              #
#    Updated: 2020/10/06 01:01:43 by mbari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NAME = cub3d

INCLUDES = /ft_printf/includes/libftprintf.h ./ft_printf/libft/libft.h includes/cub3d.h

MINILIBX = -Lminilibx -lmlx -L/usr/X11/lib -lXext -lX11 -lm -lbsd -g

NAMELIB = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC_FT_CUB3D = files/*.c ./get_next_line/*.c

OBJ = *.o ./get_next_line/*.o

all: $(NAME)

$(NAMELIB):
	make -C ./ft_printf
	cp ./ft_printf/$(NAMELIB) .
	
$(NAME):$(NAMELIB)
	gcc $(SRC_FT_CUB3D) $(NAMELIB) -D BUFFER_SIZE=32 -I $(INCLUDES) $(MINILIBX) -o $(NAME)
	

clean:
	make clean -C ft_printf
	rm -f $(OBJ)
	rm -f libftprintf.a

fclean: clean
	make fclean -C ft_printf
	rm -f *.a screenshot.bmp
	rm -rf cub3d

re: fclean all