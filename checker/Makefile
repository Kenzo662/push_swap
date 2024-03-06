CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

NAME = checker

SRCS = checker.c lst_utils.c utils.c r_reverse_instructions.c reverse_instructions.c swap_push_instructions.c init.c check_args.c

OBJ = $(SRCS:.c=.o)

all     :   $(NAME)

$(NAME) :   $(OBJ)
	$(MAKE) -C ../libft
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L../libft/ -lft
clean   :
	$(MAKE) -C ../libft clean
	rm -rf $(OBJ)
fclean  :   clean
	rm -f $(NAME)
	
re      :   fclean all

.PHONY  :   clean fclean all re