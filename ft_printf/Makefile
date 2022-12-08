# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/25 15:46:02 by qtrinh        #+#    #+#                  #
#    Updated: 2022/12/08 14:29:15 by qtrinh        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := gcc
CFLAGS := -Wall -Werror -Wextra
AR := ar -src

SRCS := ft_printf.c \
		ft_printf_hex.c \
		ft_printf_pointer.c \
		ft_printf_stuff.c \
		ft_printf_unsigned.c \

OBJ := $(SRCS:.c=.o)

BOLD_GREEN=\033[1;92m
RED=\033[0;31m
BOLD_RED=\033[1;91m
INTENSE_CYAN=\033[0;96m
END_COLOUR=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@cd Libft && $(MAKE)
	@cp ./Libft/libft.a $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "${RED}compiling? ${BOLD_GREEN} Completed it mate ${END_COLOUR}"

%.o:%.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C ./Libft

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./Libft
	@echo "${INTENSE_CYAN}library..? ${BOLD_GREEN}LIBRARY..? ${BOLD_RED}LIBRARY!!!"

re: fclean all

.PHONY: all clean fclean re