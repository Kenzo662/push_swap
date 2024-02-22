/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 04:01:02 by kenz              #+#    #+#             */
/*   Updated: 2024/02/22 15:18:43 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_data data;

    data.lsta = NULL;
    data.lstb = NULL;
    if (ac > 1)
    {
        check_args_value(av, ac);
        data.lsta = init_lst_a(av, ac);
        print_all_lst(data.lsta, data.lstb);
        sa(data.lsta);
        print_all_lst(data.lsta, data.lstb);
        pb(&data);
        print_all_lst(data.lsta, data.lstb);
        sa(data.lsta);
        print_all_lst(data.lsta, data.lstb);
        pb(&data);
        print_all_lst(data.lsta, data.lstb);
        ss(&data);
        print_all_lst(data.lsta, data.lstb);
    }
    else 
        printf("Besoin d'arguments!\n");
}