/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:17:03 by kenz              #+#    #+#             */
/*   Updated: 2024/02/25 20:04:00 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    algorithm(t_data *data)
{
    if (data->utils.len_a > 3)
    {
        pb(data);
        pb(data);
        find_min_and_max(data);
        find_target(data, data->lstb, data->lsta->nb);
        data->lsta = define_target(data, data->lsta);
        print_target(data->lsta);
    }
    else
        ft_printf("non :d");
}

void    find_min_and_max(t_data *data)
{
    if (data->lstb->nb > data->lstb->next->nb)
    {
        data->utils.max = data->lstb->nb;
        data->utils.min = data->lstb->next->nb;
        printf("min = %d, max = %d\n", data->utils.min, data->utils.max);
    }
    else
    {
        data->utils.min = data->lstb->nb;
        data->utils.max = data->lstb->next->nb;
        printf("min = %d, max = %d\n", data->utils.min, data->utils.max);
    }
}

int    find_target(t_data *data, t_lst *lstb, int nb)
{
    int count;
    int *tab;
    int i;
    int target;
    t_lst *temp;

    temp = lstb;
    count = 0;
    i = 0;
    if (!lstb || !temp)
        return (0);
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    tab = ft_calloc((count + 1), (sizeof(int)));
    while (lstb)
    {
        printf ("lstb = %d\n", lstb->nb);
        if (nb > lstb->nb)
        {
            tab[i] = lstb->nb;
            i++;
        }
        printf ("tab = %d\n", tab[i]);
        lstb = lstb->next;
    }
    if (i == 0)
        return (target = data->utils.max, free(tab),  target);
    i = 1;
    while (tab[i])
    {
        printf ("tab = %d\n", tab[i]);
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
    i = 0;
    while (temp)
    {
        i++;
        temp->pos = i;
        temp->target = find_target(data, data->lstb, temp->nb);
        temp = temp->next;
    }
    return (lsta);
}
