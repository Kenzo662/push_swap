/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 04:30:11 by kenz              #+#    #+#             */
/*   Updated: 2024/03/04 04:39:57 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_lst *lst, t_data *data)
{
	t_lst	*tmp;
	int		temp;

	if (!lst->next || !lst)
	{
		data->utils.use_sa = 0;
		return ;
	}
	tmp = lst->next;
	temp = tmp->nb;
	lst->next->nb = lst->nb;
	lst->nb = temp;
	if (data->utils.use_sa == 0)
	{
		data->utils.count++;
		ft_printf("sa\n");
	}
	else
		data->utils.use_sa = 0;
}

void	sb(t_lst *lst, t_data *data)
{
	t_lst	*tmp;
	int		temp;

	if (!lst->next || !lst)
	{
		data->utils.use_sb = 0;
		return ;
	}
	tmp = lst->next;
	temp = tmp->nb;
	lst->next->nb = lst->nb;
	lst->nb = temp;
	if (data->utils.use_sb == 0)
	{
		data->utils.count++;
		ft_printf("sb\n");
	}
	else
		data->utils.use_sb = 0;
}

void	ss(t_data *data)
{
	data->utils.use_sa = 1;
	data->utils.use_sb = 1;
	if (data->lsta && data->lsta->next)
		sa(data->lsta, data);
	if (data->lstb && data->lstb->next)
		sb(data->lstb, data);
	data->utils.count++;
	ft_printf("ss\n");
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
	data->utils.count++;
	free(tmp);
	ft_printf("pb\n");
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
	data->utils.count++;
	free(tmp);
	ft_printf("pa\n");
}
