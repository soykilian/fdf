/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <mclerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:38:18 by mclerico          #+#    #+#             */
/*   Updated: 2021/11/19 19:25:03 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *line)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i += 1;
	new = malloc(ft_len(line) - i + 1);
	if (!new)
		return (NULL);
	while (line[i])
		new[j++] = line[i++];
	new[j] = 0;
	free(line);
	if (new[0] != 0)
		return (new);
	free(new);
	return (NULL);
}

char	*get_first(char *line)
{
	char	*temp;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!line)
		return (NULL);
	while (line[len] && line[len] != '\n')
		len++;
	if (line[len] == '\n')
		len += 1;
	temp = malloc(len + 1);
	if (!temp)
		return (NULL);
	while (i < len)
	{
		temp[i] = line[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			red;
	static char	*line;

	red = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (red && newline(line) == -1)
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[red] = 0;
		line = ft_gnl_strjoin(line, buffer);
	}
	free(buffer);
	buffer = get_first(line);
	line = get_line(line);
	return (buffer);
}
