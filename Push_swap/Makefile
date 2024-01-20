SRC = error.c index.c main.c radix.c rules.c rules1.c sorts.c utils.c\

LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror
NAME = push_swap

all: ${NAME}

${NAME}: ${SRC} ${LIBFT}
	@echo "Push Swap Loading..."
	@gcc $(FLAGS) $(SRC) $(LIBFT) -o ${NAME}
	@echo "Done!"

${LIBFT}:
	@echo "Libft Loading..."
	@cd libft && make all

clean:
	@echo "Libft Cleaning..."
	@cd libft && make clean
	@echo "Push Swap Cleaning..."
	@rm -fr push_swap
	@echo "Done!"

fclean: clean
	@echo "Libft Full Cleaning..."
	@cd libft && make fclean
	@echo "Push Swap Full Cleaning..."
	@echo "Done!"

re: fclean all

.PHONY: all clean fclean re