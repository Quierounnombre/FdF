# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:56:53 by vicgarci          #+#    #+#              #
#    Updated: 2023/03/04 18:49:20 by vicgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = libft_def/libftprintf.a
MLX42 = MLX42/libmlx42.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address -g3
MLXFLAGS = -lglfw -L "glwf" -D DEBUG=1
RM = rm -f

BLACK = \033[0;30m
RED =   \033[0;31m
GREEN = \033[0;32m
YELLOW =    \033[0;33m
BLUE  = \033[0;34m
MAGENTA =   \033[0;35m
CYAN =  \033[0;36m
LGRAY = \033[0;37m
DGRAY = \033[1;30m
LBLUE = \033[1;34m
LGREEN = \033[1;32m
LCYAN = \033[1;36m
LRED = \033[1;31m
LMAGENTA =\033[1;35m
LYELLOW = \033[1;33m
WHITE = \033[1;37m
RESET = \033[0m

FILES = src/main.c \
		src/parse.c \
		src/store_file.c \
		src/init_struct.c \
		src/store_line.c \
		src/free_map.c \
		src/free_struct.c \
		src/calc_len.c \
		src/init.c \
		src/ft_hooks.c \
		src/close_fdf.c \
		src/draw.c \
		src/get_iso_perspective.c \
		src/draw_lines.c \
		src/set_dimensions.c \
		src/load_angles.c \
		src/set_dark.c \
		src/select_perspective.c \
		src/hooks/a_hook.c \
		src/hooks/d_hook.c \
		src/hooks/w_hook.c \
		src/hooks/s_hook.c \
		src/hooks/z_hook.c \
		src/hooks/x_hook.c \
		src/hooks/h_hook.c \
		src/hooks/y_hook.c \
		src/hooks/u_hook.c \
		src/hooks/j_hook.c \
		src/hooks/i_hook.c \
		src/hooks/k_hook.c \
		src/hooks/left_hook.c \
		src/hooks/right_hook.c \
		src/hooks/space_hook.c \
		src/hooks/scroll_hook.c

OBJS = ${FILES:.c=.o}

all: mlx43 libft $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT) $(MLX42) $(MLXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(LBLUE)\nFDF compilado con éxito\n$(RESET)"

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libft_def
	$(MAKE)	clean -C ./MLX42

fclean: clean
	$(MAKE) fclean -C ./libft_def
	$(RM) $(NAME) $(MLX42)


re: fclean libft mlx43 $(NAME)

#NOMBRE IGUAL A NOMBRE DE CARPETA CACA
mlx43:
	$(MAKE) -C ./MLX42

libft:
	$(MAKE) -C ./libft_def

.PHONY: all clean fclean re libft mlx43
