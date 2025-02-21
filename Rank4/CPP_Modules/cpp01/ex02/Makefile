# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: robertrinh <robertrinh@student.codam.nl      +#+                      #
#                                                    +#+                       #
#    Created: 2025/02/12 17:25:39 by robertrinh    #+#    #+#                  #
#    Updated: 2025/02/18 18:47:37 by robertrinh    ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME:= brain
CC:= c++
FLAGS:= -Wall -Wextra -Werror -std=c++98
OBJDIR := objects
SRC := main.cpp
OBJS := $(SRC:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) 
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