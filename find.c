/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:30:34 by kenz              #+#    #+#             */
/*   Updated: 2024/03/04 04:18:38 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_data *data, t_lst *lsta)
{
	data->utils.min = lsta->nb;
	lsta = lsta->next;
	while (lsta)
	{
		if (data->utils.min > lsta->nb)
			data->utils.min = lsta->nb;
		lsta = lsta->next;
	}
}

void	find_max(t_lst *lst, t_data *data)
{
	t_lst	*start;

	start = lst;
	data->utils.max = 0;
	if (!lst)
		return ;
	if (data->utils.max)
	{
		if (data->utils.max < lst->nb)
			data->utils.max = lst->nb;
	}
	lst = lst->next;
	while (lst)
	{
		if (data->utils.max)
		{
			if (data->utils.max < lst->nb)
				data->utils.max = lst->nb;
		}
		else if (start->nb > lst->nb)
			data->utils.max = start->nb;
		else if (start->nb < lst->nb)
			data->utils.max = lst->nb;
		lst = lst->next;
	}
}

int	find_target(t_data *data, t_lst *lstb, int nb)
{
	int	*tab;
	int	i;
	int	target;

	i = 0;
	tab = ft_calloc((data->utils.len_b + 1), (sizeof(int)));
	while (lstb)
	{
		if (nb > lstb->nb)
			tab[i++] = lstb->nb;
		lstb = lstb->next;
	}
	if (i == 0)
		return (target = data->utils.max, free(tab), target);
	while (i > 0)
	{
		if (tab[0] < tab[i - 1])
			tab[0] = tab[i - 1];
		i--;
	}
	target = tab[0];
	return (free(tab), target);
}

int	find_target_b(t_data *data, t_lst *lsta, int nb)
{
	int	*tab;
	int	i;
	int	target;

	tab = ft_calloc(data->utils.len_a + 1, sizeof(int));
	i = 0;
	target = 0;
	find_min(data, lsta);
	while (lsta)
	{
		if (nb < lsta->nb)
			tab[i++] = lsta->nb;
		lsta = lsta->next;
	}
	if (i == 0)
		return (target = data->utils.min, free(tab), target);
	target = cut_while(i, target, tab);
	return (free(tab), target);
}

int	find_pushcost(t_data *data, t_lst *lst)
{
	int	tg_pos;
	int	pushcost;

	tg_pos = define_target_pos(lst->target, data->lstb);
	init_median(data);
	if (lst->pos <= data->utils.m_lsta && tg_pos <= data->utils.m_lstb)
	{
		if (lst->pos < tg_pos)
			return (pushcost = tg_pos);
		else if (lst->pos >= tg_pos)
			return (pushcost = lst->pos);
	}
	else if (lst->pos > data->utils.m_lsta && tg_pos > data->utils.m_lstb)
	{
		if ((data->utils.len_a - lst->pos) > (data->utils.len_b - tg_pos))
			return (pushcost = (data->utils.len_a - lst->pos));
		else if ((data->utils.len_a - lst->pos) < (data->utils.len_b - tg_pos))
			return (pushcost = (data->utils.len_b - tg_pos));
		pushcost = lst->pos;
	}
	else if (lst->pos <= data->utils.m_lsta && tg_pos > data->utils.m_lstb)
		pushcost = lst->pos + (data->utils.len_b - tg_pos);
	else if (lst->pos > data->utils.m_lsta && tg_pos <= data->utils.m_lstb)
		pushcost = (data->utils.len_a - lst->pos) + tg_pos;
	return (pushcost);
}
