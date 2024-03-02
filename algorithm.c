/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:17:03 by kenz              #+#    #+#             */
/*   Updated: 2024/03/02 19:02:58 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    algorithm(t_data *data)
{
    int i;

    i = 0;
    pb(data);
    pb(data);
    while (data->utils.len_a > 3)
    {
        set_list_a(data);
        define_pushcost(data, data->lsta);
        //print_target(data->lsta);
        execute(data, data->lsta);
        //print_all_lst(data->lsta, data->lstb);
    }
    if (data->utils.len_a == 3)
    {
        sort_three(data);
        i = data->utils.len_b;
        while (i > 0)
        {
            set_list_b(data);
            execute_b(data, data->lsta);
            i--;
        }
        last_move(data, data->lsta);
        freelist(data);
    }
}

void    execute(t_data *data, t_lst *lsta)
{
    int cheapest;
    int target_pos;
    int i;

    i = 0;
    cheapest = find_cheapest(lsta);
    lsta = define_target(data, data->lsta);
    while (cheapest != lsta->nb)
        lsta = lsta->next;
    target_pos = define_target_pos(lsta->target, data->lstb);
   /*  printf("La target de : %d = %d\n", lsta->nb, lsta->target);
    printf("La pos de NB = %d La pos de TARGET = %d\n", lsta->pos, target_pos); */
    init_median(data);
    if (lsta->pos == 0 && target_pos == 0)
            return (pb(data));
    if (lsta->pos > data->utils.median_lsta && target_pos <= data->utils.median_lstb)
        execute_rra(data, lsta, target_pos, i);
    else if (lsta->pos <= data->utils.median_lsta && target_pos > data->utils.median_lstb)
        execute_rrb(data, lsta, target_pos, i);
    else if (lsta->pos <= data->utils.median_lsta && target_pos <= data->utils.median_lstb)
        execute_rr(data, lsta, target_pos);
    else if (lsta->pos > data->utils.median_lsta && target_pos > data->utils.median_lstb)
    {
        i = lsta->pos;
        execute_rrr(data, lsta, target_pos, i);
    }
    pb(data);   
}

void    execute_b(t_data *data, t_lst *lsta)
{
    int i;

    init_median(data);
    if (data->lstb->target == lsta->nb)
        return (pa(data));
    while (lsta->nb != data->lstb->target)
        lsta = lsta->next;
    if (lsta->pos <= data->utils.median_lsta)
        {
            i = lsta->pos;
            while (i > 0)
            {
                ra(data);
                i--;
            }
        }
    else if (lsta->pos > data->utils.median_lsta)
    {
        i = (data->utils.len_a - lsta->pos);
        while (i > 0)
        {
            rra(data, data->lsta);
            i--;
        }
    }
    pa(data);
}

void    last_move(t_data *data, t_lst *lsta)
{
    int i;
    
    init_median(data);
    find_min(data, data->lsta);
    define_pos(lsta);
    while (lsta->nb != data->utils.min)
        lsta = lsta->next;
    if (lsta->pos <= data->utils.median_lsta)
    {
        i = lsta->pos;
        while (i > 0)
        {
            ra(data);
            i--;
        }  
    }
    else if (lsta->pos > data->utils.median_lsta)
    {
        i = (data->utils.len_a - lsta->pos);
        while (i > 0)
        {
            rra(data, data->lsta);
            i--;
        }
    }
}
