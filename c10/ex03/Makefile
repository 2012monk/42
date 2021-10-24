NAME = ft_hexdump 

DIR = ./srcs/

SRCS = ${wildcard ./srcs/*.c}

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

fclean: clean 
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean e