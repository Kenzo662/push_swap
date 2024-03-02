/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:46:00 by kenz              #+#    #+#             */
/*   Updated: 2024/03/02 18:47:07 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_lst(t_lst *lst)
{
    if (!lst)
        {
            ft_printf("La liste est vide, rien a afficher\n");
            return ;
        }
    while(lst)
    {
        ft_printf("nblist = %d\n", lst->nb);
        lst = lst->next;
    }
}

void    print_target(t_lst *lsta)
{
    if (!lsta)
        return ;
    while (lsta)
    {
        printf("la target de %d est %d\n",lsta->nb, lsta->target);
        lsta = lsta->next;
    }
}


void    print_all_lst(t_lst *lsta, t_lst *lstb)
{
    ft_printf("<------------------------------------>\n");
    if (!lsta)
            ft_printf("La liste [A] est vide, rien a afficher\n");
    else 
        {
            ft_printf("Liste [A] :\n");
            while(lsta)
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
    while(lstb)
    {
        ft_printf("  %d\n", lstb->nb);
        lstb = lstb->next;
    }
    ft_printf("<------------------------------------>\n");
}

void    freetab(char **tab)
{
    int i;

    i = -1;
    while (tab[++i])
        free(tab[i]);
    free(tab);
}

void    freelist(t_data *data)
{
    t_lst *next;
    
    if (data->lsta)
    {     
        while (data->lsta)
        {
            next = data->lsta->next;
            free(data->lsta);
            data->lsta = next;
        }
        free(data->lsta);
    }
    if (data->lstb)
    {
        while (data->lstb)
        {
            next = data->lstb->next;
            free(data->lstb);
            data->lstb = next;
        }
        free(data->lstb);
    }
}