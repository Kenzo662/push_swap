#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>


typedef struct s_node
{
    int nb;
    struct s_node  *next;
    struct s_node  *prev;
}               t_node;

#endif