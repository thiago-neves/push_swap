NAME	=	push_swap
SRCS	=	src/push_swap.c				src/swap.c				src/push.c				\
			src/set_stacks.c			src/rotate.c			src/reverse_rotate.c	\
			src/verification.c			src/close.c				src/utils.c
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
