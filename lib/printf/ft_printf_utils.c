/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:44:34 by mclerico          #+#    #+#             */
/*   Updated: 2021/10/14 15:40:04 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(int nbr, int *c)
{
	unsigned int	n;

	if (nbr < 0)
	{
		ft_putchar('-');
		n = (unsigned int) nbr * -1;
		*c += 1;
	}
	else
		n = (unsigned int) nbr;
	if (n >= 10)
	{
		ft_putnbr (n / 10, c);
		ft_putnbr (n % 10, c);
	}
	else
	{
		ft_putchar(n + '0');
		*c += 1;
	}
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = ft_strlen(str);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	return (i);
}

int	ft_valid(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (-1);
}

void	ft_printhex(char *s)
{
	int	i;

	i = 0;
	write(1, "0x", 2);
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
