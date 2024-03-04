/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:33:29 by kenz              #+#    #+#             */
/*   Updated: 2024/03/03 22:24:47 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_target_pos(int target, t_lst *lstb)
{
	int	targetpos;

	define_pos(lstb);
	targetpos = 0;
	while (lstb)
	{
		if (target == lstb->nb)
		{
			targetpos = lstb->pos;
		}
		lstb = lstb->next;
	}
	return (targetpos);
}

t_lst	*define_target(t_data *data, t_lst *lsta)
{
	t_lst	*temp;

	if (!lsta || !data->lsta)
		return (NULL);
	temp = lsta;
	while (temp)
	{
		temp->target = find_target(data, data->lstb, temp->nb);
		temp = temp->next;
	}
	return (lsta);
}

void	define_pos(t_lst *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return ;
	while (lst->next)
	{
		lst->pos = i;
		lst = lst->next;
		i++;
	}
	lst->pos = i;
}

void	define_lastpos(t_lst *lst, int len_list)
{
	while (lst)
	{
		lst->last_pos = len_list;
		lst = lst->next;
	}
}

void	define_pushcost(t_data *data, t_lst *lsta)
{
	if (!lsta)
		return ;
	while (lsta)
	{
		lsta->pushcost = find_pushcost(data, lsta);
		lsta = lsta->next;
	}
}
