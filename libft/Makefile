# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igradea <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 19:01:51 by igradea           #+#    #+#              #
#    Updated: 2017/10/25 18:43:15 by igradea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

# Source files
SRC := ft_realloc.c ft_isspace.c	ft_isupper.c ft_islower.c	\
			ft_isalpha.c ft_isdigit.c	ft_isalnum.c ft_isascii.c	\
			ft_isprint.c ft_toupper.c	ft_tolower.c ft_memset.c	\
			ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c	\
			ft_memchr.c ft_memcmp.c ft_memalloc.c	ft_memdel.c	\
			ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c	\
			ft_strcat.c ft_strncat.c ft_strlcat.c	ft_strchr.c	\
			ft_strrchr.c ft_strstr.c ft_strnstr.c	ft_strcmp.c	\
			ft_strncmp.c ft_atoi.c ft_strnew.c ft_strdel.c	\
			ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c	\
			ft_strmapi.c ft_strequ.c ft_strnequ.c	ft_strsub.c	\
			ft_strjoin.c ft_strtrim.c	ft_strsplit.c ft_strndup.c \
			ft_itoa.c	ft_putchar.c ft_putstr.c ft_putendl.c	\
			ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c	\
			ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c	\
			ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
			ft_sqrt.c ft_abs.c ft_max.c ft_print_memory.c ft_itoa_base.c \
			ft_strnjoin.c ft_min.c ft_tablen.c get_next_line.c \
			ft_atoi_max_int.c

# Directories
SRC_DIR := src
OBJ_DIR := bin

# Flags, libraries, include
# Several compile modes are defined: no flags, debug, standard
ifdef MODE
ifeq ($(MODE), no)
endif
ifeq ($(MODE), debug)
	CFLAGS = -g3 -fsanitize=address
endif
else
	CFLAGS = -Wall -Wextra -Werror
endif

# Variables
OBJ := $(SRC:.c=.o)

all: $(NAME)

# Compiling .o files and creates .d files
# The last 4 lines modify the .d files in order to make it work when 
# .o files are in a subdirectory
./$(OBJ_DIR)/%.o: ./$(SRC_DIR)/%.c 
	@/bin/mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) -c $< -o $@

# Creates library and index
$(NAME): $(addprefix ./$(OBJ_DIR)/, $(OBJ))
	ar rc $(NAME) $(addprefix ./$(OBJ_DIR)/, $(OBJ))
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

# Non-file targets
.PHONY: all, re, clean, fclean
