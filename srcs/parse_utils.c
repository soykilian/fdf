/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:25:47 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/06 16:40:06 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
void	ft_free_split(char **s)
{
	char	**str;

	str = s;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(s);
}

int	ft_atoi_check(char *n)
{
	int				sign;
	char			*nptr;
	unsigned int	res;
	int				i;

	sign = 1;
	res = 0;
	i = 0;
	nptr = ft_strtrim(n, "\n");
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = (res * 10) + (nptr[i] - 48);
		if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1))
			return (0);
		i++;
	}
	free(nptr);
	return (1);
}

int	bool_digits(char *n)
{
	int		i;
	char	*nbr;

	i = 0;
	nbr = ft_strtrim(n, "\n");
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	if (nbr[i] == '-' || nbr[i] == '+')
		return (0);
	free(nbr);
	return (1);
}

int	ft_sizem(char **n)
{
	int	size;

	size = 0;
	if (!n)
		return (0);
	while (n[size])
		size++;
	return (size);
}

void	ft_matrix_ini(t_prog *f, int r, int size)
{
	f->zoom = 0;
	f->h = r;
	f->w = size;
	f->iso = 0;
	f->zoom = 0;
	f->persp = 1;
	f->k = 0;
}
