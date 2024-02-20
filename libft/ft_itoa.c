/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:37:20 by klopez            #+#    #+#             */
/*   Updated: 2023/12/18 19:26:23 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_countnbitoa(int c)
{
	int	count;

	count = 0;
	if (c < 0)
	{
		count++;
		c = c * -1;
	}
	while (c / 10 > 0)
	{
		c = c / 10;
		count++;
	}
	count++;
	return (count);
}

static char	*ft_calcul(int n, int j, char *str, int y)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		y++;
		j--;
	}
	while (j > 1)
	{
		len = len * 10;
		j--;
	}
	while ((len / 10) > 0)
	{
		str[y] = (n / len) + '0';
		n %= len;
		len /= 10;
		y++;
	}
	str[y++] = (n / len) + '0';
	str[y] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		j;
	int		y;

	y = 0;
	j = ft_countnbitoa(n);
	if (n == -2147483648)
	{
		str = malloc(sizeof(char) * 12);
		if (!str)
			return (NULL);
		ft_strcpy(str, "-2147483648");
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	return (ft_calcul(n, j, str, y));
}
