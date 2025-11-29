NAME = zombie
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = newZombie.cpp randomChump.cpp Zombie.cpp main.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -rf $(OBJS)
fclean:
	rm -rf $(NAME)
re: fclean all
