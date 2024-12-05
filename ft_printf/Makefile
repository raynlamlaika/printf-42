CC = cc  

NAME = libftprintf.a 

CFLAGS= -Wall -Wextra -Werror 

AR = ar rc

SRC = ft_toupper.c ft_utils.c ft_printf.c ft_putunsigned.c ft_strchr.c
HEADER = ft_printf.h

OBJ = ${SRC:.c=.o}

all: ${NAME} 

${NAME}: ${OBJ}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@ 
	${AR} ${NAME} $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all