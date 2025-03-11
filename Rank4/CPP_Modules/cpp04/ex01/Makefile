# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/05 15:27:07 by qtrinh        #+#    #+#                  #
#    Updated: 2025/03/11 14:48:32 by qtrinh        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME:= animal
CC:= c++
FLAGS:= -Wall -Wextra -Werror -std=c++11
OBJDIR := objects
HDR := Animal.hpp Cat.hpp Dog.hpp Brain.hpp
SRC := main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
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

.PHONY: clean fclean re