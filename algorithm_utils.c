/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 03:31:30 by kenz              #+#    #+#             */
/*   Updated: 2024/02/29 16:59:40 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    define_target_pos(int target, t_lst *lstb)
{
    int targetpos;

    define_pos(lstb);

    targetpos = 0;
    while (lstb)
    {
        if (target == lstb->nb)
        {
            targetpos = lstb->pos;
        }
        lstb = lstb->next;
    }
    return (targetpos);
}

void    find_max(t_lst *lst, t_data *data)
{
    t_lst *start;

    start = lst;
    data->utils.max = 0;
    if (!lst)
        return;
    if (data->utils.max)
    {
        if (data->utils.max < lst->nb)
            data->utils.max = lst->nb;
    }
    lst = lst->next;
    while (lst)
    {
        if (data->utils.max)
        {
            if (data->utils.max < lst->nb)
                data->utils.max = lst->nb;
        }
        else if (start->nb > lst->nb)
            data->utils.max = start->nb;
        else if (start->nb < lst->nb)
            data->utils.max = lst->nb;
        lst = lst->next;
    }
    printf("MAX = %d\n", data->utils.max);
}

int    find_target(t_data *data, t_lst *lstb, int nb)
{
    int *tab;
    int i;
    int target;
   
    i = 0;
    tab = ft_calloc((data->utils.len_b + 1), (sizeof(int)));
    while (lstb)
    {
        if (nb > lstb->nb)
            tab[i++] = lstb->nb;
        lstb = lstb->next;
    }
    if (i == 0)
        return (target = data->utils.max, free(tab),  target);
    while (i > 0)
    {
        if (tab[0] < tab[i])
             tab[0] = tab[i];
        i--;
    }
    target = tab[0];
    return (free(tab) , target);
}

t_lst    *define_target(t_data *data, t_lst *lsta)
{
    if (!lsta || !data->lsta)
        return NULL;
    t_lst *temp;

    temp = lsta;
    while (temp)
    {
        temp->target = find_target(data, data->lstb, temp->nb);
        temp = temp->next;
    }
    return (lsta);
}

void    sort_three(t_data *data)
{
    if (!data->lsta)
        return;
    find_max(data->lsta, data);
    printf ("lsta->nb = %d\n", data->lsta->nb);
    if (data->lsta->next->next->nb == data->utils.max && data->lsta->nb < data->lsta->next->nb)
        return ;
    if (data->lsta->nb == data->utils.max)
            ra(data);
    else if (data->lsta->next->nb == data->utils.max)
            rra(data, data->lsta);
    else if (data->lsta->nb > data->lsta->next->nb)
            sa(data->lsta, data);
    else if (data->lsta->nb < data->lsta->next->nb)
            ra(data);
}