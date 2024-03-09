/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 04:01:02 by kenz              #+#    #+#             */
/*   Updated: 2024/03/06 20:06:38 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;
	char	**tab;

	data.lsta = NULL;
	data.lstb = NULL;
	if (ac >= 2)
	{
		init_data(&data);
		init_lst_a(av, ac, &data);
		tab = init_tab(av, ac, &data);
		check_argv(tab, &data);
		if (already_sorted(&data) == 0)
		{
			freetab(tab);
			freelist(&data);
			exit(0);
		}
		algorithm(&data);
		freetab(tab);
		freelist(&data);
	}
	else
		write(2, "Error\n", 6);
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

void	sort_two(t_data *data)
{
	if (data->lsta->nb > data->lsta->next->nb)
		sa(data->lsta, data);
}
