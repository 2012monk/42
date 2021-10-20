NAME = ft_tail

DIR = ./srcs/

SRCS = ${wildcard ./srcs/*.c}

# SRCS = ${addprefix ${DIR}, ${SRC}}

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} -o $@ $^

all: ${NAME}

clean:
	${RM} ${OBJS} 

fclean: 
	${RM} ${NAME}

.PHONY: all clean fclean e