/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 04:33:38 by kenz              #+#    #+#             */
/*   Updated: 2024/02/22 03:50:39 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst    *init_lst_a(char **av, int ac)
{
    int i;
    int nb;
    t_lst *temp;

    i = 0;
    temp = NULL;
    if (ac == 2)
    {
        av = ft_split(av[1], ' ');
        i = -1;
    }
    while(av[++i])
    {
        nb = ft_atoi(av[i]);
        temp = push_front(temp, nb);
    }
    return(temp);
}

t_lst   *push_front(t_lst *lst, int nb)
{
    t_lst *node;

    node = malloc(sizeof(*node));

    node->nb = nb;
    node->next = lst;
    return (node);
}



