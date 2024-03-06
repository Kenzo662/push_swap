/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:46:00 by kenz              #+#    #+#             */
/*   Updated: 2024/03/05 00:52:48 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(t_data *data)
{
	t_lst	*temp;
	t_lst	*next;

	temp = data->lsta;
	next = data->lsta->next;
	while (temp->next)
	{
		if (temp->nb > next->nb)
			return (1);
		temp = next;
		next = next->next;
	}
	return (0);
}

void	freetab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	freelist(t_lst *lst)
{
	t_lst	*next;

	if (!lst)
		return ;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

int	cut_while(int i, int target, int *tab)
{
	while (i > 0)
	{
		if (tab[0] > tab[i - 1])
		{
			target = tab[i - 1];
			tab[0] = tab[i - 1];
		}
		else
			target = tab[0];
		i--;
	}
	return (target);
}

void	algo_b_to_a(t_data *data)
{
	int	i;

	i = 0;
	sort_three(data);
	i = data->utils.len_b;
	while (i > 0)
	{
		set_list_b(data);
		execute_b(data, data->lsta);
		i--;
	}
	last_move(data, data->lsta);
}
