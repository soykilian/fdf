NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -c
SRCS = ft_printf.c  ft_printf_utils.c ft_printf_hex.c
OBJS	= ${SRCS:.c=.o}
RM		= rm -f

all: ${NAME}

%o: %c
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	@ar rc ${NAME} ${OBJS}

clean:
		@${RM} ${OBJS}

fclean:		clean
		@${RM} ${NAME}
re:		fclean all
.PHONY:		clean re fclean bonus all

