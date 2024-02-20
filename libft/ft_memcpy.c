/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:42:07 by klopez            #+#    #+#             */
/*   Updated: 2023/10/09 13:44:47 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*source;

	i = 0;
	dst = dest;
	source = src;
	if (source == 0 && dest == 0)
	{
		return (0);
	}
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dest);
}
