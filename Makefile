# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 09:35:52 by crisfern          #+#    #+#              #
#    Updated: 2021/10/20 10:11:46 by crisfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
HEADER = so_long.h
SRC = so_long.c
LIBFT = ./libft/libft.a
OBJ = $(SRC:.c=.o)

all: make_libft $(NAME)

make_libft:
	make all -C ./libft

$(NAME): $(HEADER) $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -c

clean:
	rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all 

.PHONY: all clean fclean re
