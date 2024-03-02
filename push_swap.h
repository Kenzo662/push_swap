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
    int target;
    int pos;
    int last_pos;
    int pushcost;
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
    int    min;
    int    max;
    int    median_lsta;
    int    median_lstb;
    int    count;
}               t_utils;

typedef struct s_data
{
    t_lst       *lsta;
    t_lst       *lstb;
    t_utils     utils;

}               t_data;


void    check_argv(char **tab);
void    check_av_char(char **tab);

t_lst   *define_target(t_data *data, t_lst *lsta);
t_lst   *define_target_b(t_data *data, t_lst *lstb);
void    define_pos(t_lst *lst);
int     define_target_pos(int target, t_lst *lstb);
void    define_lastpos(t_lst *lst, int len_list);
void    define_pushcost(t_data *data, t_lst *lsta);

void    execute(t_data *data, t_lst *lsta);
void    execute_b(t_data *data, t_lst *lsta);
void    execute_rrr(t_data *data, t_lst *lsta, int target_pos, int i);
void    execute_rra(t_data *data, t_lst *lsta, int target_pos, int i);
void    execute_rrb(t_data *data, t_lst *lsta, int target_pos, int i);


void    find_min(t_data *data, t_lst *lsta);
void    find_max(t_lst *lst, t_data *data);
int     find_target(t_data *data, t_lst *lstb, int nb);
int     find_target_b(t_data *data, t_lst *lsta, int nb);
int     find_pushcost(t_data *data, t_lst *lst);
int     find_cheapest(t_lst *lsta);


void     init_data(t_data *data);
t_lst    *init_lst_a(char **av, int ac, t_data *data);
char    **init_tab(char **av, int ac, t_data *data);
void    init_median(t_data *data);
void    init_execute_data(t_data *data, t_lst *lsta, int target_pos, int cheapest);


void    print_lst(t_lst *lst);
void    print_all_lst(t_lst *lsta, t_lst *lstb);
void    print_target(t_lst *lsta);


t_lst   *push_front(t_lst *lst, int nb);
t_lst   *push_back(t_lst *lst, int nb);
t_lst   *pop_front(t_lst *lst);
t_lst   *pop_back(t_lst *lst);


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


void    algorithm(t_data *data);
void    calcul_rr(t_data *data, t_lst *lsta, int i);
void    execute_rr(t_data *data, t_lst *lsta, int target_pos);
int	    ft_strcmp(char *s1, char *s2);
void    freetab(char **tab);
void    freelist(t_data *data);
void	free_lst_ab(t_lst **lst_a, t_lst **lst_b);
void    last_move(t_data *data, t_lst *lsta);
void    set_list_a(t_data *data);
void    set_list_b(t_data *data);
void    sort_three(t_data *data);



#endif