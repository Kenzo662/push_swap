/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:51:11 by klopez            #+#    #+#             */
/*   Updated: 2023/10/23 14:38:06 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			count += ft_format(s[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &s[i], 1);
			i++;
			count++;
		}
	}
	return (count);
}

int	ft_format(const char c, va_list args)
{
	int	nb;

	nb = 0;
	if (c == 'd' || c == 'i')
		nb = ft_integer(va_arg(args, int));
	if (c == 's')
		nb = ft_char(va_arg(args, char *));
	if (c == 'c')
		nb = ft_putchar(va_arg(args, int));
	if (c == 'u')
		nb = ft_uinteger(va_arg(args, unsigned int));
	if (c == 'x')
		nb = ft_nbrhexa(va_arg(args, int), 0);
	if (c == 'X')
		nb = ft_nbrhexa(va_arg(args, int), 1);
	if (c == 'p')
		nb = ft_format2(c, args);
	if (c == '%')
		nb = ft_putchar('%');
	return (nb);
}

int	ft_format2(const char c, va_list args)
{
	int				nb;
	unsigned long	temp;

	nb = 0;
	temp = 0;
	if (c == 'p')
	{
		temp = (va_arg(args, unsigned long));
		if (!temp)
		{
			write(1, "(nil)", 5);
			nb += 5;
		}
		else
		{
			write(1, "0x", 2);
			nb += ft_nbrptr(temp) + 2;
		}
	}
	return (nb);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_char(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		i += 6;
		return (i);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
