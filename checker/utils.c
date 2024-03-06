/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:16:23 by kenz              #+#    #+#             */
/*   Updated: 2024/03/06 05:09:24 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
