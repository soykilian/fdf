/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:14:01 by mclerico          #+#    #+#             */
/*   Updated: 2021/10/14 15:38:35 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*output;
	size_t	i;

	i = 0;
	output = (char *)malloc(nmemb * size);
	if (!output)
		return (output);
	while (i < (size * nmemb))
	{
		output[i] = 0;
		i++;
	}
	return ((void *)output);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

void	ft_unsigned(unsigned int n, int *c)
{
	if (n >= 10 )
	{
		ft_unsigned(n / 10, c);
		ft_unsigned(n % 10, c);
	}
	else
	{
		ft_putchar(n + '0');
		*c += 1;
	}
}

void	ft_params(char f, va_list arg, int *c)
{
	if (f == 'i' || f == 'd')
		ft_putnbr(va_arg(arg, int), c);
	else if (f == 'c')
		*c += ft_putchar(va_arg(arg, int));
	else if (f == 's')
		*c += ft_putstr(va_arg(arg, char *));
	else if (f == 'p')
		*c += ft_address(va_arg(arg, void *));
	else if (f == 'x' || f == 'X')
		*c += ft_hex(va_arg(arg, int), (char)f);
	else if (f == 'u')
		ft_unsigned(va_arg(arg, unsigned int), c);
	else if (f == '%')
		*c += write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		c;

	i = 0;
	c = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		while (format[i] == '%')
		{
			if (format[i + 1] && ft_valid(format[i + 1]))
			{
				ft_params((char) format[i + 1], arg, &c);
				i += 2;
			}
			break;
		}
		if (format[i] != '\0')
		{
			ft_putchar(format[i++]);
			c++;
		}
	}
	va_end(arg);
	return (c);
}
