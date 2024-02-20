/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:23:49 by klopez            #+#    #+#             */
/*   Updated: 2023/12/18 19:19:28 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoingnl(char *s1, const char *s2)
{
	char	*s3;
	size_t	totallen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	totallen = ft_strlengnl(s2) + 1;
	if (s1)
		totallen += ft_strlengnl(s1);
	s3 = malloc(sizeof(char) * (totallen));
	if (!s3)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			s3[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (free(s1), s3);
}

int	ft_boolstrchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_cutline(char *str, char c)
{
	int		i;
	int		count;
	char	*tmp;

	count = 0;
	i = 0;
	while (str[count] && str[count] != c)
		count++;
	if (str[count] == c)
		count++;
	tmp = malloc(sizeof(char) * (count + 1));
	ft_memsetgnl(tmp, '\0', count + 1);
	if (!tmp)
		return (NULL);
	while (str[i] && str[i] != c)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = str[i];
	if (str)
		free(str);
	return (tmp);
}

void	*ft_memsetgnl(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (s);
}

size_t	ft_strlcpygnl(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j] != '\0')
	{
		j++;
	}
	if (size == 0)
	{
		return (j);
	}
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}
