/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:04:37 by mjlem             #+#    #+#             */
/*   Updated: 2022/05/27 18:04:39 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"

# define WIN_W 1920
# define WIN_H 1080
# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define D 2
# define S 1
# define A 0
# define W 13
# define Q 12
# define E 14
# define P 35
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define PLUS 69
# define MINUS 78
# define R 15

typedef struct s_var
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	z0;
	int	z1;
	int	pad_x;
	int	pad_y;

}	t_var;

typedef struct s_data
{
	int		height;
	int		width;
	char	**map;
	int		**numbers;
	int		**colors;
}	t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		zoom;
	t_data	data;
	int		applying_iso;
	int		add_to_x;
	int		add_to_y;
	int		type;
	double	alpha;
	double	beta;
	double	gamma;
	int		add_c;
}	t_mlx;

typedef struct s_math
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}	t_math;

char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_atoi(char *str);
void	get_altitude(t_data *var);
void	read_map(int fd, t_data *data);
void	get_color(t_data *var);
void	draw(t_mlx *mlx);
int		key(int keyp, t_mlx *mlx);
int		destroy(t_mlx *mlx);
int		mouse(int keyp, int x, int y, t_mlx *mlx);
void	print_on_map(t_mlx *mlx);
void	init_vars(t_mlx	*mlx);
void	double_free(void **data);
int		conv_hex(char	*color);
char	**conv_color(t_data *var, char **buf, int i);
void	get_color(t_data *var);
int		is_base(char hex);
int		ft_power(int nb, int power);
void	check_len(int j, t_data *var);
void	rotate(t_var *var, t_mlx *mlx);
void	print_on_map(t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	centering_map(t_var *var, t_mlx *mlx);
void	iso(t_var *var);
void	get_valus(t_var *vars, t_math *math);
void	centering(t_var *var, t_mlx *mlx);
void	zoom(t_var *var, t_mlx *mlx);
void	rotate_z(t_var *var, t_mlx *mlx);
#endif
