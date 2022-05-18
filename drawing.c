/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:58:00 by mjlem             #+#    #+#             */
/*   Updated: 2022/04/14 15:58:02 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_math init(t_fdf *var, t_math val)
{
	if (var->x0 < var->x1)
		val.sx = 1;
	else
		val.sx = -1;
	if (var->y0 < var->y1)
		val.sy = 1;
	else
		val.sy = -1;
	return (val);
}

void	bresenham(t_fdf *var, int color, t_math val, int dx, int dy)
{
	int e2;
	int err;

	err = dx + dy;
	val = init(var, val);
	while (var->x0 != var->x1 && var->y0 != var->y1)
	{
		mlx_pixel_put(var->mlx, var->mlx_win, var->x0 + var->xo, var->y0 + var->yo, color);
		e2 = 2 * err;
		if (e2 >= dy)
		{
			if (var->x0 == var->x1)
				break ;
			err += dy;
			var->x0 += val.sx;
		}
		if (e2 <= dx)
		{
			if (var->y0 == var->y1)
				break ;
			err += dx;
			var->y0 += val.sy;
		}
	}
}

void	iso(t_fdf *var)
{
	int tmp;
	int	tmp1;
	int	tmp3;
	int	tmp2;

	tmp = (var->x0 - var->y0) * cos(0.523599);
	tmp1 = -var->z0 + (var->x0 + var->y0) * sin(0.523599);
	tmp2 = (var->x1 - var->y1) * cos(0.523599);
	tmp3 =  -var->z1 + (var->x1 + var->y1) * sin(0.523599);
	var->x0 = tmp;
	var->y0 = tmp1;
	var->x1 = tmp2;
	var->y1 = tmp3;
}

void	draw_line(t_fdf *var, int size, int j, int i)
{
	t_math val;
	int dx;
	int dy;

	val.sx = 0;
	val.sy = 0;
	var->x0 *= size;
	var->y0 *= size;
	var->x1 *= size;
	var->y1 *= size;
	// var->z0 *= size;
	// var->z1 *= size;
	iso(var);
	dx = abs(var->x1 - var->x0);
	dy = -abs(var->y1 - var->y0);
	bresenham(var, var->color[i][j], val, dx, dy);
}

void	draw_2_lines(t_fdf *var, int x, int y, int size)
{
	if(x < var->w -1)
	{
		var->x0 = x;
		var->y0 = y;
		var->x1 = (x + 1);
		var->y1 = y;
		var->z0 = var->map[y][x];
		var->z1 = var->map[y][x+1];
		draw_line(var,size,x ,y);
	}
	if (y < var->h - 1)
	{
		var->x0 = x;
		var->y0 = y;
		var->x1 = x;
		var->y1 = (y + 1);
		var->z0 = var->map[y][x];
		var->z1 = var->map[y+1][x];
		draw_line(var,size,x ,y);
	}
}

void draw(t_fdf *var, int size)
{
	int i;
	int	j;
	i = 0;
	while(i < var->h)
	{
		j = 0;
		while (j < var->w)
		{
			draw_2_lines(var, j, i, size);
			j++;
		}
		i++;
	}
}