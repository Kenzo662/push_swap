/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:21:29 by klopez            #+#    #+#             */
/*   Updated: 2023/10/12 19:26:58 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_while(t_list *lst, t_list *newlst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*temp;
	t_list	*startlst;

	startlst = newlst;
	while (lst)
	{
		temp = f(lst->content);
		newlst->next = ft_lstnew(temp);
		if (!newlst->next)
		{
			del(temp);
			ft_lstclear(&startlst, del);
			return (NULL);
		}
		lst = lst->next;
		newlst = newlst->next;
	}
	return (startlst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = f(lst->content);
	newlst = ft_lstnew(temp);
	lst = lst->next;
	if (!newlst)
	{
		del(temp);
		return (NULL);
	}
	return (ft_while(lst, newlst, f, del));
}
