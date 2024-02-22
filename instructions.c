/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 04:30:11 by kenz              #+#    #+#             */
/*   Updated: 2024/02/22 15:17:26 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_lst *lst)
{
    t_lst *tmp;
    int temp;
    
    if (!lst->next || !lst)
        return ;
    tmp = lst->next;
    temp = tmp->nb;
    lst->next->nb = lst->nb;
    lst->nb = temp;
    ft_printf("sa\n");
}

void    sb(t_lst *lst)
{
    t_lst *tmp;
    int temp;

    if (!lst->next || !lst)
        return ;
    tmp = lst->next;
    temp = tmp->nb;
    lst->next->nb = lst->nb;
    lst->nb = temp;
    ft_printf("sb\n");
}

void    ss(t_data *data)
{
    if (data->lsta && data->lsta->next)
        sa(data->lsta);
    else
        ft_printf("Pas assez d'éléments pour swap dans la Liste A\n");
        
    if (data->lstb && data->lstb->next)
        sb(data->lstb);
    else
        ft_printf("Pas assez d'éléments pour swap dans la Liste B\n");
}

void    pb(t_data *data)
{
    int temp;

    if(!data->lsta)
        return;
    temp = data->lsta->nb;
    data->lsta = data->lsta->next;
    data->lstb = push_front(data->lstb, temp);
    ft_printf("pb\n");
}

void    pa(t_data *data)
{
    int temp;

    if(!data->lstb)
        return;
    temp = data->lstb->nb;
    data->lstb = data->lstb->next;
    data->lsta = push_front(data->lsta, temp);
    ft_printf("pa\n");
}


