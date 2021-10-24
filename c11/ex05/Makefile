TARGET = do-op

DIR = ./srcs/

SRCS = ${wildcard ${DIR}*.c}

OBJS = ${SRCS:.c=.o}

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} -o $@ $^

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${TARGET}

re: fclean all

.POHNY: clean fclean all re