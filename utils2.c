/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:15:35 by mjlem             #+#    #+#             */
/*   Updated: 2022/05/28 18:15:37 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	centering_map(t_var *var, t_mlx *mlx)
{
	var->pad_x = (WIN_W - (mlx->data.width * mlx->zoom)) / 2;
	var->pad_y = (WIN_H - (mlx->data.height * mlx->zoom)) / 2;
}

void	iso(t_var *var)
{
	int	tmp;
	int	tmp1;
	int	tmp3;
	int	tmp2;

	tmp = (var->x0 - var->y0) * cos(0.52);
	tmp1 = -var->z0 + (var->x0 + var->y0) * sin(0.52);
	tmp2 = (var->x1 - var->y1) * cos(0.52);
	tmp3 = -var->z1 + (var->x1 + var->y1) * sin(0.52);
	var->x0 = tmp;
	var->y0 = tmp1;
	var->x1 = tmp2;
	var->y1 = tmp3;
}

void	get_valus(t_var *vars, t_math *math)
{
	math->dx = abs(vars->x1 - vars->x0);
	if (vars->x0 < vars->x1)
		math->sx = 1;
	else
		math->sx = -1;
	math->dy = -abs(vars->y1 - vars->y0);
	if (vars->y0 < vars->y1)
		math->sy = 1;
	else
		math->sy = -1;
	math->err = math->dx + math->dy;
}

void	zoom(t_var *var, t_mlx *mlx)
{
	var->x0 *= mlx->zoom;
	var->y0 *= mlx->zoom;
	var->x1 *= mlx->zoom;
	var->y1 *= mlx->zoom;
	var->z0 *= mlx->zoom;
	var->z1 *= mlx->zoom;
}

void	centering(t_var *var, t_mlx *mlx)
{
	var->x0 += var->pad_x + mlx->add_to_x;
	var->x1 += var->pad_x + mlx->add_to_x;
	var->y0 += var->pad_y + mlx->add_to_y;
	var->y1 += var->pad_y + mlx->add_to_y;
	(void)mlx;
}
