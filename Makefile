CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap

SRCS = push_swap.c init.c swap_push_instructions.c reverse_instructions.c r_reverse_instructions.c utils.c lst_utils.c \
check_args.c algorithm.c algorithm_utils.c execute.c find.c define.c 

OBJ = $(SRCS:.c=.o)

all     :   $(NAME)

$(NAME) :   $(OBJ)
	$(MAKE) -C libft
	$(MAKE) -C checker
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./checker/ -L./libft/ -lft
clean   :
	$(MAKE) -C libft fclean
	$(MAKE) -C checker fclean
	rm -rf $(OBJ)
fclean  :   clean
	rm -f $(NAME)
	
re      :   fclean all

.PHONY  :   clean fclean all re