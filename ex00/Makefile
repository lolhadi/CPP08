NAME	= easyfind

CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

SRCS	=  main.cpp

OBJS	= $(SRCS:.cpp=.o)

GREEN	= \033[32m
RED		= \033[31m
RESET	= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
		@echo "$(GREEN) $(NAME), Great news, It Compiled! $(RESET)"

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
		@echo "$(RED) Object .o files are gone dy! $(RESET)"

fclean: clean
		$(RM) $(NAME)
		@echo "$(RED)Executeies are removed $(RESET)"

re: fclean all

.PHONY: all clean fclean re
