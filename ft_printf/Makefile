# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbari <mbari@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/30 09:48:13 by mbari             #+#    #+#              #
#    Updated: 2020/10/19 13:45:19 by mbari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NAME = printflib.a

INCLUDES = /includes/libftprintf.h ./libft/libft.h

NAMELIB = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = ./SRC/*.c

OBJ = *.o *SORTED

all: $(NAME)

$(NAMELIB):
	@echo "\033[35m[Libft compilation...]\033[34m"
	@make -C ./libft
	@echo "\033[35m[Moving Libft...]\033[34m"
	@mv ./libft/$(NAMELIB) .
	
$(NAME):$(NAMELIB)
	@echo "\033[35m[ft_printf compilation...]\033[34m"
	@ar -x libft.a
	@$(CC) $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@rm -f libft.a

fclean: clean
	@make fclean -C libft
	@rm -f *.a

re: fclean all
