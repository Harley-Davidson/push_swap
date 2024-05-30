SRC	= 	push_swap.c			\
		stack_utils.c		\
		stack_utils2.c		\
		stack_utils3.c		\
		utils.c				\
		main.c				\
		sorting.c			\
		rules_rotate.c		\
		rules_swap_push.c	

OBJS	= ${SRC:.c=.o}

NAME	= push_swap

AR	= ar rcs

RM	= rm -f

LIB	= ranlib

GCC	= gcc

LIBFT_PATH = ./libft

CFLAGS	= 

all:	${NAME}

libft:	
	${MAKE} -C ${LIBFT_PATH}

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
$(NAME):	${OBJS} libft
	${CC} ${CFLAGS} ${OBJS} -L./libft -lft -o ${NAME}
		
clean:
	${RM} ${OBJS}
	${MAKE} -C ${LIBFT_PATH} clean
	
fclean:	clean
	${RM} ${NAME}
	${MAKE} -C ${LIBFT_PATH} fclean

	
re:	fclean all

.PHONY:	all clean fclean re libft
