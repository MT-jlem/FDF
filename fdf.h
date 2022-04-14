/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:20:10 by mjlem             #+#    #+#             */
/*   Updated: 2022/04/12 15:20:54 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>
#include "get_next_line.h"

typedef struct s_fdf
{
	void	*mlx;
	char	**buf;
	int		h;
	int		w;
	int		**map;
	int		**color;
}t_fdf;

char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_atoi(char *str);

#endif
