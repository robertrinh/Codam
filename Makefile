# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/04 17:09:25 by qtrinh        #+#    #+#                  #
#    Updated: 2022/11/18 16:23:27 by qtrinh        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
NAME := libft.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror
AR := ar -src

SRCS := ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \

BSRCS := ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \

OBJ := $(SRCS:.c=.o)
OBJ_B := $(BSRCS:.c=.o)

ifdef WITH_BONUS
OBJ_FILES = $(OBJ) $(OBJ_B)
else
OBJ_FILES = $(OBJ)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(AR) $(NAME) $(OBJ_FILES)
	@echo "compiling? completed it mate"

%.o: %.c 
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_B)

fclean: clean
	@rm -f $(NAME)
	@echo "libft? libft...? LIBFT!!!!!"

re: fclean all bonus

bonus:
	@$(MAKE) WITH_BONUS=1 all
	