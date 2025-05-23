NAME:= serializer
CC:= c++
FLAGS:= -Wall -Wextra -Werror -std=c++11
OBJDIR := objects
HDR := Serializer.hpp
SRC := main.cpp Serializer.cpp
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