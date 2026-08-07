NAME = bsp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJS = $(SRC:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re