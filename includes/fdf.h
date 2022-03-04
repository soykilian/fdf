/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:49:21 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/06 16:28:12 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h> 
# include <fcntl.h>
# include <math.h>
# include <libft.h>

typedef struct s_coord{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_coord;

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_prog{
	int		h;
	int		w;
	int		iso;
	int		zoom;
	int		persp;
	float	k;
	void	*mlx;
	void	*win;
	t_data	img;
	t_coord	*matrix;
	int		move_y;
	int		move_x;
}				t_prog;

# define H_WINDOW 1080
# define W_WINDOW 1920

# define X_OFFSET 20
# define Y_OFFSET 20
void	ft_legend(t_prog *f);
char	**ft_split_trim(char *str, char c);
void	ft_free_split(char **s);
int		bool_digits(char *n);
int		ft_atoi_check(char *n);
int		ft_sizem(char **n);
void	ft_scale_matrix(t_coord *m, t_prog *f);
int		m_len(t_coord *m);
void	plot_liney(t_coord p0, t_coord p1, t_data img);
void	plot_linex(t_coord p0, t_coord p1, t_data img);
void	plot_line(t_coord p0, t_coord p1, t_data img);
void	ft_handle(t_coord *m, t_prog *f);
void	ft_try_lines(t_coord *matrix, t_prog *f);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_rgb(t_coord end, t_coord ini, t_coord p);
float	ft_scale(int r, int c);
void	ft_center(t_coord *m, t_prog *f);
void	ft_matrix_ini(t_prog *f, int r, int size);
int		ft_randrgb(int z);
void	ft_fill_matrix(int fd, t_coord **matrix, t_prog *f);
t_coord	max_point(t_coord *matrix);
void	ft_reset(t_prog *f);
t_coord	*iso_transf(t_coord *m, int size);
#endif
