CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook
SRC = phonebook.cpp contact.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ) phonebook.hpp
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re: fclean re