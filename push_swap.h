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

typedef struct s_utils
{
    int    len_a;
    int    len_b;
    int    use_sa;
    int    use_sb;
    int    use_ra;
    int    use_rb;
    int    use_rra;
    int    use_rrb;
}               t_utils;

typedef struct s_data
{
    t_lst       *lsta;
    t_lst       *lstb;
    t_utils     utils;

}               t_data;


void     init_data(t_data *data);
t_lst    *init_lst_a(char **av, int ac, t_data *data);
void    print_lst(t_lst *lst);
void    print_all_lst(t_lst *lsta, t_lst *lstb);
t_lst   *push_front(t_lst *lst, int nb);
t_lst   *push_back(t_lst *lst, int nb);
t_lst   *pop_front(t_lst *lst);
t_lst   *pop_back(t_lst *lst);
void    check_args_value(char **av, int ac);
void    check_args_char(char **av, int ac);
int	    ft_strcmp(char *s1, char *s2);
void    check_number(char **av);
void    freetab(char **tab);
void    sa(t_lst *lst, t_data *data);
void    sb(t_lst *lst, t_data *data);
void    ss(t_data *data);
void    pb(t_data *data);
void    pa(t_data *data);
void    ra(t_data *data);
void    rb(t_data *data);
void    rr(t_data *data);
void    rra(t_data *data, t_lst *lsta);
void    rrb(t_data *data, t_lst *lstb);
void    rrr(t_data *data, t_lst *lsta, t_lst *lstb);




#endif