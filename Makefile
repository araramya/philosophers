NAME = philo
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c helpers.c initilize.c philo.c threads.c
OBJS = ${SRCS:.c=.o}

all:  ${NAME}

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		rm -rf ${OBJS}

fclean: clean
	${RM} ${NAME}

re : fclean all


.PHONY: all clean fclean re