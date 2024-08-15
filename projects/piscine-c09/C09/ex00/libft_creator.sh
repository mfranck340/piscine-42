#!/bin/sh
CC="cc"
SRC=*.c
FLAGS="-c -Wall -Werror -Wextra"
NAME="libft.a"

$CC $FLAGS $SRC
ar rc $NAME *.o
ranlib $NAME
rm *.o
