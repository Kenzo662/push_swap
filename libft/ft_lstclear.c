/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:22:27 by klopez            #+#    #+#             */
/*   Updated: 2023/10/12 19:25:47 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*nextelem;

	temp = *lst;
	while (temp != NULL)
	{
		nextelem = temp->next;
		if (temp->content != NULL)
		{
			del(temp->content);
		}
		free(temp);
		temp = nextelem;
	}
	*lst = NULL;
}
