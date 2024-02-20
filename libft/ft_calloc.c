/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:00:24 by klopez            #+#    #+#             */
/*   Updated: 2023/10/09 13:00:33 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size == 0 || nmemb == 0)
	{
		return (malloc(0));
	}
	tab = malloc(nmemb * size);
	if (tab == 0)
	{
		return (NULL);
	}
	if (tab)
		ft_memset(tab, 0, nmemb * size);
	return (tab);
}
