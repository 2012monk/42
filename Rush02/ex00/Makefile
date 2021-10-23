TARGET = rush-02

DIR = ./srcs/

SRC = ${wildcard *.c}

SRCS = ${addprefix ${DIR}, ${SRC}}

OBJ = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${TARGET}: ${OBJ}
	${CC} -o ${NAME} ${OBJ}

all: ${TARGET}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re