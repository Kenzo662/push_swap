/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:46:00 by kenz              #+#    #+#             */
/*   Updated: 2024/03/04 04:55:56 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_all_lst(t_lst *lsta, t_lst *lstb)
{
	ft_printf("<------------------------------------>\n");
	if (!lsta)
		ft_printf("La liste [A] est vide, rien a afficher\n");
	else
	{
		ft_printf("Liste [A] :\n");
		while (lsta)
		{
			ft_printf("  %d\n", lsta->nb);
			lsta = lsta->next;
		}
	}
	ft_printf("<------------------------------------>\n");
	if (!lstb)
	{
		ft_printf("La liste [B] est vide, rien a afficher\n");
		return ;
	}
	ft_printf("Liste [B] :\n");
	while (lstb)
	{
		ft_printf("  %d\n", lstb->nb);
		lstb = lstb->next;
	}
	ft_printf("<------------------------------------>\n");
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
