#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>


typedef struct s_lst
{
    int nb;
    struct s_lst  *next;
}               t_lst;

typedef struct s_data
{
    t_lst *lsta;
    t_lst *lstb;
}           t_data;


t_lst   *init_lst_a(char **av, int ac);
void    print_lst(t_lst *lst);
void    print_all_lst(t_lst *lsta, t_lst *lstb);
t_lst   *push_front(t_lst *lst, int nb);
void    check_args_value(char **av, int ac);
void    check_args_char(char **av, int ac);
int	    ft_strcmp(char *s1, char *s2);
void    check_number(char **av);
void    sa(t_lst *lst);
void    sb(t_lst *lst);
void    ss(t_data *data);
void    pb(t_data *data);
void    pa(t_data *data);



#endif