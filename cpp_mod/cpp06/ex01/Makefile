NAME = Serializer
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Serializer.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS) Serializer.hpp data.hpp
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all 	