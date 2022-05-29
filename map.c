/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:05:30 by mjlem             #+#    #+#             */
/*   Updated: 2022/05/27 18:05:32 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_map(int fd, t_data *data)
{
	char	*buf;
	char	*line;
	int		i;

	i = 0;
	buf = NULL;
	line = get_next_line(fd);
	if (!line || !line[0])
		exit (1);
	while (line && line[0])
	{
		data->height++;
		buf = ft_strjoin(buf, line);
		free(line);
		line = get_next_line(fd);
	}
	while (buf[i])
	{
		if (buf[i] == '\n' && buf[i + 1] == '\n' && (!buf[0] || buf[0] == '\n'))
			exit(1);
		i++;
	}
	data->map = ft_split(buf, '\n');
	free(buf);
}

void	get_altitude(t_data *var)
{
	int		i;
	char	**buf;
	int		j;
	int		l;

	i = 0;
	while (var->map[i])
	{
		buf = ft_split(var->map[i], ' ');
		l = 0;
		while (buf[l])
			l++;
		if (i == 0)
			var->width = l;
		var->numbers[i] = malloc(sizeof(int) * l);
		j = 0;
		while (buf[j])
		{
			var->numbers[i][j] = ft_atoi(buf[j]);
			j++;
		}
		check_len(j, var);
		i++;
		double_free((void **)buf);
	}
}

int	is_base(char hex)
{
	if (hex >= 48 && hex <= 57)
		return (hex - 48);
	else if (hex >= 65 && hex <= 70)
		return (hex - 55);
	else if (hex >= 97 && hex <= 102)
		return (hex - 87);
	else
		return (-1);
}

char	**conv_color(t_data *var, char **buf, int i)
{
	int	l;
	int	j;

	j = 0;
	while (buf[j])
	{
		l = 0;
		if (ft_strchr(buf[j], ','))
		{
			while (buf[j][l] != ',')
				l++;
			if (buf[j][l] == '\0')
				var->colors[i][j] = 0;
			else
				var->colors[i][j] = conv_hex(&buf[j][l]);
		}
		else
			var->colors[i][j] = 16777215;
		j++;
	}
	return (buf);
}

void	get_color(t_data *var)
{
	int		i;
	char	**buf;

	i = 0;
	while (var->map[i])
	{
		buf = ft_split(var->map[i], ' ');
		var->colors[i] = malloc (sizeof(int) * var->width);
		buf = conv_color(var, buf, i);
		i++;
		double_free((void **) buf);
	}
}
