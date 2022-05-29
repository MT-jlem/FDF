/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:04:31 by mjlem             #+#    #+#             */
/*   Updated: 2022/05/27 18:04:33 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_zoom(t_data *data)
{
	int	map_d;
	int	win_d;
	int	zoom;

	win_d = sqrt(((WIN_H * WIN_H) + (WIN_W * WIN_W)));
	map_d = sqrt((data->height * data->height) + (data->width * data->width));
	zoom = ((win_d * 30) / 100) / map_d;
	if (zoom > 0)
		return (zoom);
	else
		return (1);
}

void	ft_mlx(t_mlx *mlx)
{
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_W, WIN_H, "FDF");
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	mlx_hook(mlx->win_ptr, 17, 0, destroy, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse, mlx);
	mlx_hook(mlx->win_ptr, 2, 0, key, mlx);
}

void	init_vars(t_mlx	*mlx)
{
	mlx->applying_iso = 1;
	mlx->add_to_x = 0;
	mlx->add_to_y = 0;
	mlx->alpha = 0.52;
	mlx->beta = 0.52;
	mlx->gamma = 0.52;
	mlx->type = 0;
	mlx->add_c = 0;
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;
	t_mlx	mlx;

	fd = open(av[1], O_RDONLY);
	if (fd < 0 || ac > 2)
		exit(1);
	read_map(fd, &data);
	data.numbers = malloc (sizeof(int *) * (data.height + 1));
	data.colors = malloc (sizeof(int *) * (data.height + 1));
	get_altitude(&data);
	get_color(&data);
	init_vars(&mlx);
	mlx.zoom = get_zoom(&data);
	mlx.mlx_ptr = mlx_init();
	mlx.data = data;
	ft_mlx(&mlx);
	draw(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
