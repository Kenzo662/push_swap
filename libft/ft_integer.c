/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:51:27 by klopez            #+#    #+#             */
/*   Updated: 2023/10/20 16:54:55 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_integer(int nb)
{
	int	count;

	count = ft_countnb(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_uinteger(nb / 10);
		ft_uinteger(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (count);
}

int	ft_uinteger(unsigned int nb)
{
	int	count;

	count = ft_countnbu(nb);
	if (nb > 9)
	{
		ft_uinteger(nb / 10);
		ft_uinteger(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (count);
}

int	ft_nbrhexa(unsigned int nb, int format)
{
	int	count;

	count = ft_countnbhex(nb);
	if (nb >= 16)
	{
		ft_nbrhexa(nb / 16, format);
		ft_nbrhexa(nb % 16, format);
	}
	else if (format == 0)
		ft_putchar("0123456789abcdef"[nb]);
	else
		ft_putchar("0123456789ABCDEF"[nb]);
	return (count);
}

int	ft_nbrptr(unsigned long nb)
{
	int	count;

	count = ft_countnbhexl(nb);
	if (nb >= 16)
	{
		ft_nbrptr(nb / 16);
		ft_nbrptr(nb % 16);
	}
	else
		ft_putchar("0123456789abcdef"[nb]);
	return (count);
}
