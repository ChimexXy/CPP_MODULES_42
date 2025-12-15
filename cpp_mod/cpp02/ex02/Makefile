NAME = Fixed
CCXXX = c++
CFLAGSXX = -Wall -Wextra -Werror -std=c++98
SRC = Makefile main.cpp Fixed.hpp Fixed.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS) Fixed.hpp
	$(CXX) $(CFLAGSXX) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)

re: fclean all