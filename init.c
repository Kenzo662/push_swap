/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 04:33:38 by kenz              #+#    #+#             */
/*   Updated: 2024/03/02 05:16:40 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void     init_data(t_data *data)
{
    data->utils.len_a = 0;
    data->utils.len_b = 0;
    data->utils.use_sa = 0;
    data->utils.use_sb = 0;
    data->utils.use_ra = 0;
    data->utils.use_rb = 0;
    data->utils.use_rra = 0;
    data->utils.use_rrb = 0;
    data->utils.count = 0;
}
t_lst    *init_lst_a(char **av, int ac, t_data *data)
{
    int i;
    int j;
    int nb;
    t_lst *temp;
    char **tab;

    i = 1;
    temp = NULL;
    while (i < ac)
    {
        tab = ft_split(av[i], ' ');
        j = -1;
        while(tab[++j])
        {
            nb = ft_atoi(tab[j]);
            temp = push_back(temp, nb);
            data->utils.len_a++;
        }
        freetab(tab);
        i++;
    }
    return(temp);
}

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
            newtab[k] = ft_strdup(tab[j]);
            k++;
            j++;
        }
        freetab(tab);
        i++;
    }
    return (newtab);
}

void    init_median(t_data *data)
{
    data->utils.median_lsta = (data->utils.len_a / 2);
    data->utils.median_lstb = (data->utils.len_b / 2);
}
