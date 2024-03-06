/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 04:30:11 by kenz              #+#    #+#             */
/*   Updated: 2024/03/06 04:31:55 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_lst *lst)
{
	t_lst	*tmp;
	int		temp;

	if (!lst->next || !lst)
		return ;
	tmp = lst->next;
	temp = tmp->nb;
	lst->next->nb = lst->nb;
	lst->nb = temp;
}

void	sb(t_lst *lst)
{
	t_lst	*tmp;
	int		temp;

	if (!lst->next || !lst)
		return ;
	tmp = lst->next;
	temp = tmp->nb;
	lst->next->nb = lst->nb;
	lst->nb = temp;
}

void	ss(t_data *data)
{
	if (data->lsta && data->lsta->next)
		sa(data->lsta);
	if (data->lstb && data->lstb->next)
		sb(data->lstb);
}

void	pb(t_data *data)
{
	int		temp;
	t_lst	*tmp;

	if (!data->lsta)
		return ;
	tmp = data->lsta;
	temp = data->lsta->nb;
	data->lsta = data->lsta->next;
	data->lstb = push_front(data->lstb, temp);
	data->utils.len_b++;
	data->utils.len_a--;
	free(tmp);
}

void	pa(t_data *data)
{
	int		temp;
	t_lst	*tmp;

	if (!data->lstb)
		return ;
	tmp = data->lstb;
	temp = data->lstb->nb;
	data->lstb = data->lstb->next;
	data->lsta = push_front(data->lsta, temp);
	data->utils.len_a++;
	data->utils.len_b--;
	free(tmp);
}
