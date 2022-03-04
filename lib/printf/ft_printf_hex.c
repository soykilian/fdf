/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:38:57 by mclerico          #+#    #+#             */
/*   Updated: 2021/09/27 18:53:17 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(int n)
{
	int	k;

	k = 0;
	if (n <= 0)
	{
		k++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		k++;
	}
	return (k);
}

int	ft_printstr(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = ft_strlen(str);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	return (i);
}

int	dec_char_hex(unsigned long n)
{
	char				*pi;
	int					i;
	int					t;

	t = 0;
	i = 15;
	pi = ft_calloc(16 + 1, 1);
	if (n == 0)
		pi[i--] = 48;
	while (n != 0)
	{
		t = n % 16;
		if (t < 10)
			t = t + 48;
		else
			t = t + 87;
		pi[i--] = t;
		n = n / 16;
	}
	ft_printhex(&pi[i + 1]);
	t = ft_strlen(&pi[i + 1]);
	free (pi);
	return (t + 2);
}

int	ft_address(void *add)
{
	char			*c;
	long unsigned	dir;

	c = add;
	dir = (long unsigned) c;
	return (dec_char_hex(dir));
}

int	ft_hex(int n, char c)
{
	char			*pi;
	int				i;
	unsigned int	t;
	unsigned int	dec;

	dec = n;
	t = 0;
	i = 7;
	pi = ft_calloc(8 + 1, 1);
	if (n == 0)
		pi[i--] = 48;
	while (dec != 0 && i > -1)
	{
		t = dec % 16;
		if (t < 10)
			t = t + 48;
		else
			t = t + c - 33;
		pi[i--] = t;
		dec = dec / 16;
	}
	t = ft_printstr(&pi[i + 1]);
	free(pi);
	return (t);
}
