/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:43:33 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/03 15:16:31 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

double	get_gradient(int ini, int fin, int at)
{
	double	dact;
	double	dtot;

	dact = at - ini;
	dtot = fin - ini;
	if (dtot == 0)
		return (1.0);
	return (dact / dtot);
}

int	get_scale(int start, int end, double perc)
{
	return ((int) end * perc + start * (1 - perc));
}

int	get_rgb(t_coord end, t_coord ini, t_coord p)
{
	double	perc;
	int		r;
	int		g;
	int		b;

	if (p.color == end.color)
		return (p.color);
	if (abs(end.x - ini.x) > abs(end.y - ini.y))
		perc = get_gradient(ini.x, end.x, p.x);
	else
		perc = get_gradient(ini.y, end.y, p.y);
	r = get_scale((ini.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, perc);
	g = get_scale((ini.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, perc);
	b = get_scale(ini.color & 0xFF, end.color & 0xFF, perc);
	return (r << 16 | g << 8 | b);
}

int	ft_randrgb(int z)
{
	int	color;

	if (z == 0)
		color = 0xE6F9AF;
	else if (z < 0)
		color = 0xBDADEA;
	else
		color = 0xBD93BD;
	return (color);
}
