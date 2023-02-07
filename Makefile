# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:56:53 by vicgarci          #+#    #+#              #
#    Updated: 2023/02/07 16:41:49 by vicgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
LIBFT = libft_def/libftprintf.a
MLX42 = MLX42/libmlx42.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
MLXFLAGS = -lglfw -L "/Users/vicgarci/.brew/opt/glfw/lib/" -D DEBUG=1
RM = rm -f

FILES = main.c \
		parse.c \
		store_file.c \
		init_struct.c \
		store_line.c \
		free_map.c \
		free_struct.c \
		calc_len.c \
		init.c \
		ft_hooks.c \
		close_fdf.c

OBJS = ${FILES:.c=.o}

all: mlx43 libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(MLX42) $(MLXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libft_def
	$(MAKE)	clean -C ./MLX42

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(MLX42)


re: fclean libft mlx43 $(NAME)

#NOMBRE IGUAL A NOMBRE DE CARPETA CACA
mlx43:
	$(MAKE) -C ./MLX42

libft:
	$(MAKE) -C ./libft_def


norma:
	@echo 6966205b5b2024286e6f726d696e65747465207c206772657020274572726f7227207c207763202d6c29202d65712030205d5d3b207468656e206e6f726d696e657474653b20656c736520286e6f726d696e65747465207c206772657020274572726f7227293b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re libft norma
