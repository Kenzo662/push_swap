SRCS = ft_atoi.c ft_itoa.c ft_putendl_fd.c	ft_strlcat.c  ft_substr.c\
ft_bzero.c    ft_putnbr_fd.c	ft_strlcpy.c  ft_tolower.c\
ft_calloc.c   ft_memchr.c      ft_putstr_fd.c	ft_strlen.c   ft_toupper.c\
ft_isalnum.c  ft_memcmp.c      ft_split.c	ft_strmapi.c \
ft_isalpha.c  ft_memcpy.c      ft_strchr.c	ft_strncmp.c \
ft_isascii.c  ft_memmove.c     ft_strdup.c	ft_strnstr.c \
ft_isdigit.c  ft_memset.c      ft_striteri.c	ft_strrchr.c\
ft_isprint.c  ft_putchar_fd.c  ft_strjoin.c	ft_strtrim.c \
ft_printf.c   ft_countnb.c     ft_integer.c \
gnl.c 		  gnlutils.c	   ft_atol.c \

SRCSBNS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

SRCSOBJS = $(SRCSBNS:.c=.o)

NAME = libft.a

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS) $(SRCSOBJS)
	ar rcs $(NAME) $(OBJS) $(SRCSOBJS)

clean : 
	$(RM) $(OBJS) $(SRCSOBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : $(OBJS) $(SRCSOBJS)
	ar rcs $(NAME) $(OBJS) $(SRCSOBJS)
