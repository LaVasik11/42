NAME = phonebook
SRC = main.cpp Contact.cpp PhoneBook.cpp
OBJ = ${SRC:.cpp=.o}
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean flcean re
