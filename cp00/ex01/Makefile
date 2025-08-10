CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook
SRC = phonebook.cpp
OBJ = $(OBJ:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ) phonebook.hpp phonebook.h
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re: fclean re