# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/05 15:27:07 by qtrinh        #+#    #+#                  #
#    Updated: 2025/05/10 17:13:23 by robertrinh    ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME:= scalarconverter
CC:= c++
FLAGS:= -Wall -Wextra -Werror -std=c++11
OBJDIR := objects
HDR := ScalarConverter.hpp
SRC := main.cpp ScalarConverter.cpp
OBJS := $(SRC:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(HDR)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(OBJDIR)/%.o : %.cpp
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

.PHONY: clean fclean re