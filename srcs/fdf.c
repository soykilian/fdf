/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:47:14 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/03 16:20:03 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdlib.h>

void	ft_move(int keycode, t_prog *f)
{
	if (keycode == 126)
		f->move_y = -Y_OFFSET;
	else if (keycode == 123)
		f->move_x = -X_OFFSET;
	else if (keycode == 125)
		f->move_y = Y_OFFSET;
	else if (keycode == 124)
		f->move_x = X_OFFSET;
	ft_try_lines(f->matrix, f);
}

void	ft_persp(t_prog *f)
{
	f->iso = 1;
	if (f->persp == 2)
	{
		f->iso = 0;
		f->persp = 1;
	}
	else
		f->persp = 2;
	ft_reset(f);
	ft_try_lines(f->matrix, f);
}

void	ft_zoom_pic(t_prog *f)
{
	f->zoom = 1;
	ft_reset(f);
	ft_try_lines(f->matrix, f);
	f->zoom = 0;
}

int	events(int keycode, t_prog *f)
{
	if (keycode == 53)
	{
		mlx_destroy_window(f->mlx, f->win);
		mlx_destroy_image(f->mlx, f->img.img);
		free(f->matrix);
		exit(0);
	}
	else if (keycode > 122 && keycode < 127)
		ft_move(keycode, f);
	else if (keycode == 36)
	{
		ft_reset(f);
		ft_try_lines(f->matrix, f);
	}
	else if (keycode == 258)
		ft_persp(f);
	else if (keycode == 24)
		ft_zoom_pic(f);
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_prog	f;

	if (argc != 2 || !argv)
		return (1);
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, 1920, 1080, "Hello world!");
	mlx_hook(f.win, 2, 1L << 0, events, &f);
	fd = open(argv[1], O_RDONLY);
	f.img.img = mlx_new_image(f.mlx, 1920, 1080);
	f.img.addr = mlx_get_data_addr(f.img.img, &(f.img.bits_per_pixel),
			&(f.img.line_length), &(f.img.endian));
	ft_fill_matrix(fd, &(f.matrix), &f);
	if (f.h < 1 || f.w < 1 || !f.matrix)
		return (1);
	ft_try_lines(f.matrix, &f);
	system("leaks fdf");
	mlx_loop(f.mlx);
}
