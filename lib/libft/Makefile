NAME	= libft.a
CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -c

SRCS_LIB	= ft_strlen.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_bzero.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_memset.c \
		  ft_atoi.c \
		  ft_split.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_isascii.c \
		  ft_isalnum.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_isprint.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_striteri.c 

SRCBONUS = 	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

SRC_GNL = get_next_line.c get_next_line_utils.c

OBJ_PATH = objs

SRCS_PATH = src

#OBJSBONUS	= ${SRCBONUS:.c=.o}

GNLDIR = gnl

LIBFTDIR = lib

INC_PATH = inc

OBJS_DIRS = $(addprefix $(OBJ_PATH)/, $(LIBFTDIR)) \
 			$(addprefix $(OBJ_PATH)/, $(GNLDIR)) 

SRCS_PATHS = $(addprefix $(LIBFTDIR)/, $(SRCS_LIB))\
		   $(addprefix $(GNLDIR)/, $(SRC_GNL))

OBJS_PATHS	= ${SRCS_PATHS:.c=.o}

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_PATHS))

OBJS  = $(addprefix $(OBJ_PATH)/, $(OBJS_PATHS))

RM		= rm -f

all: ${NAME}

${OBJ_PATH}/%.o: ${SRCS_PATH}/%.c | ${OBJS_DIRS}
	${CC} ${CFLAGS} -D BUFFER_SIZE=32 $< -o $@ -I ${INC_PATH}

$(NAME) : ${OBJS} ${OBJS_DIRS}
	ar rc ${NAME} ${OBJS}

$(OBJS_DIRS):
	mkdir -p $(OBJS_DIRS) 2> /dev/null

clean:
		@${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
		@${RM} ${NAME}

bonus:	${NAME} ${OBJSBONUS}
		@ar rc ${NAME} ${OBJSBONUS}

re:		fclean all

.PHONY:		clean re fclean bonus all
