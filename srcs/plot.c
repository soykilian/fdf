/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:37:46 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/03 15:27:36 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h> 
#include <stdio.h>

void	ft_scale_matrix(t_coord *m, t_prog *f)
{
	int		i;
	float	scale;

	scale = ft_scale(f->h, f->w);
	if (f->zoom)
		scale = f->k + 2;
	i = 0;
	while (i < f->h * f->w)
	{
		m[i].x *= scale;
		m[i].y *= scale;
		i++;
	}
	f->k = scale;
}

void	ft_iso(t_coord *m, t_prog *f)
{
	int		i;
	int		p_x;
	int		p_y;
	float	k;

	i = 0;
	k = ft_scale(f->h, f->w);
	f->iso = 1;
	while (i < f->w * f->h)
	{
		p_x = m[i].x;
		p_y = m[i].y;
		m[i].x = (p_x - p_y) * cos(0.523599);
		m[i].y = -m[i].z * (k / 3) + sin(0.523599) * (p_x + p_y);
		i++;
	}
}

void	ft_center(t_coord *m, t_prog *f)
{
	int	xoffset;	
	int	yoffset;
	int	i;

	ft_scale_matrix(m, f);
	if (f->iso == 0)
		ft_iso(m, f);
	xoffset = abs(m[0].x - m[(f->h * f->w) - 1].x);
	xoffset = (1920 - xoffset) / 2;
	yoffset = abs(m[f->w - 1].y - m[f->w * (f->h - 1)].y);
	yoffset = (1080 - yoffset) / 2;
	f->move_y = 0;
	f->move_x = 0;
	i = 0;
	while (i < f->h * f->w)
	{
		m[i].x = m[i].x + xoffset;
		m[i].y = m[i].y + yoffset;
		i++;
	}
}

float	ft_scale(int r, int c)
{
	float	xsize;	
	float	ysize;	

	xsize = (1920 * 0.5) / (c - 1);
	ysize = (1080 * 0.4) / (r - 1);
	if (xsize <= ysize)
		return (xsize);
	return (ysize);
}
