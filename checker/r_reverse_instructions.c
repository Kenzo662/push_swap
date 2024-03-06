/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_reverse_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:57:54 by kenz              #+#    #+#             */
/*   Updated: 2024/03/06 04:27:29 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_data *data, t_lst *lsta)
{
	int	temp;

	if (!data->lsta)
		return ;
	while (lsta->next)
		lsta = lsta->next;
	temp = lsta->nb;
	data->lsta = pop_back(data->lsta);
	data->lsta = push_front(data->lsta, temp);
}

void	rrb(t_data *data, t_lst *lstb)
{
	int	temp1;

	if (!data->lstb)
		return ;
	while (lstb->next)
		lstb = lstb->next;
	temp1 = lstb->nb;
	data->lstb = pop_back(data->lstb);
	data->lstb = push_front(data->lstb, temp1);
}

void	rrr(t_data *data, t_lst *lsta, t_lst *lstb)
{
	rra(data, lsta);
	rrb(data, lstb);
}
