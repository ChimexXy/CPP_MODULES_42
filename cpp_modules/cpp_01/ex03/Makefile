NAME = Weapon
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = HumanA.cpp  HumanB.cpp Weapon.cpp  main.cpp
HEAD = HumanB.hpp Weapon.hpp HumanA.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)

re: fclean all 