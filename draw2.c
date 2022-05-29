/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:05:00 by mjlem             #+#    #+#             */
/*   Updated: 2022/05/28 18:05:02 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_var *var, t_mlx *mlx)
{
	int	temp;
	int	temp2;

	if (mlx->type == 3)
	{
		temp = var->x0 * cos(mlx->gamma) - var->y0 * sin(mlx->gamma);
		temp2 = var->x1 * cos(mlx->gamma) - var->y1 * sin(mlx->gamma);
		var->y0 = var->x0 * sin(mlx->gamma) + var->y0 * cos(mlx->gamma);
		var->y1 = var->x1 * sin(mlx->gamma) + var->y1 * cos(mlx->gamma);
		var->x0 = temp;
		var->x1 = temp2;
	}	
}

void	rotate(t_var *var, t_mlx *mlx)
{
	int	temp;
	int	temp2;

	if (mlx->type == 1)
	{
		temp = var->y0 * cos(mlx->alpha) + var->z0 * sin(mlx->alpha);
		temp2 = var->y1 * cos(mlx->alpha) + var->z1 * sin(mlx->alpha);
		var->z0 = -var->y0 * sin(mlx->alpha) + var->z0 * cos(mlx->alpha);
		var->z1 = -var->y1 * sin(mlx->alpha) + var->z1 * cos(mlx->alpha);
		var->y0 = temp;
		var->y1 = temp2;
	}
	else if (mlx->type == 2)
	{
		temp = var->x0 * cos(mlx->beta) + var->z0 * sin(mlx->beta);
		temp2 = var->x1 * cos(mlx->beta) + var->z1 * sin(mlx->beta);
		var->z0 = -var->x0 * sin(mlx->beta) + var->z0 * cos(mlx->beta);
		var->z1 = -var->x1 * sin(mlx->beta) + var->z1 * cos(mlx->beta);
		var->x0 = temp;
		var->x1 = temp2;
	}
	else if (mlx->type == 3)
		rotate_z(var, mlx);
}

void	print_on_map(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 40, 800, 0xffffff,
		"ESC to close the window			   ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 40, 820, 0xffffff,
		"UP ARROW to move the map upwards	   ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 40, 840, 0xffffff,
		"DOWN ARROW to move the map downwardS  ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 40, 860, 0xffffff,
		"RIGHT ARROW to move the map rightwards");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 40, 880, 0xffffff,
		"LEFT ARROW to move the map leftwards  ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 40, 900, 0xffffff,
		"D/A to rotate the map in the X-axis   ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 40, 920, 0xffffff,
		"W/S to rotate the map in the Y-axis   ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 40, 940, 0xffffff,
		"Q/E to rotate the map in the Z-axis   ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 40, 960, 0xffffff,
		"SCROLL UP to zoom in				   ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 40, 980, 0xffffff,
		"SCROLL DOWN to zoom out			   ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 40, 1000, 0xffffff,
		"+/- to change the color		       ");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 40, 1020, 0xffffff,
		"P to change the projection		       ");
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img_addr + (y * mlx->line_length + x
			* (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
