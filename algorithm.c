/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:17:03 by kenz              #+#    #+#             */
/*   Updated: 2024/02/27 05:25:38 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    algorithm(t_data *data)
{
    if (data->utils.len_a > 3)
    {
        pb(data);
        pb(data);
        set_list(data);
        printf("nb = %d target = %d\n",data->lsta->nb, data->lsta->target);
        find_pushcost(data, data->lsta, data->lsta->nb, data->lsta->target);
        print_all_lst(data->lsta, data->lstb);
        set_list(data);
        printf("nb = %d target = %d\n",data->lsta->nb, data->lsta->target);
        find_pushcost(data, data->lsta->next->next, data->lsta->next->next->nb, data->lsta->next->next->target);
    }
    else
        ft_printf("non :d");
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
    i = 1;
    while (tab[i])
    {
        if (tab[0] < tab[i])
             tab[0] = tab[i];
        i++;
    }
    target = tab[0];
    return (free(tab) , target);
}

t_lst    *define_target(t_data *data, t_lst *lsta)
{
    if (!lsta || !data->lsta)
        return NULL;
    t_lst *temp;
    int i;

    temp = lsta;
    while (temp)
    {
        temp->target = find_target(data, data->lstb, temp->nb);
        temp = temp->next;
    }
    return (lsta);
}

void    find_pushcost(t_data *data, t_lst *lst, int nb, int target)
{
    int a_cost;
    int b_cost;
    int target_pos;


    a_cost = 0;
    b_cost = 0;
    target_pos = define_target_pos(target, data->lstb);  
    data->utils.median_lsta = (data->utils.len_a / 2);
    data->utils.median_lstb = (data->utils.len_b / 2);
    printf("median A = %d\n", data->utils.median_lsta);
    printf("median B = %d\n", data->utils.median_lstb);
    if(lst->pos == 0 && target_pos == 0)
    {
        pb(data);
        return ;
    }
    printf ("lstpos = %d\n", lst->pos);
    if (lst->pos <= data->utils.median_lsta && target_pos <= data->utils.median_lstb)
    {
        a_cost = lst->pos;
        b_cost = target_pos;
        lst->pushcost = (a_cost + b_cost);
        printf("A");
        printf("pushcost = %d\n", lst->pushcost);
    }
    else if (lst->pos > data->utils.median_lsta && target_pos > data->utils.median_lstb)
    {
        a_cost = (data->lsta->last_pos - lst->pos);
        b_cost = (data->lstb->last_pos - target_pos);
        lst->pushcost = (a_cost + b_cost);
        printf("B");
        printf("pushcost = %d\n", lst->pushcost);
    }
    else if (lst->pos <= data->utils.median_lsta && target_pos > data->utils.median_lstb)
    {
        a_cost = lst->pos;
        b_cost = (data->lstb->last_pos - target_pos);
        lst->pushcost = (a_cost + b_cost);
        printf("C");
        printf("pushcost = %d\n", lst->pushcost);
    }
    else if (lst->pos > data->utils.median_lsta && target_pos <= data->utils.median_lstb)
    {
        a_cost = (data->lsta->last_pos - lst->pos);
        b_cost = target_pos;
        lst->pushcost = (a_cost + b_cost);
        printf("D");
        printf("pushcost = %d\n", lst->pushcost);
    }
}

