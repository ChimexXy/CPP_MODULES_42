NAME = Harl
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Harl.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all