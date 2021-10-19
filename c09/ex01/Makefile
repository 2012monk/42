NAME = libft.a

DIR = ./srcs/

SRC= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

SRCS = ${addprefix ${DIR}, ${SRC}}

OBJS = ${SRCS:.c=.o}

INC = ./includes/

AR = ar rcs

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c -I ${INC} $< -o $@

${NAME}:	${OBJS}
	${AR} $@ ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re