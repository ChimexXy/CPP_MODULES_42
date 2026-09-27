CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone
SRC = megaphone.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all

