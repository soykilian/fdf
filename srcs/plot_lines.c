/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:44:24 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/03 16:29:47 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 1920 || y >= 1080 || y < 0 || x < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_bigger(int x, int y)
{
	if (x < y)
		return (1);
	return (-1);
}

void	plot_line(t_coord p1, t_coord p2, t_data img)
{
	t_coord	s;
	t_coord	d;
	int		err[2];
	t_coord	p0;

	s = (t_coord){ft_bigger(p1.x, p2.x), ft_bigger(p1.y, p2.y), 0, 0};
	d = (t_coord){abs(p2.x - p1.x), abs(p2.y - p1.y) * -1, 0, 0};
	err[0] = d.x + d.y;
	p0 = p1;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		my_mlx_pixel_put(&img, p1.x, p1.y, get_rgb(p2, p0, p1));
		err[1] = 2 * err[0];
		if (err[1] >= d.y)
		{
			err[0] += d.y;
			p1.x += s.x;
		}
		if (err[1] <= d.x)
		{
			err[0] += d.x;
			p1.y += s.y;
		}
	}
}

void	ft_try_lines(t_coord *matrix, t_prog *f)
{
	int		j;

	j = 0;
	ft_bzero(f->img.addr, W_WINDOW * H_WINDOW * (f->img.bits_per_pixel / 8));
	if (f->move_x == 0 && f->move_y == 0)
		ft_center(matrix, f);
	else
		ft_handle(matrix, f);
	while (j < f->h * f->w)
	{
		if ((j + 1) % f->w != 0)
			plot_line((matrix[j]), (matrix[j + 1]), f->img);
		j++;
	}
	j = 0;
	while (j + f->w < f->h * f->w)
	{
		plot_line((matrix[j]), (matrix[(f->w) + j]), f->img);
		j++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	ft_legend(f);
}
