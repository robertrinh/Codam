# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: robertrinh <robertrinh@student.codam.nl      +#+                      #
#                                                    +#+                       #
#    Created: 2025/04/14 17:02:30 by robertrinh    #+#    #+#                  #
#    Updated: 2025/04/21 17:17:10 by robertrinh    ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME:= bureaucrat
CC:= c++
FLAGS:= -Wall -Wextra -Werror -std=c++11
OBJDIR := objects
HDR_FILES := Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
SRC_FILES := Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
SRC := $(addprefix src/, $(SRC_FILES)) main.cpp
HDR := $(addprefix include/, $(HDR_FILES))
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