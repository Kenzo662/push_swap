/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:17:03 by kenz              #+#    #+#             */
/*   Updated: 2024/03/01 18:27:37 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    algorithm(t_data *data)
{
    pb(data);
    pb(data);
    while (data->utils.len_a > 3)
    {
        set_list(data);
        define_pushcost(data, data->lsta);
        execute(data, data->lsta);
        print_all_lst(data->lsta, data->lstb);
    }
    if (data->utils.len_a == 3)
    {
        sort_three(data);
    }
}

void    set_list(t_data *data)
{
        define_pos(data->lsta);
        define_pos(data->lstb);
        define_lastpos(data->lsta, data->utils.len_a);
        define_lastpos(data->lstb, data->utils.len_b);
        find_max(data->lstb, data);
        data->lsta = define_target(data, data->lsta);
        print_target(data->lsta);
}

int    find_pushcost(t_data *data, t_lst *lst)
{
    int target_pos;
    int pushcost;
    int temp;

    pushcost = 0;
    temp = 0;
    target_pos = define_target_pos(lst->target, data->lstb);
    data->utils.median_lsta = (data->utils.len_a / 2);
    data->utils.median_lstb = (data->utils.len_b / 2);
    printf("LSTPOSPC = %d\n TARGETPOSPC = %d\n" , lst->pos, target_pos);
    if (lst->pos <= data->utils.median_lsta && target_pos <= data->utils.median_lstb)
    {
        if (lst->pos < target_pos)
            return (pushcost = lst->pos + (target_pos - lst->pos));
        else if (lst->pos > target_pos)
            return (pushcost = (target_pos + (lst->pos - target_pos)));
        pushcost = lst->pos;
    }
    else if (lst->pos > data->utils.median_lsta && target_pos > data->utils.median_lstb)
    {
        if (lst->pos > target_pos)
            return (pushcost = (data->utils.len_b - target_pos));
        else if (target_pos > lst->pos)
            return (pushcost = (data->utils.len_a - lst->pos));
        pushcost = (data->utils.len_a - lst->pos);    
    }
    else if (lst->pos <= data->utils.median_lsta && target_pos > data->utils.median_lstb)
        pushcost = lst->pos + (data->utils.len_b - target_pos);
    else if (lst->pos > data->utils.median_lsta && target_pos <= data->utils.median_lstb)
        pushcost = (data->utils.len_a - lst->pos) + target_pos;
    return (pushcost);
}

void    define_pushcost(t_data *data, t_lst *lsta)
{
    if (!lsta)
        return;
    while (lsta)
    {
        lsta->pushcost = find_pushcost(data, lsta);
        printf("pushcost = %d\n", lsta->pushcost);
        lsta = lsta->next;
    }
}

int    calcul(t_lst *lst, int pos)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;    
    if (!lst)
        return (0);
    i = pos;
    while (i > 0)
    {
        i--;
        j++;
    }
    i = pos;
    while (i < lst->last_pos)
    {
        i++;
        k++;
    }
    if (j < k)
        return (1);
    return (2);
}

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
    printf ("cheapest = %d\n", cheapest);
    return (cheapest);
}

void    execute(t_data *data, t_lst *lsta)
{
    if (!lsta)
        return ;
    int cheapest;
    int target_pos;
    int i;
    int j;

    i = 0;
    j = 0;
    cheapest = find_cheapest(lsta);
    lsta = define_target(data, data->lsta);
    while (cheapest != lsta->nb)
        lsta = lsta->next;
    target_pos = define_target_pos(lsta->target, data->lstb);
    printf ("len a = %d\nlen b = %d\n", data->utils.len_a, data->utils.len_b);
    data->utils.median_lsta = (data->utils.len_a / 2);
    data->utils.median_lstb = (data->utils.len_b / 2);
    printf("MEDIAN A = %d\nMEDIAN B =%d\n", data->utils.median_lsta, data->utils.median_lstb);
    printf ("LSTANB = %d LSTA-TARGET = %d\n", lsta->nb, lsta->target);
    printf ("LSTAPOS = %d TARGETPOS = %d\n", lsta->pos, target_pos);
    if (lsta->pos == 0 && target_pos == 0)
        {
            pb(data);
            return;
        }
    if (lsta->pos > data->utils.median_lsta && target_pos <= data->utils.median_lstb)
    {
        i = lsta->pos;
        while (i++ < data->utils.len_a)
                rra(data, data->lsta);
        while (target_pos > 0)
            {
                rb(data);
                target_pos--;
            }
        pb(data);
    }
    else if (lsta->pos <= data->utils.median_lsta && target_pos > data->utils.median_lstb)
    {
        i = lsta->pos + 1;
        while (--i > 0)
            ra(data);
        while (target_pos++ < data->utils.len_b)
            rrb(data, data->lstb);
        pb(data);
    }
    else if (lsta->pos <= data->utils.median_lsta && target_pos <= data->utils.median_lstb)
    {
        if (lsta->pos < target_pos)
        {
            j = target_pos - lsta->pos;
            i = lsta->pos;
            while (i > 0)
            {
                rr(data);
                i--;
            }
            while (j > 0)
            {
                rb(data);
                j--;
            }
        }
        else if (lsta->pos > target_pos)
        {
            j = lsta->pos - target_pos;
            i = target_pos;
            while (i > 0)
            {
                rr(data);
                i--;
            }
            while (j > 0)
            {
                ra(data);
                j--;
            }
        }
        else if (lsta->pos == target_pos)
        {
            i = lsta->pos;
            while (i > 0)
            {
                rr(data);
                i--;
            }
        }
        pb(data);
    }
    else if (lsta->pos > data->utils.median_lsta && target_pos > data->utils.median_lstb)
    {
        if (lsta->pos > target_pos)
        {
            i = lsta->pos;
            while (i < data->utils.len_a)
            {
                rrr(data, data->lsta, data->lstb);
                i++;
                j++;
            }
            j = target_pos + 1;
            printf (" j = %d\n", j);
            while (j < data->utils.len_b)
            {
                rrb(data, data->lstb);
                j++;
            }
        }
        else if (lsta->pos < target_pos)
        {
            printf ("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
            i = target_pos;
            while (i < data->utils.len_b)
            {
                rrr(data, data->lsta, data->lstb);
                i++;
                j++;
            }
            j = lsta->pos + 1;
            while (j < data->utils.len_a)
            {
                rra(data, data->lsta);
                j++;
            }
        }
        else if (lsta->pos == target_pos)
        {
            i = lsta->pos;
            while (i < data->utils.len_a)
            {
                rrr(data, data->lsta, data->lstb);
                i++;
            }
        }
        pb(data);
    }
}
