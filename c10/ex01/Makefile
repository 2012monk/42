NAME = ft_cat

DIR = ./srcs/

INC = ./includes/

SRC = ft_cat.c do_cat.c

SRCS = ${addprefix ${DIR}, ${SRC}}

OBJS = ${SRCS:.c=.o}

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
	${RM} $@

.PHONY: all clean fclean