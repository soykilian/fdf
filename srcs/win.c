/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:04:32 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/02 20:00:24 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_legend(t_prog *f)
{
	int		y;
	void	*mlx;
	void	*win;

	mlx = f->mlx;
	win = f->win;
	y = 0;
	mlx_string_put(mlx, win, 15, y += 15, 0xf9b9f2, "GUIDE: Keyboard ENG");
	mlx_string_put(mlx, win, 15, y += 45, 0xf9b9f2, "RESET : Enter");
	mlx_string_put(mlx, win, 15, y += 75, 0xf9b9f2, "ZOOM OUT : +");
	mlx_string_put(mlx, win, 15, y += 105, 0xf9b9f2, "MOVE : Arrow Keys");
	mlx_string_put(mlx, win, 15, y += 105, 0xf9b9f2,
		"TOGGLE PERSPECTIVE : Shift");
}
