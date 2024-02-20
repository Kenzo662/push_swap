/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:27:29 by klopez            #+#    #+#             */
/*   Updated: 2023/10/19 13:48:51 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_integer(int nb);
int	ft_format(const char c, va_list args);
int	ft_format2(const char c, va_list args);
int	ft_char(char *str);
int	ft_putchar(char c);
int	ft_uinteger(unsigned int nb);
int	ft_nbrhexa(unsigned int nb, int format);
int	ft_nbrptr(unsigned long nb);
int	ft_countnb(int c);
int	ft_countnbhex(unsigned int c);
int	ft_countnbu(unsigned int c);
int	ft_countnbhexl(unsigned long c);
int	ft_printf(const char *s, ...);

#endif