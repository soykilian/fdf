/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:14:36 by mclerico          #+#    #+#             */
/*   Updated: 2021/11/19 19:24:53 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(char *p)
{
	int	i;

	i = 0;
	if (!p)
		return (0);
	while (p[i])
		i++;
	return (i);
}

int	newline(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_gnl_memmove(void *dest, const void *src, int n)
{
	unsigned char		*destc;
	unsigned char		*srcc;
	int					i;

	destc = (unsigned char *)(dest);
	srcc = (unsigned char *)(src);
	i = n;
	if (dest == src || !n)
		return (dest);
	if (src < dest)
	{
		while (i-- > 0)
			destc[i] = srcc[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			destc[i] = srcc[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*join;
	int		l1;
	int		l2;

	l1 = ft_len(s1);
	l2 = ft_len(s2);
	if ((!s2 && !s1) || (l1 + l2) == 0)
		return (NULL);
	join = malloc((l1 + l2 + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	ft_gnl_memmove(join, s1, l1);
	ft_gnl_memmove(join + l1, s2, l2);
	join[l1 + l2] = 0;
	free(s1);
	return (join);
}
