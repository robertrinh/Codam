# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/05 15:27:07 by qtrinh        #+#    #+#                  #
#    Updated: 2025/03/06 14:16:19 by robertrinh    ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME:= diamondtrap
CC:= c++
FLAGS:= -Wall -Wextra -Werror -Wshadow -std=c++11 
#Wshadow -> warning compiler: variable declaration shadows another variable with the same name in an outer scope
OBJDIR := objects
HDR := ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
SRC := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
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