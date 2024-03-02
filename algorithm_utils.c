/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 03:31:30 by kenz              #+#    #+#             */
/*   Updated: 2024/03/02 05:50:16 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    find_cheapest(t_lst *lsta)
{
    int cheapest;
    int cost; 
    if (!lsta)
        return (0);
    cheapest = lsta->nb;
    cost = lsta->pushcost;
    while (lsta)
    {
        if (cost > lsta->pushcost)
            {
                cost = lsta->pushcost;
                cheapest = lsta->nb;
            }
            lsta = lsta->next;
    }
    return (cheapest);
}

void    sort_three(t_data *data)
{
    if (!data->lsta)
        return;
    find_max(data->lsta, data);
    if (data->lsta->next->next->nb == data->utils.max && data->lsta->nb < data->lsta->next->nb)
        return ;
    if (data->lsta->nb == data->utils.max)
            ra(data);
    else if (data->lsta->next->nb == data->utils.max)
            rra(data, data->lsta);
    if (data->lsta->nb > data->lsta->next->nb)
            sa(data->lsta, data);
}

void    set_list_a(t_data *data)
{
        define_pos(data->lsta);
        define_pos(data->lstb);
        define_lastpos(data->lsta, data->utils.len_a);
        define_lastpos(data->lstb, data->utils.len_b);
        find_max(data->lstb, data);
        data->lsta = define_target(data, data->lsta);
}
void    set_list_b(t_data *data)
{
    define_pos(data->lsta);
    define_pos(data->lstb);
    data->lstb = define_target_b(data, data->lstb);
}
t_lst    *define_target_b(t_data *data, t_lst *lstb)
{
    t_lst *temp;

    temp = lstb;
    while (temp)
    {
        temp->target = find_target_b(data, data->lsta, temp->nb);
        temp = temp->next;
    }
    return (lstb);
}

