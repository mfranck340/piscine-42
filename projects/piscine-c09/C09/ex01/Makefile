# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffierro- <ffierro-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 18:07:43 by ffierro-          #+#    #+#              #
#    Updated: 2024/08/15 19:44:02 by ffierro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:.c=.o)
HEADERS = includes/ft.h

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $(TARGET) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
