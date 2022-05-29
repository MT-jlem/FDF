/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:05:20 by mjlem             #+#    #+#             */
/*   Updated: 2022/05/27 18:05:22 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translation(int keyp, t_mlx *mlx)
{
	if (keyp == UP)
		mlx->add_to_y -= 10;
	else if (keyp == DOWN)
		mlx->add_to_y += 10;
	else if (keyp == LEFT)
		mlx->add_to_x -= 10;
	else
		mlx->add_to_x += 10;
}

int	mouse(int keyp, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	if (keyp == SCROLL_DOWN || keyp == SCROLL_UP)
	{	
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
		if (keyp == SCROLL_UP && mlx->zoom >= 0)
			mlx->zoom += 1;
		else if (keyp == SCROLL_DOWN && mlx->zoom > 0)
			mlx->zoom -= 1;
		mlx->img = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
		draw(mlx);
	}
	return (0);
}

void	rotation(int keyp, t_mlx *mlx)
{
	if (keyp == D || keyp == A)
	{
		mlx->type = 1;
		if (keyp == D)
			mlx->alpha += 0.06;
		else
			mlx->alpha -= 0.06;
	}
	else if (keyp == S || keyp == W)
	{
		mlx->type = 2;
		if (keyp == W)
			mlx->beta -= 0.06;
		else
			mlx->beta += 0.06;
	}
	else if (keyp == E || keyp == Q)
	{
		mlx->type = 3;
		if (keyp == Q)
			mlx->gamma += 0.06;
		else
			mlx->gamma -= 0.06;
	}
}

int	key(int keyp, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	if (keyp == UP || keyp == DOWN || keyp == LEFT || keyp == RIGHT)
		translation(keyp, mlx);
	else if (keyp == ESC)
		exit(0);
	else if (keyp == P)
	{
		if (mlx->applying_iso)
			mlx->applying_iso = 0;
		else
			mlx->applying_iso = 1;
	}
	else if (keyp == D || keyp == S || keyp == W || keyp == A || keyp == E
		|| keyp == Q)
		rotation(keyp, mlx);
	else if (keyp == PLUS)
		mlx->add_c += 100000;
	else if (keyp == MINUS)
		mlx->add_c -= 100000;
	else if (keyp == R)
		init_vars(mlx);
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	draw(mlx);
	return (0);
}

int	destroy(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
	return (0);
}
