# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/25 15:46:02 by qtrinh        #+#    #+#                  #
#    Updated: 2022/12/07 16:53:45 by qtrinh        ########   odam.nl          #
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

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@cd Libft && $(MAKE)
	@cp ./Libft/libft.a $(NAME)
	#niet vergeten om terug erin te doen

%.o:%.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C ./Libft

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./Libft

re: fclean all

.PHONY: all clean fclean re