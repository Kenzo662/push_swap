/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:43:55 by klopez            #+#    #+#             */
/*   Updated: 2024/01/17 18:39:53 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	j;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	j = 0;
	while (dest[j] && j < size)
		j++;
	if (size <= j)
	{
		return (srclen + size);
	}
	while (src[i] && (j + i < size - 1))
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (j + srclen);
}
