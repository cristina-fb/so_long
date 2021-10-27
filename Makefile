# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 09:35:52 by crisfern          #+#    #+#              #
#    Updated: 2021/10/27 11:10:51 by crisfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
HEADER = so_long.h
SRC = so_long.c \
		map.c \
		move.c \
		game.c \
		utils.c
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a
OBJ = $(SRC:.c=.o)

all: make_libft make_mlx $(NAME)

make_libft:
	@make all -C ./libft

make_mlx:
	@make all -C ./mlx

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

%.o: %.c $(HEADER) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $< -c

bonus: all

clean:
	rm -f $(OBJ)
	@make clean -C ./libft
	@make clean -C ./mlx

fclean: clean
	rm -f $(NAME)
	@make fclean -C ./libft
	@make clean -C ./mlx

re: fclean all 

.PHONY: all clean fclean re bonus
