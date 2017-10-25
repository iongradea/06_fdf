# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igradea <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 15:08:53 by igradea           #+#    #+#              #
#    Updated: 2017/10/25 16:58:23 by igradea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

FLAGS_MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit

CC = gcc

SRC = main.c 0_ch_in_err.c 1_parser.c 2_display.c 21_proj.c 22_draw.c \
	  23_keyhook.c

SRCS = $(addprefix ./src/, $(SRC))
OBJS = $(addprefix ./src/, $(SRC:.c=.o))

LIBFT = -L./libft -lft

LIBFT_PATH = ./libft

MLX_PATH = ./mlx

all: $(NAME)

$(NAME):$(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(FLAGS_MLX) $(LIBFT)

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
