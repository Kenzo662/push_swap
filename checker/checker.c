/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:09:10 by kenz              #+#    #+#             */
/*   Updated: 2024/03/06 05:22:22 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.lsta = NULL;
	data.lstb = NULL;
	if (ac > 4)
	{
		init_data(&data);
		init_lst_a(av, ac, &data);
		read_output(&data);
		if (already_sorted(&data) == 0)
		{
			printf("OK\n");
			freelist(data.lsta);
			exit(0);
		}
		printf("KO\n");
		freelist(data.lsta);
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
	if (str[0] == 'p' && str[1] == 'b')
		pb(data);
	else if (str[0] == 'p' && str[1] == 'a')
		pa(data);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		rra(data, data->lsta);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		rrb(data, data->lstb);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		rrr(data, data->lsta, data->lstb);
	else if (str[0] == 'r' && str[1] == 'a')
		ra(data);
	else if (str[0] == 'r' && str[1] == 'b')
		rb(data);
	else if (str[0] == 's' && str[1] == 'a')
		sa(data->lsta);
	else if (str[0] == 's' && str[1] == 'b')
		sb(data->lstb);
	else if (str[0] == 'r' && str[1] == 'r')
		rr(data);
	else
	{
		ft_printf("Error\n");
		return (freelist(data->lsta), exit(0));
	}
}
