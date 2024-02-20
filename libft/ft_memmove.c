/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:42:30 by klopez            #+#    #+#             */
/*   Updated: 2023/10/09 13:45:49 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*source;
	size_t		i;

	dst = dest;
	source = src;
	i = -1;
	if (!source && !dest)
		return (0);
	if (dst < source)
	{
		while (++i < n)
			dst[i] = source[i];
	}
	else if (dst > source)
	{
		i = n + 1;
		while (--i > 0)
			dst[i - 1] = source[i - 1];
	}
	return (dest);
}
