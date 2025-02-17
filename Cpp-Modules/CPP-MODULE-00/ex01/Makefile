NAME = phonebook

SRC = Main.cpp \
	  Contact.cpp \
	  PhoneBook.cpp \

CC = C++

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -fr

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	
re: fclean all

.PHONY: all clean fclean re