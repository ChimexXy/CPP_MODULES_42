NAME = Animal
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Animal.cpp  Cat.cpp  Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
HEADERS = WrongAnimal.hpp WrongCat.hpp Animal.hpp  Cat.hpp  Dog.hpp Brain.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADRS)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all