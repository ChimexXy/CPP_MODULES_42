NAME = ScavTrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  ClapTrap.cpp main.cpp ScavTrap.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) ClapTrap.hpp ScavTrap.hpp
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
