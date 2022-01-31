NAME	=	push_swap
SRCS	=	src/push_swap.c				src/actions/swap.c		src/actions/push.c				\
			src/utils/set_stacks.c		src/actions/rotate.c	src/actions/reverse_rotate.c	\
			src/utils/verification.c	src/utils/close.c		src/utils/utils.c
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
NORM	=	norminette inc/*.h && norminette src/*.c
OBJS	=	$(SRCS:%.c=%.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

n		:
			$(NORM)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
