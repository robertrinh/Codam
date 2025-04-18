# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: robertrinh <robertrinh@student.codam.nl      +#+                      #
#                                                    +#+                       #
#    Created: 2025/02/12 17:25:39 by robertrinh    #+#    #+#                  #
#    Updated: 2025/03/04 12:55:28 by qtrinh        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME:= phonebook
CC:= c++
FLAGS:= -Wall -Wextra -Werror -std=c++98
OBJDIR := objects
HDR := PhoneBook.hpp Contact.hpp
SRC := main.cpp PhoneBook.cpp Contact.cpp
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