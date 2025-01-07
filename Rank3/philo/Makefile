# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: robertrinh <robertrinh@student.codam.nl      +#+                      #
#                                                    +#+                       #
#    Created: 2025/01/07 18:12:23 by robertrinh    #+#    #+#                  #
#    Updated: 2025/01/07 18:14:12 by robertrinh    ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := philo

CC := gcc
CFLAGS := -Wall -Werror -Wextra -g #gflag for debug
HEADER := include/philo.h
INCLUDE := -I include
OBJDIR = objects

SRC := 	philo.c \
#init_bruv.c \
		main.c \
		parse.c \
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

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "${RED}compiling? ${BOLD_GREEN}completed it mate ${END_COLOUR}"

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJDIR)
	@echo "${RED} Socrates.. ${GRAY}Freud..${YELLOW}Davinci.. ${PURPLE}SPAGHETTI MONSTER...${END_COLOUR}"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)
	@echo "${BOLD_RED}And so they have gone in their caves.. only to philosophise some more ${END_COLOUR}"

fclean: clean
	@rm -f $(NAME)
	@echo "${BOLD_GREEN}we out here ${END_COLOUR}"

re: fclean all

.PHONY: all clean fclean re