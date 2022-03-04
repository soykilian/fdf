/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:31:08 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/06 16:58:08 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	ft_numberint(char n)
{
	if (ft_isdigit(n))
		return (n - 48);
	else
		return (ft_toupper(n) - 55);
}

int	ft_hex(char *n)
{
	int	len;
	int	sol;
	int	i;

	if (n[0] != '0' || n[1] != 'x' || ft_strlen(n) > 8 || ft_strlen(n) < 3)
		return (0);
	n += 2;
	while (*n == '0')
		n++;
	len = ft_strlen(n);
	i = len - 1;
	sol = 0;
	while (i > -1)
	{
		if (ft_strrchr("0123456789ABCDEFabcdef", n[i]))
			sol += (ft_numberint(n[i]) * pow(16, len - i - 1));
		else
			return (0xfffff);
		i--;
	}
	return (sol);
}

int	check_is_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (str == base[i])
			return (1);
		i++;
	}
	return (0);
}

t_coord	*vectorize(t_coord *m, char **n, int size, int y)
{
	t_coord	*vector;
	char	**split;
	int		i;
	int		j;

	i = -1;
	j = -1;
	vector = (t_coord *)ft_calloc(sizeof(t_coord), (size * (y + 1)));
	while (++i < (size * y))
		vector[i] = (t_coord){m[i].x, m[i].y, m[i].z, m[i].color};
	while (n[++j])
	{
		split = ft_split(n[j], ',');
		if (!ft_atoi_check(split[0]) || !bool_digits(split[0]))
			return (NULL);
		if (split[1])
			vector[i] = (t_coord){j, y, ft_atoi(split[0]), ft_hex(split[1])};
		else
			vector[i] = (t_coord){j, y, ft_atoi(split[0]),
				ft_randrgb(ft_atoi(split[0]))};
		ft_free_split(split);
		i++;
	}
	free(m);
	return (vector);
}

void	ft_fill_matrix(int fd, t_coord **matrix, t_prog *f)
{
	char	*line;
	char	**n;
	int		size;
	int		r;

	line = get_next_line(fd);
	n = ft_split_trim(line, ' ');
	size = ft_sizem(n);
	r = 0;
	while (line)
	{
		if (ft_sizem(n) != size)
			return ;
		*matrix = vectorize(*matrix, n, size, r);
		if (*matrix == NULL)
			return ;
		free(line);
		line = get_next_line(fd);
		ft_free_split(n);
		n = ft_split_trim(line, ' ');
		r++;
	}
	ft_matrix_ini(f, r, size);
}
