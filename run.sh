make fclean
if [ "$1" = bonus ]; then
    echo "\033[35m[Building The Game with The Bonus Part....]\033[34m"
    make bonus
else
    echo "\033[35m[Building The Game without The Bonus Part...]\033[34m"
    make
fi
make clean

if [ "$1" = bonus ]; then
    echo "\033[35m[The map You select is $2 ...]\033[34m"
    if [ "$3" = --save ]; then
        ./cub3D $2 $3
    else
        ./cub3D $2
    fi
else
    echo "\033[35m[The map You select is $1 .....]\033[34m"
    if [ "$2" = --save ]; then
        ./cub3D $1 $2
    else
        ./cub3D $1
    fi
fi
