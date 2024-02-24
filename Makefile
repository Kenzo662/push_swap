CC = gcc

CFLAGS = -Wall -Wextra -g3

NAME = push_swap

SRCS = push_swap.c init.c swap_push_instructions.c reverse_instructions.c r_reverse_instructions.c args_error.c utils.c lst_utils.c \
check_args.c

OBJ = $(SRCS:.c=.o)

all     :   $(NAME)

$(NAME) :   $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./libft/ -lft
clean   :
	$(MAKE) -C libft clean
	rm -rf $(OBJ)
fclean  :   clean
	rm -f $(NAME)
	
re      :   fclean all

.PHONY  :   clean fclean all re