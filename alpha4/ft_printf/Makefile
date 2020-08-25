# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbari <mbari@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/30 09:48:13 by mbari             #+#    #+#              #
#    Updated: 2020/05/20 23:42:23 by mbari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NAME = libftprintf.a

INCLUDES = /includes/libftprintf.h ./libft/libft.h

NAMELIB = libft.a

FLAGS = -Wall -Wextra -Werror

SRC_FT_PRINTF = ./SRC/*.c

OBJ = *.o #*SORTED

all: $(NAME)

$(NAMELIB):
	make -C ./libft
	cp ./libft/$(NAMELIB) .
	
$(NAME):$(NAMELIB)
	ar -x libft.a
	gcc $(FLAGS) -c $(SRC_FT_PRINTF) -I $(INCLUDES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)
	rm -f libft.a

fclean: clean
	make fclean -C libft
	rm -f *.a

re: fclean all
