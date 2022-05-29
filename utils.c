/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:16:16 by mjlem             #+#    #+#             */
/*   Updated: 2022/05/28 16:16:20 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	double_free(void **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
}

int	conv_hex(char	*color)
{
	int	power;
	int	i;
	int	num;
	int	base;

	i = ft_strlen(color) - 1;
	power = 0;
	num = 0;
	base = 1;
	while (color[i] != 'x' && color[i] != 'X')
	{
		base = is_base(color[i]);
		if (base == -1)
			return (0);
		num += base * ft_power(16, power);
		power++;
		i--;
	}
	return (num);
}

int	ft_power(int nb, int power)
{
	int	n;

	n = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 1)
	{
		n = n * nb;
		power--;
	}
	return (n);
}

void	check_len(int j, t_data *var)
{
	if (j < var->width)
	{
		write(1, "Invalid map!\n", 13);
		exit(1);
	}
}
