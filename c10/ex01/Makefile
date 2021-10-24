NAME = ft_cat

DIR = ./srcs/

SRCS = ${wildcard ./srcs/*.c}

OBJS = ${SRCS:.c=.o}

INC = ./includes/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -I ${INC} -c $< -o $@

${NAME}: ${OBJS}
	${CC} -o $@ $^

all: ${NAME}

clean:
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re 
