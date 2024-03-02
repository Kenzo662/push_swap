/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:58:56 by kenz              #+#    #+#             */
/*   Updated: 2024/03/02 16:10:14 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    execute_rrr(t_data *data, t_lst *lsta, int target_pos, int i)
{
    int j;
    int k;

    j = target_pos;
    k = 0;
 /*    printf("AAAAAA"); */
    while (i < data->utils.len_a && j < data->utils.len_b)
    {
        rrr(data, data->lsta, data->lstb);
        i++;
        j++;
        k++;
    }
    if (i == data->utils.len_a && j != data->utils.len_b)
    {
        j = (data->utils.len_b - (target_pos + k)) + 1;
        while (--j > 0)
            rrb(data, data->lstb);
    }
    if (j == data->utils.len_b && i != data->utils.len_a)
    {
        i = (data->utils.len_a - (lsta->pos + k)) + 1;
        while (--i > 0)
            rra(data, data->lsta);
    }
}

void    execute_rr(t_data *data, t_lst *lsta, int target_pos)
{
    int i;
    int j;

    i = 0;
    j = 0;
   /*  printf("BBBBBB"); */
    if (lsta->pos < target_pos)
    {
        j = (target_pos - lsta->pos) + 1;
        i = lsta->pos + 1;
        while (--i > 0)
            rr(data);
        while (--j > 0)
            rb(data);
    }
    else if (lsta->pos > target_pos)
    {
        j = (lsta->pos - target_pos) + 1;
        i = target_pos + 1;
        while (--i > 0)
            rr(data);
        while (--j > 0)
            ra(data);
    }
    else if (lsta->pos == target_pos)
        calcul_rr(data, lsta, i);
}

void    calcul_rr(t_data *data, t_lst *lsta, int i)
{
     i = lsta->pos + 1;
        while (--i > 0)
            rr(data);
}

void    execute_rra(t_data *data, t_lst *lsta, int target_pos, int i)
{
        i = lsta->pos;
        /* printf("CCCCCC"); */
        while (i++ < data->utils.len_a)
                rra(data, data->lsta);
        while (target_pos > 0)
            {
                rb(data);
                target_pos--;
            }
}

void    execute_rrb(t_data *data, t_lst *lsta, int target_pos, int i)
{
        /* printf("DDDDDD"); */
        i = lsta->pos + 1;
        while (--i > 0)
            ra(data);
        while (target_pos++ < data->utils.len_b)
            rrb(data, data->lstb);
}