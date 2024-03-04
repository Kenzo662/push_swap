/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:27:17 by klopez            #+#    #+#             */
/*   Updated: 2024/03/04 04:42:56 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_argv(char **tab, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = 1;
	while (tab[++i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) == 0)
			{
				ft_printf
				("Two numbers have the same value, send a valid list!\n");
				freelist(data->lsta);
				freetab(tab);
				exit(0);
			}
			j++;
		}
	}
	check_av_char(tab, data);
}

void	check_av_char(char **tab, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (tab[++i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]) == 0)
			{
				ft_printf("Wrong arguments, please send a valid list!\n");
				freelist(data->lsta);
				freetab(tab);
				exit(0);
			}
			j++;
		}
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
