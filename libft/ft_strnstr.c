/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:42:20 by klopez            #+#    #+#             */
/*   Updated: 2023/10/15 15:36:53 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[i] == 0)
		return ((char *)str);
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (to_find[j] != '\0' && i < n && (to_find[j] == str[i]))
		{
			j++;
			i++;
		}
		if (to_find[j] == 0)
			return ((char *)&str[i - j]);
		i = i - j + 1;
	}
	return (NULL);
}
