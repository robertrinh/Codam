# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/04 17:09:25 by qtrinh        #+#    #+#                  #
#    Updated: 2023/08/03 16:08:38 by robertrinh    ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
NAME := libft.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror
AR := ar rcs
INCLUDE := -I ./include

SRC_CHARACTER = ./character/ft_isalnum.c ./character/ft_isalpha.c ./character/ft_isascii.c ./character/ft_isdigit.c ./character/ft_isprint.c ./character/ft_tolower.c ./character/ft_toupper.c
SRC_LIST = ./linked_list/ft_lstnew.c ./linked_list/ft_lstadd_front.c ./linked_list/ft_lstsize.c ./linked_list/ft_lstlast.c ./linked_list/ft_lstadd_back.c ./linked_list/ft_lstdelone.c ./linked_list/ft_lstclear.c ./linked_list/ft_lstiter.c ./linked_list/ft_lstmap.c
SRC_MEMORY = ./memory/ft_bzero.c ./memory/ft_calloc.c ./memory/ft_memchr.c ./memory/ft_memcmp.c ./memory/ft_memcpy.c ./memory/ft_memmove.c ./memory/ft_memset.c
WRITE = ./write/ft_putchar_fd.c ./write/ft_putstr_fd.c ./write/ft_putendl_fd.c ./write/ft_putnbr_fd.c
SRC_STRING = ./string/ft_strchr.c ./string/ft_strdup.c ./string/ft_strlcat.c ./string/ft_strlcpy.c ./string/ft_strlen.c ./string/ft_strncmp.c ./string/ft_strnstr.c ./string/ft_strrchr.c ./string/ft_substr.c ./string/ft_strjoin.c ./string/ft_strtrim.c ./string/ft_strmapi.c ./string/ft_striteri.c ./string/ft_atoi.c ./string/ft_ayetoi.c ./string/ft_itoa.c ./string/ft_split.c
SRC_GET_NEXT_LINE = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

SRC += $(SRC_CHARACTER) $(SRC_LIST) $(SRC_MEMORY) $(SRC_WRITE) $(SRC_STRING) $(SRC_GET_NEXT_LINE)

OBJDIR = objects
OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

DIRECTORY = $(dir $(SRC))
SPLIT = $(DIRECTORY:/=)
CAT = $(addprefix $(OBJDIR)/, $(DIRECTORY))

#COLORS SHOW
BOLD_GREEN=\033[1;92m
BOLD_RED=\033[1;91m
RED=\033[0;31m
PURPLE=\033[0;35m
YELLOW=\033[0;33m
GRAY=\033[0;37m
INTENSE_CYAN=\033[0;96m
END_COLOUR=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "    __    ________  ____________                       __      __"
	@echo "   / /   /  _/ __ )/ ____/_  __/  ________  ____ _____/ /_  __/ /"
	@echo "  / /    / // __  / /_    / /    / ___/ _ \/ __  / __  / / / / / "
	@echo " / /____/ // /_/ / __/   / /    / /  /  __/ /_/ / /_/ / /_/ /_/  "
	@echo "/_____/___/_____/_/     /_/    /_/   \___/\__,_/\__,_/\__, (_)   "
	@echo "                                                     /____/      "

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:%.c | $(OBJDIR)
	@mkdir -p $(CAT)
	@echo "${RED} compiling ${GRAY}libft.. ${PURPLE}bliep.. bloep.. ${INTENSE_CYAN}$<${YELLOW}ccccc ${END_COLOUR}"
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "${BOLD_RED}THANOS SNAPPED! ${GRAY}Spider senses tingling...$(END_COLOUR)"

fclean: clean
	@rm -f $(NAME)
	@echo "${RED}Mister stark, I don't feel so good.. $(INTENSE_CYAN)LIBFT DISSOLVED insert sad emoji $(END_COLOUR)"

re: fclean all

