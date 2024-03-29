/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:10:19 by kenz              #+#    #+#             */
/*   Updated: 2024/03/06 21:39:47 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_data(t_data *data)
{
	data->utils.len_a = 0;
	data->utils.len_b = 0;
}

void	init_lst_a(char **av, int ac, t_data *data)
{
	int		i;
	int		j;
	int		nb;
	char	**tab;

	i = 1;
	data->lsta = NULL;
	while (i < ac)
	{
		tab = ft_split(av[i], ' ');
		j = -1;
		while (tab[++j])
		{
			nb = ft_atoi(tab[j]);
			data->lsta = push_back(data->lsta, nb);
			data->utils.len_a++;
		}
		freetab(tab);
		i++;
	}
}

char	**init_tab(char **av, int ac, t_data *data)
{
	int		i;
	int		j;
	int		k;
	char	**newtab;
	char	**tab;

	i = 1;
	k = 0;
	newtab = ft_calloc(data->utils.len_a + 1, sizeof(char *));
	while (i < ac)
	{
		tab = ft_split(av[i], ' ');
		j = 0;
		while (tab[j])
		{
			newtab[k] = ft_strdup(tab[j]);
			k++;
			j++;
		}
		freetab(tab);
		i++;
	}
	return (newtab);
}
