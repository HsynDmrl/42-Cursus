LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRV	= server.c
CLT = client.c
NAME = server
NAME2 = client
SRVBONUS = server_bonus.c
CLTBONUS = client_bonus.c
NAMEBONUS = server_bonus
NAME2BONUS = client_bonus

all: ${NAME} ${NAME2}

${NAME}: ${SRV} ${LIBFT}
	gcc $(FLAGS) $(SRV) $(LIBFT) -o ${NAME}

${NAME2}: ${CLT} ${LIBFT}
	gcc $(FLAGS) $(CLT) $(LIBFT) -o ${NAME2}
	@echo "Loading...Done!"

${LIBFT}:
	@cd libft && make all

bonus: ${NAMEBONUS} ${NAME2BONUS}

${NAMEBONUS}: ${SRVBONUS} ${LIBFT}
	gcc $(FLAGS) $(SRVBONUS) $(LIBFT) -o ${NAMEBONUS}

${NAME2BONUS}: ${CLTBONUS} ${LIBFT}
	gcc $(FLAGS) $(CLTBONUS) $(LIBFT) -o ${NAME2BONUS}
	@echo "Bonus Loading...Done!"

clean:
	@cd libft && make clean
	@rm -fr server client server_bonus client_bonus

fclean: clean
	@cd libft && make fclean

re: fclean all

.PHONY: all bonus clean fclean re