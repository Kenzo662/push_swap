/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:52:55 by kenz              #+#    #+#             */
/*   Updated: 2024/03/05 02:19:56 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_lst	*push_front(t_lst *lst, int nb)
{
	t_lst	*node;

	node = (t_lst *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->next = lst;
	return (node);
}

t_lst	*push_back(t_lst *lst, int nb)
{
	t_lst	*node;
	t_lst	*templst;

	node = (t_lst *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->next = NULL;
	if (!lst)
		return (node);
	templst = lst;
	while (templst->next)
		templst = templst->next;
	templst->next = node;
	return (lst);
}

t_lst	*pop_back(t_lst *lst)
{
	t_lst	*temp;
	t_lst	*before;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (free(lst), NULL);
	temp = lst;
	before = lst;
	while (temp->next)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	free(temp);
	return (lst);
}

t_lst	*pop_front(t_lst *lst)
{
	t_lst	*node;

	if (!lst)
		return (NULL);
	node = lst->next;
	free(lst);
	return (node);
}

t_lst	*clear_list(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
		lst = pop_front(lst);
	return (lst);
}
