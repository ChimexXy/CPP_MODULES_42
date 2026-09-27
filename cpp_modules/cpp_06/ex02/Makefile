NAME = Base
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Base.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS) Base.hpp
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all 	