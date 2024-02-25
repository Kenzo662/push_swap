/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:52:55 by kenz              #+#    #+#             */
/*   Updated: 2024/02/25 19:25:23 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst   *push_front(t_lst *lst, int nb)
{
    t_lst *node;

    node = malloc(sizeof(*node));
    if (!node)
        return (NULL);
    node->nb = nb;
    node->target = 0;
    node->pos = 0;
    node->next = lst;
    return (node);
}

t_lst   *push_back(t_lst *lst, int nb)
{
    t_lst *node;
    t_lst *templst;

    node = malloc(sizeof(*node));
    node->nb = nb;
    node->target = 0;
    node->pos = 0;
    node->next = NULL;

    if(!lst)
        return(node);
    templst = lst;
    while(templst->next)
        templst = templst->next;
    templst->next = node;
    return(lst);
}

t_lst   *pop_back(t_lst *lst)
{
    t_lst   *temp;
    t_lst   *before;
    
    if (!lst)
        return (NULL);
    if(!lst->next)
        return(free(lst), NULL);
    temp = lst;
    before = lst;
    while (temp->next)
    {
        before = temp;
        temp = temp->next;
    }
    before->next = NULL;
    free (temp);
    return (lst);
}

t_lst   *pop_front(t_lst *lst)
{
    t_lst *node;

    node = malloc(sizeof(*node));
    if (!node)
        return (NULL);
    node = lst->next;
    free(lst);
    return(node);   
}