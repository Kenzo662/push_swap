/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 03:45:26 by kenz              #+#    #+#             */
/*   Updated: 2024/02/24 04:01:54 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_data *data)
{
    int temp;
    
    if (!data->lsta || data->utils.len_a < 2)
    {
        data->utils.use_ra = 0;
        return;
    }
    temp = data->lsta->nb;
    data->lsta = pop_front(data->lsta);
    data->lsta = push_back(data->lsta, temp);
    if (data->utils.use_ra == 0)
        ft_printf("ra\n");
    else
        data->utils.use_ra = 0;
}

void    rb(t_data *data)
{
    int temp;

    if (!data->lstb || data->utils.len_b < 2)
    {
        data->utils.use_rb = 0;
        return;
    }
    temp = data->lstb->nb;
    data->lstb = pop_front(data->lstb);
    data->lstb = push_back(data->lstb, temp);
    if (data->utils.use_rb == 0)
        ft_printf("rb\n");
    else
        data->utils.use_rb = 0;
}

void    rr(t_data *data)
{
    data->utils.use_ra = 1;
    data->utils.use_rb = 1;
    ra(data);
    rb(data);
    ft_printf("rr\n");   
}