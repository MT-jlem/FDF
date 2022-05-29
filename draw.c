/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:04:03 by mjlem             #+#    #+#             */
/*   Updated: 2022/05/27 18:04:12 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_var *vars, t_mlx *mlx, t_math *math, int color)
{
	get_valus(vars, math);
	while (1)
	{
		if (vars->x0 > 0 && vars->x0 < WIN_W
			&& vars->y0 > 0 && vars->y0 < WIN_H)
			my_mlx_pixel_put(mlx, vars->x0, vars->y0, color + mlx->add_c);
		if (vars->x0 == vars->x1 && vars->y0 == vars->y1)
			break ;
		math->e2 = 2 * math->err;
		if (math->e2 >= math->dy)
		{
			if (vars->x0 == vars->x1)
				break ;
			math->err += math->dy;
			vars->x0 += math->sx;
		}
		if (math->e2 <= math->dx)
		{
			if (vars->y0 == vars->y1)
				break ;
			math->err += math->dx;
			vars->y0 += math->sy;
		}
	}
}

void	draw_line(t_var *var, t_mlx *mlx, int color)
{
	t_math	math;

	zoom(var, mlx);
	rotate(var, mlx);
	if (mlx->applying_iso)
		iso(var);
	centering(var, mlx);
	bresenham(var, mlx, &math, color);
}

void	draw_lines(t_mlx *mlx, t_var *var, int x, int y)
{
	if (x < mlx->data.width - 1)
	{
		var->x0 = x;
		var->y0 = y;
		var->x1 = x + 1;
		var->y1 = y;
		var->z0 = mlx->data.numbers[var->y0][var->x0];
		var->z1 = mlx->data.numbers[var->y1][var->x1];
		draw_line(var, mlx, mlx->data.colors[y][x]);
	}
	if (y < mlx->data.height - 1)
	{
		var->x0 = x;
		var->y0 = y;
		var->x1 = x;
		var->y1 = y + 1;
		var->z0 = mlx->data.numbers[var->y0][var->x0];
		var->z1 = mlx->data.numbers[var->y1][var->x1];
		draw_line(var, mlx, mlx->data.colors[y][x]);
	}
}

void	draw(t_mlx *mlx)
{
	int		y;
	int		x;
	t_var	var;

	y = 0;
	centering_map(&var, mlx);
	while (y < mlx->data.height)
	{
		x = 0;
		while (x < mlx->data.width)
		{
			draw_lines(mlx, &var, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	print_on_map(mlx);
}
