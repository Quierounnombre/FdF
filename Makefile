# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:56:53 by vicgarci          #+#    #+#              #
#    Updated: 2022/11/22 20:56:36 by vicgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
LIBFT = libft_def/libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -fsanitize=address
RM = rm -f

FILES = main.c \
		parse.c \
		store_file.c \
		init_struct.c \
		store_line.c \
		free_map.c \
		free_struct.c \
		calc_line_size.c

OBJS = ${FILES:.c=.o}

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libft_def

fclean: clean
	$(RM) $(NAME) $(LIBFT)


re: fclean libft $(NAME)

libft:
	$(MAKE) -C ./libft_def

norma:
	@echo 6966205b5b2024286e6f726d696e65747465207c206772657020274572726f7227207c207763202d6c29202d65712030205d5d3b207468656e206e6f726d696e657474653b20656c736520286e6f726d696e65747465207c206772657020274572726f7227293b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re libft norma