/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:30:34 by kenz              #+#    #+#             */
/*   Updated: 2024/03/02 05:50:37 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    find_min(t_data *data, t_lst *lsta)
{
    data->utils.min = lsta->nb;
    lsta = lsta->next;
    while (lsta)
    {
        if (data->utils.min > lsta->nb)
            data->utils.min = lsta->nb;
        lsta = lsta->next; 
    }
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

int    find_target_b(t_data *data, t_lst *lsta, int nb)
{
    int *tab;
    int i;
    int target;

    tab = ft_calloc(data->utils.len_a + 1 , sizeof(int));
    i = 0;
    find_min(data, lsta);
    while (lsta)
    {
        if (nb < lsta->nb)
            tab[i++] = lsta->nb;
        lsta = lsta->next;
    }
     if (i == 0)
        return (target = data->utils.min, free(tab),  target);
    while (i > 0)
    {
        if (tab[0] > tab[i - 1])
        {
            target = tab[i - 1];
            tab[0] = tab[i - 1];
        }
        else 
            target = tab[0];
        i--;
    }
    return (free(tab), target);
}

int    find_pushcost(t_data *data, t_lst *lst)
{
    int target_pos;
    int pushcost;

    pushcost = 0;
    target_pos = define_target_pos(lst->target, data->lstb);
    data->utils.median_lsta = (data->utils.len_a / 2);
    data->utils.median_lstb = (data->utils.len_b / 2);
    if (lst->pos <= data->utils.median_lsta && target_pos <= data->utils.median_lstb)
    {
        if (lst->pos < target_pos)
            return (pushcost = target_pos);
        else if (lst->pos > target_pos)
            return (pushcost = lst->pos);
        pushcost = lst->pos;
    }
    else if (lst->pos > data->utils.median_lsta && target_pos > data->utils.median_lstb)
    {
        if ((data->utils.median_lsta - lst->pos) > (data->utils.median_lstb - target_pos))
            pushcost = data->utils.len_a - lst->pos;
        else if ((data->utils.median_lsta - lst->pos) < (data->utils.median_lstb - target_pos))
            pushcost = data->utils.len_b - target_pos;
        pushcost = lst->pos;
    }
    else if (lst->pos <= data->utils.median_lsta && target_pos > data->utils.median_lstb)
        pushcost = lst->pos + (data->utils.len_b - target_pos);
    else if (lst->pos > data->utils.median_lsta && target_pos <= data->utils.median_lstb)
        pushcost = (data->utils.len_a - lst->pos) + target_pos;
    return (pushcost);
}