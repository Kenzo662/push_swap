/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:39:07 by klopez            #+#    #+#             */
/*   Updated: 2023/10/09 15:53:00 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*subs;

	j = 0;
	i = 0;
	if (start > ft_strlen(s))
	{
		subs = (char *)malloc(sizeof(char));
		if (!subs)
			return (NULL);
		subs[0] = '\0';
		return (subs);
	}
	while (s[start + i] && len--)
		i++;
	subs = (char *)malloc((i + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	while (s[start] && j < i)
	{
		subs[j++] = s[start++];
	}
	subs[j] = '\0';
	return (subs);
}
