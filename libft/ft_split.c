/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:38:15 by klopez            #+#    #+#             */
/*   Updated: 2024/02/21 18:11:27 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strncpy(char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

static int	ft_countword(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
		}
		while (s[i] && s[i] != c)
		{
			i++;
		}
		j++;
	}
	if (s[i - 1] == c)
		j--;
	return (j);
}

static void	*freetab(char **tab, int cword)
{
	while (cword > 0)
	{
		cword--;
		free(tab[cword]);
	}
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s1, char c)
{
	char	**tab;
	int		j;
	int		cword;

	tab = (char **)malloc(sizeof(char *) * (ft_countword(s1, c) + 1));
	if (!tab)
		return (NULL);
	cword = 0;
	s1--;
	while (*(++s1))
	{
		j = 0;
		while (*(s1 + j) && *(s1 + j) != c)
			j++;
		if (j > 0)
		{
			tab[cword] = (char *)malloc(sizeof(char) * (j + 1));
			if (!tab[cword])
				return (freetab(tab, cword));
			ft_strncpy(tab[cword++], s1, j);
			s1 += j - 1;
		}
	}
	tab[cword] = 0;
	return (tab);
}
