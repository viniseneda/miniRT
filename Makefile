SRCS	= main.c\
			math_1.c math_2.c math_3.c\
			intersections_1.c intersections_2.c intersections_3.c intersections_4.c intersections_5.c\
			matrix_1.c matrix_2.c matrix_3.c matrix_4.c\
			parser_1.c parser_2.c parser_3.c parser_4.c parser_5.c parser_6.c parser_7.c\
			scene.c\
			shading_1.c shading_2.c shading_3.c shading_4.c\
			transformations_1.c transformations_2.c\
			libx.c
OBJS	= ${SRCS:.c=.o}

CC	= cc

CFLAGS = -Wall -Werror -Wextra

NAME	= a.out

.c.o:
	make -C ./libft all
	${CC} ${CFLAGS} -c ${SRCS}

RM	= rm -f

$(NAME):	${OBJS}
	cc ${OBJS} -L./libft -lft -L. -lmlx_Linux -lXext -lX11 -lm -lz

install:
	sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev

all:	$(NAME)

clean:
	${RM} ${OBJS}
	make -C ./libft clean

fclean:	clean
	${RM} ${NAME}
	make -C ./libft fclean

re:	fclean all

.PHONY: 	all clean fclean
