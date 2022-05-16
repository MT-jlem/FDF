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

void	bresenham(t_fdf var, int x1, int y1, int x2, int y2, int color)
{
	int dx;
	int dy;
	int p;
	int x;
	int y;

	dx = x2 - x1;
	dy = y2 - y1;
	x = x1;
	y = y1;
	if ((float)dy / (float)dx < 1 && (float)dy / (float)dx > 0)
	{
		p = 2 * dy - dx;
		while(x <= x2 && y <= y2)
		{
			mlx_pixel_put(var.mlx, var.mlx_win, x, y, color);
			if(p < 0)
				p = p + 2 * dy;
			else
			{
				p = p + 2 * dy - 2 * dx;
				y++;
			}
			x++;
		}
	}
	else
	{
		p = 2 * dx - dy;
		while (x <= x2 && y <= y2)
		{	
			mlx_pixel_put(var.mlx, var.mlx_win, x, y, color);
			if(p < 0)
				p = p + 2 * dx;
			else
			{
				p = p + 2 * dx - 2 * dy;
				x++;
			}
			y++;
		}
		
	}
}

// t_fdf dda(t_fdf var,int x1, int x2, int y1, int y2)
// {
// 	int dx = x2 - x1;
// 	int dy = y2 - y1;
// 	int steps;
// 	if (abs(dx) > abs(dy))
// 		steps = abs(dy);
// 	else
// 		steps = abs(dx);
// 	double xi = (double)dx/(double)steps;
// 	double yi = (double)dy/(double)steps;
// 	int i = 0;
// 	while (i < steps)
// 	{
// 		mlx_pixel_put(var.mlx, var.mlx_win,x1,y1,300);
// 		x1 = (int)round(xi+x1);
// 		y1 = (int)round(y1+yi);
// 		i++;
// 	}
// 	return (var);
// }