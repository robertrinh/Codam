# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/08/30 18:26:49 by qtrinh        #+#    #+#                  #
#    Updated: 2023/10/26 15:02:06 by qtrinh        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := fractol
CC := cc
CFLAGS := -Wall -Werror -Wextra
INCLUDE := -I ./include -I libft/include -I MLX42/source/include/MLX42
OBJDIR := objects
LIBFT := libft/libft.a

# MLX stuff
MLX42_BUILD_DIR = MLX42/build/
MLX_LIB := MLX42/build/libmlx42.a

ifeq ($(shell uname -s),Linux)
LINKERS = -Iinclude -ldl -lglfw -pthread -lm
else ifeq ($(shell uname -s), Darwin)
LINKERS = -framework Cocoa -framework OpenGL -framework IOKit -lglfw3
endif

SRC :=	check.c \
		init_bruv.c \
		main.c \
		utils.c \

vpath %.c	src
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

#COLORS SHOW
BOLD_GREEN=\033[1;92m
BOLD_RED=\033[1;91m
RED=\033[0;31m
PURPLE=\033[0;35m
YELLOW=\033[0;33m
GRAY=\033[0;37m
INTENSE_CYAN=\033[0;96m
END_COLOUR=\033[0m

all: libft $(NAME)

$(NAME):  $(MLX_LIB) $(LIBFT) $(OBJ)
	@$(CC) $(INCLUDE) $(CFLAGS) -o $@ $(OBJ) $(LIBFT) $(MLX_LIB)
	@echo "${BOLD_RED}Are we ready ${BOLD_GREEN}to do some ${YELLOW}political debates?!${END_COLOUR}"

$(MLX_LIB):
	@git submodule update --init --recursive
	@cmake ./MLX42 -B $(MLX42_BUILD_DIR) && make -C $(MLX42_BUILD_DIR) -j4

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

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(OBJDIR)
	@rm -rf $(NAME)
	@rm -rf $(MLX42_BUILD_DIR)

re:	fclean all

module-update:
	@git submodule update --remote --merge

.PHONY: all clean fclean re libmlx
