/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:40:49 by mclerico          #+#    #+#             */
/*   Updated: 2021/11/25 21:42:52 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
void	ft_reset(t_prog *f)
{
	int	i;

	i = 0;
	while (i < f->h * f->w)
	{
		f->matrix[i].x = i % f->w;
		f->matrix[i].y = i / f->w;
		i++;
	}
	if (f->persp == 1)
		f->iso = 0;
}

void	ft_handle(t_coord *m, t_prog *f)
{
	int	i;
	int	xoff;
	int	yoff;

	i = 0;
	xoff = 0;
	yoff = 0;
	while (i < f->h * f->w)
	{
		m[i].x = m[i].x + f->move_x;
		m[i].y = m[i].y + f->move_y;
		i++;
	}
	f->move_x = 0;
	f->move_y = 0;
}
