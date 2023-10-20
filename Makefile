# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/08/30 18:26:49 by qtrinh        #+#    #+#                  #
#    Updated: 2023/10/20 15:58:38 by qtrinh        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := fractol
CC := cc
CFLAGS := -Wall -Werror -Wextra
MLX := MLX42/build/libmlx42.a
LIBFT := libft/libft.a
LIBMLX := ./MLX42
INCLUDE := -I ./include -I $(LIBMLX)/include
OBJDIR := objects

ifeq ($(shell uname -m),arm64)
LINKERS = -L/opt/homebrew/lib -lglfw -framework IOKit -framework Cocoa
else ifeq ($(shell uname -m),x86_64)
LINKERS = -lglfw3 -framework IOKit -framework Cocoa
endif

LIBS := $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm $(LINKERS)
SRC :=	main.c \

vpath %.c	src
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))
# OBJ := $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

#COLORS SHOW
BOLD_GREEN=\033[1;92m
BOLD_RED=\033[1;91m
RED=\033[0;31m
PURPLE=\033[0;35m
YELLOW=\033[0;33m
GRAY=\033[0;37m
INTENSE_CYAN=\033[0;96m
END_COLOUR=\033[0m

all: $(LIBMLX) $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBFT) $(LIBMLX) $(INCLUDE) $(LIBS)

$(MLX):
	@git submodule update --init --recursive
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	@git submodule update --init --recursive
	@$(MAKE) -C ./libft

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@echo "${RED} assembling ${GRAY}political fractions..${INTENSE_CYAN}$<${YELLOW}ccccc ${END_COLOUR}"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJDIR)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re libmlx
