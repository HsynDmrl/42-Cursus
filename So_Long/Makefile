SRC = map.c map2.c map3.c control.c control2.c move.c path_control.c so_long.c path_control_utils.c control3.c
CFLAGS = -Wall -Wextra -Werror -framework AppKit -framework OpenGL
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
MLX = ./minilibx_opengl_20191021/libmlx.a
PRINTF = ./ft_printf/libftprintf.a
NAME = so_long
CC = gcc
DEL = rm -f
CD = cd

all: ${NAME}

${NAME}: ${SRC} ${MLX} ${PRINTF}
	@${CC} $(CFLAGS) ${GNL} ${PRINTF} ${SRC} ${MLX} -o ${NAME}

${MLX}:
	@${CD} minilibx_opengl_20191021 && make all

${PRINTF}:
	@${CD} ft_printf && make all

clean:
	@${CD} minilibx_opengl_20191021 && make clean
	@${CD} ft_printf && make clean
	@${DEL} ${NAME}

fclean: clean
	@${CD} ft_printf && make fclean

re: fclean all

.PHONY: all clean fclean re