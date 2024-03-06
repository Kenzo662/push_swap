/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:17:03 by kenz              #+#    #+#             */
/*   Updated: 2024/03/06 20:06:51 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_data *data)
{
	if (data->utils.len_a == 2)
		return (sort_two(data));
	if (data->utils.len_a == 3)
		return (sort_three(data));
	if (data->utils.len_a == 4)
		return (four_argv(data));
	pb(data);
	pb(data);
	while (data->utils.len_a > 3)
	{
		set_list_a(data);
		define_pushcost(data, data->lsta);
		execute(data, data->lsta);
	}
	if (data->utils.len_a == 3)
		algo_b_to_a(data);
}

void	execute(t_data *data, t_lst *lsta)
{
	int	cheapest;
	int	trgt_pos;
	int	i;

	i = 0;
	cheapest = find_cheapest(lsta);
	lsta = define_target(data, data->lsta);
	while (cheapest != lsta->nb)
		lsta = lsta->next;
	trgt_pos = define_target_pos(lsta->target, data->lstb);
	init_median(data);
	if (lsta->pos == 0 && trgt_pos == 0)
		return (pb(data));
	if (lsta->pos > data->utils.m_lsta && trgt_pos <= data->utils.m_lstb)
		execute_rra(data, lsta, trgt_pos, i);
	else if (lsta->pos <= data->utils.m_lsta && trgt_pos > data->utils.m_lstb)
		execute_rrb(data, lsta, trgt_pos, i);
	else if (lsta->pos <= data->utils.m_lsta && trgt_pos <= data->utils.m_lstb)
		execute_rr(data, lsta, trgt_pos);
	else if (lsta->pos > data->utils.m_lsta && trgt_pos > data->utils.m_lstb)
	{
		i = lsta->pos;
		execute_rrr(data, lsta, trgt_pos, i);
	}
	pb(data);
}

void	execute_b(t_data *data, t_lst *lsta)
{
	int	i;

	init_median(data);
	if (data->lstb->target == lsta->nb)
		return (pa(data));
	while (lsta->nb != data->lstb->target)
		lsta = lsta->next;
	if (lsta->pos <= data->utils.m_lsta)
	{
		i = lsta->pos;
		while (i > 0)
		{
			ra(data);
			i--;
		}
	}
	else if (lsta->pos > data->utils.m_lsta)
	{
		i = (data->utils.len_a - lsta->pos) + 1;
		while (--i > 0)
			rra(data, data->lsta);
	}
	pa(data);
}

void	last_move(t_data *data, t_lst *lsta)
{
	int	i;

	init_median(data);
	find_min(data, data->lsta);
	define_pos(lsta);
	while (lsta->nb != data->utils.min)
		lsta = lsta->next;
	if (lsta->pos <= data->utils.m_lsta)
	{
		i = lsta->pos;
		while (i > 0)
		{
			ra(data);
			i--;
		}
	}
	else if (lsta->pos > data->utils.m_lsta)
	{
		i = (data->utils.len_a - lsta->pos);
		while (i > 0)
		{
			rra(data, data->lsta);
			i--;
		}
	}
}

void	four_argv(t_data *data)
{
	pb(data);
	sort_three(data);
	set_list_b(data);
	execute_b(data, data->lsta);
	last_move(data, data->lsta);
}
