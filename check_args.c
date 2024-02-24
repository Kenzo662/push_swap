/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:27:17 by klopez            #+#    #+#             */
/*   Updated: 2024/02/24 18:32:47 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char    **init_tab(char **av, int ac, t_data *data)
{
    int i;
    int j;
    int k;
    char **newtab;
    char **tab;

    i = 1;
    k = 0;
    newtab = ft_calloc(data->utils.len_a + 1, sizeof(char *));
    while (i < ac)
    {
        tab = ft_split(av[i], ' ');
        j = 0;
        while(tab[j])
        {
            printf("tabj = %s\n", tab[j]);
            newtab[k] = ft_strdup(tab[j]);
            k++;
            j++;
        }
        freetab(tab);
        i++;
    }
    return (newtab);
}

void    check_argv(char **tab)
{
    int i;
    int j;

    i = -1;
    j = 1;
    while(tab[++i])
    {
        printf("tab i = %s\n", tab[i]);
        j = i + 1;
        while (tab[j])
        {
            printf("tab j = %s\n", tab[j]);
            if (ft_strcmp(tab[i], tab[j]) == 0)
                {
                    ft_printf("Two numbers have the same value, please send a valid list!\n");
                    exit (0);
                }
            j++;
        }
    }
}