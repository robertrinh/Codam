# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/08/30 18:26:49 by qtrinh        #+#    #+#                  #
#    Updated: 2023/08/30 18:31:51 by qtrinh        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := fractol
CC := gcc
CFLAGS := -Wall -Werror -Wextra
HEADER := -I include
OBJDIR = objects
MLX = MLX42/build/libmlx42.a
LIBFT = libft/libft.a

LIBS = MLX42/build/libmlx42.a libft/libft.a


#COLORS SHOW
BOLD_GREEN=\033[1;92m
BOLD_RED=\033[1;91m
RED=\033[0;31m
PURPLE=\033[0;35m
YELLOW=\033[0;33m
GRAY=\033[0;37m
INTENSE_CYAN=\033[0;96m
END_COLOUR=\033[0m
