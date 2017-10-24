# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igradea <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 15:08:53 by igradea           #+#    #+#              #
#    Updated: 2017/10/24 15:09:08 by igradea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror -g

FLAGS_MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit

CC = gcc

SRCS = ./src/main.c\
	   ./src/ft_display.c\
	   ./src/ft_draw.c\
	   ./src/ft_parse.c\
	   ./src/get_next_line.c\
	   ./src/ft_proj.c\
	   ./src/valid_map.c\
	   ./src/key_hook.c\

OBJS = $(SRCS:.c=.o)

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

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
