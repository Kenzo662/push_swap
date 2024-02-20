/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 04:33:38 by kenz              #+#    #+#             */
/*   Updated: 2024/02/20 04:56:03 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_lst_a(t_node *node, char **av)
{
    int i;

    i = 0;
    while(av[i])
    {
        node = ft_lstnew(node->nb);
        node->nb = ft_atoi(av[i]);
        node = node->next;
    }
}