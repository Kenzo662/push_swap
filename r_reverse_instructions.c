/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_reverse_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:57:54 by kenz              #+#    #+#             */
/*   Updated: 2024/03/01 23:37:27 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_data *data, t_lst *lsta)
{
    if (!data->lsta || data->utils.len_a < 2)
    {
        data->utils.use_rra = 0;
        return ;
    }
    int temp;
    
    while (lsta->next)
        lsta = lsta->next;
    temp = lsta->nb;
    data->lsta = pop_back(data->lsta);
    data->lsta = push_front(data->lsta, temp);
    if(data->utils.use_rra == 0)
    {
        data->utils.count++;
        ft_printf("rra\n");
    }
    else
        data->utils.use_rra = 0;
    data->utils.count++;
}

void    rrb(t_data *data, t_lst *lstb)
{
    if (!data->lstb || data->utils.len_b < 2)
    {
        data->utils.use_rrb = 0;
        return ;
    }
    int temp1;
    
    while (lstb->next)
        lstb = lstb->next;
    temp1 = lstb->nb;
    data->lstb = pop_back(data->lstb);
    data->lstb = push_front(data->lstb, temp1);
    if(data->utils.use_rrb == 0)
    {
        data->utils.count++;
        ft_printf("rrb\n");
    }
    else
        data->utils.use_rrb = 0;
}

void    rrr(t_data *data, t_lst *lsta, t_lst *lstb)
{
    data->utils.use_rra = 1;
    data->utils.use_rrb = 1;
    rra(data, lsta);
    rrb(data, lstb);
    ft_printf("rrr\n");
}