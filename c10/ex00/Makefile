NAME = ft_display_file

SRCS = ./srcs/ft_display_file.c

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

re: fclean clean

.PHONY: all clean fclean re