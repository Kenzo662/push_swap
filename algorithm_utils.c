/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 03:31:30 by kenz              #+#    #+#             */
/*   Updated: 2024/02/27 05:20:26 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    define_target_pos(int target, t_lst *lstb)
{
    int targetpos;

    targetpos = 0;
    while (lstb)
    {
        if (target == lstb->nb)
        {
            targetpos = lstb->pos;
        }
        lstb = lstb->next;
    }
    printf ("target pos = %d\n", targetpos);
    return (targetpos);
}

void    set_list(t_data *data)
{
        define_pos(data->lsta);
        define_pos(data->lstb);
        define_lastpos(data->lsta, data->utils.len_a);
        define_lastpos(data->lstb, data->utils.len_b);
        printf("last_posA = %d\n",data->lsta->last_pos);
        printf("last_posB = %d\n",data->lstb->last_pos);
        find_max(data->lstb, data);
        data->lsta = define_target(data, data->lsta);
        print_target(data->lsta);
}