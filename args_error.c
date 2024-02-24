/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:17:31 by kenz              #+#    #+#             */
/*   Updated: 2024/02/24 16:26:53 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    check_args_value(char **av, int ac)
{
    int i;
    int j;

    i = 1;
    j = 2;
    if (ac == 2)
    {
        check_number(av);
        av = ft_split(av[1], ' ');
        i = 0;
    }
    while(av[i])
    {
        j = i + 1;
        while(av[j])
        {
            if (ft_strcmp(av[i], av[j]) == 0)
                {
                    ft_printf("Two numbers have the same value, please send a valid list!\n");
                    exit(0);
                }
            j++;
        }
        i++;
    }
    check_args_char(av, ac);
}

void    check_args_char(char **av, int ac)
{
    int i;
    int j;

    i = 1;
    j = 0;
    if (ac == 2)
        i = 0;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (ft_isdigit(av[i][j]) == 0)
            {
                ft_printf("Wrong arguments, please send a valid list!\n");
                exit(0);
            }
            j++;   
        }
        i++;
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

void    check_number(char **av)
{
    int i;

    i = 0;
    while (av[1][i] == ' ')
        i++;
    while (av[1][i] != ' ')
        i++;
    while (av[1][i] == ' ')
        i++;
    if (ft_isdigit(av[1][i]) == 0)
        {
            ft_printf("Wrong or too few arguments, please send a valid list!\n");
            exit(0);
        }
}


