gcc main.c ft_update.c ft_minimap.c ft_move.c ft_puts.c ft_texture.c ft_key_pressed.c -Lminilibx -lmlx -L/usr/X11/lib -lXext -lX11 -lm -lbsd -g
#-lmlx -L/usr/X11/lib -lXext -lX11 -lm -g
./a.out && rm ./a.out
