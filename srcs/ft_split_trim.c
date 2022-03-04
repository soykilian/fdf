/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_trim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:48:51 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/02 19:48:54 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

char	**ft_split_trim(char *str, char c)
{
	char	*line;
	char	**sol;

	line = ft_strtrim(str, "\n");
	sol = ft_split(line, c);
	free(line);
	return (sol);
}
