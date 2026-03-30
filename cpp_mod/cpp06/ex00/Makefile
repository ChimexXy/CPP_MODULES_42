NAME = convert
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS) ScalarConverter.hpp
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:	
	rm -rf $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
