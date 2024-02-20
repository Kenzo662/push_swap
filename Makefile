CC = gcc

CFLAGS = -Wall -Wextra -g3

NAME = push_swap

SRCS = push_swap.c

OBJ = $(SRCS:.c=.o)

all     :   $(NAME)

$(NAME) :   $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
clean   :
	$(MAKE) -C libft clean
	rm -rf $(OBJ)
fclean  :   clean
	rm -f $(NAME)
	
re      :   fclean all

.PHONY  :   clean fclean all re