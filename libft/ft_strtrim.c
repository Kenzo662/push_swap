/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:38:59 by klopez            #+#    #+#             */
/*   Updated: 2023/10/09 18:01:58 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iend(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = ft_strlen(s1) - 1;
	k = 1;
	while (s1[i] && k > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i--;
				break ;
			}
			j++;
			if (set[j] == '\0')
				k = 0;
		}
	}
	return (i);
}

static int	ft_istart(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	k = 1;
	while (s1[i] && k > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i++;
				break ;
			}
			j++;
			if (set[j] == '\0')
				k = 0;
		}
	}
	return (i);
}

static char	*ft_strtrimcut(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = ft_istart(s1, set);
	j = ft_iend(s1, set);
	if (i > j)
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	k = 0;
	str = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!str)
		return (NULL);
	while (i <= j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;

	if (!s1[0] && !set[0])
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	else if (!set[0])
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s1, ft_strlen(s1) + 1);
		return (str);
	}
	return (ft_strtrimcut(s1, set));
}
