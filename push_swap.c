/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 04:01:02 by kenz              #+#    #+#             */
/*   Updated: 2024/03/02 05:21:51 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_data data;

    data.lsta = NULL;
    data.lstb = NULL;
    char **tab;
    if (ac > 2)
    {
        //check_args_value(av, ac);
        init_data(&data);
        data.lsta = init_lst_a(av, ac, &data);
        tab = init_tab(av, ac, &data);
        //check_argv(tab);
        algorithm(&data);
        freetab(tab);
    }
    else 
        ft_printf("Besoin d'arguments!\n");
}