/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:09:10 by kenz              #+#    #+#             */
/*   Updated: 2024/03/06 21:39:34 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		read_output(&data);
		if (already_sorted(&data) == 0)
		{
			printf("OK\n");
			freelist(&data);
			freetab(tab);
			exit(0);
		}
		printf("KO\n");
		freelist(&data);
		freetab(tab);
	}
}

void	read_output(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		line = cutline(line);
		check_output(line, data);
		free(line);
		line = get_next_line(0);
	}
}

char	*cutline(char *str)
{
	char	*newstr;
	int		i;

	if (!str)
		return (free(str), NULL);
	i = -1;
	newstr = ft_calloc(ft_strlen(str), sizeof(char));
	while (str[++i] != '\n')
		newstr[i] = str[i];
	return (free(str), newstr);
}

void	check_output(char *str, t_data *data)
{
	if (ft_strcmp(str, "pb") == 0)
		pb(data);
	else if (ft_strcmp(str, "pa") == 0)
		pa(data);
	else if (ft_strcmp(str, "rra") == 0)
		rra(data, data->lsta);
	else if (ft_strcmp(str, "rrb") == 0)
		rrb(data, data->lstb);
	else if (ft_strcmp(str, "rrr") == 0)
		rrr(data, data->lsta, data->lstb);
	else if (ft_strcmp(str, "ra") == 0)
		ra(data);
	else if (ft_strcmp(str, "rb") == 0)
		rb(data);
	else if (ft_strcmp(str, "sa") == 0)
		sa(data->lsta);
	else if (ft_strcmp(str, "sb") == 0)
		sb(data->lstb);
	else if (ft_strcmp(str, "rr") == 0)
		rr(data);
	else
	{
		ft_printf("Error\n");
		return (freelist(data), exit(0));
	}
}
