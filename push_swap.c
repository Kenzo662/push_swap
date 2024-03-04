/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 04:01:02 by kenz              #+#    #+#             */
/*   Updated: 2024/03/04 04:53:05 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;
	char	**tab;

	data.lsta = NULL;
	data.lstb = NULL;
	if (ac > 2)
	{
		init_data(&data);
		init_lst_a(av, ac, &data);
		tab = init_tab(av, ac, &data);
		check_argv(tab, &data);
		algorithm(&data);
		freetab(tab);
		freelist(data.lsta);
	}
	else
		ft_printf("Besoin d'arguments!\n");
}
