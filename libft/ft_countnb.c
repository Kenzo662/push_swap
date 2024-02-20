/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:36:10 by klopez            #+#    #+#             */
/*   Updated: 2023/10/18 19:48:58 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countnb(int c)
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

int	ft_countnbu(unsigned int c)
{
	int	count;

	count = 0;
	while (c / 10 > 0)
	{
		c = c / 10;
		count++;
	}
	count++;
	return (count);
}

int	ft_countnbhex(unsigned int c)
{
	int	count;

	count = 0;
	while (c / 16 > 0)
	{
		c = c / 16;
		count++;
	}
	count++;
	return (count);
}

int	ft_countnbhexl(unsigned long c)
{
	int	count;

	count = 0;
	while (c / 16 > 0)
	{
		c = c / 16;
		count++;
	}
	count++;
	return (count);
}
