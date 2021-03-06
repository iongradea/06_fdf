# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igradea <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 15:08:53 by igradea           #+#    #+#              #
#    Updated: 2017/10/25 18:42:26 by igradea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

FLAGS_MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit

CC = gcc

SRC = main.c ch_in_err.c parser.c display.c proj.c draw.c \
	  keyhook.c

SRCS = $(addprefix ./src/, $(SRC))
OBJS = $(addprefix ./src/, $(SRC:.c=.o))

LIBFT = -L./libft -lft

LIBFT_PATH = ./libft

MLX_PATH = ./mlx

all: $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $< -o $@ 

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
