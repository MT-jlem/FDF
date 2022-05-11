/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:19:39 by mjlem             #+#    #+#             */
/*   Updated: 2022/04/12 15:19:42 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	map_check(t_fdf var)
{
	int	first;
	int	i;

	i = 1;
	first = ft_strlen(var.buf[0]);
	while(var.buf[i])
		if(first > ft_strlen(var.buf[i++]))
			exit (1);

}

t_fdf	get_altitude(t_fdf var)
{
	int		i;
	char	**buf;
	int		j;
	int		l;

	i = 0;
	while (var.buf[i])
	{ 
		buf = ft_split(var.buf[i], ' ');
		l = 0;
		while(buf[l])
			l++;
		var.map[i] = malloc(sizeof(int) * l);
		j = 0;
		while (buf[j])
		{
			var.map[i][j] = ft_atoi(buf[j]);
			j++;
		}	
		i++;
	}
	var.w = l;
	return (var);
}

int	is_base(char	hex)
{
	if(hex >= 48 && hex <= 57)
		return (hex - 48);
	else if (hex >= 65 && hex <= 70)
		return (hex - 55);
	else if (hex >= 97 && hex <= 102)
		return (hex - 87);
	else
		return (-1);
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
	while (color[i] != 'x'&& color[i] != 'X')
	{
		base = is_base(color[i]);
		if (base == -1)
			return (0);
		num += base * ft_power(16, power);
		power++;
		i--;
	}
	return(num);
}

t_fdf	get_color(t_fdf var)
{
	int	i;
	char	**buf;
	int	j;
	int	l;

	i = 0;
	while (var.buf[i])
	{
		buf = ft_split(var.buf[i], ' ');
		var.color[i] = malloc (sizeof(int) * var.w);
		j = 0;
		l = 0;
		while (buf[j])
		{
			if(ft_strchr(buf[j], ','))
			{
				while(buf[j][l] != ',')
					l++;
				if (buf[j][l] == '\0')
					var.color[i][j] = 0;
				else
					var.color[i][j] = conv_hex(&buf[j][l]);
			}
			else
				var.color[i][j] = 16777215;
			j++;
		}
		i++;
	}
	return (var);
}

t_fdf	get_map(t_fdf var, char *path)
{
	int		fd;
	int		i;
	char	*line;
	char	*buf = NULL;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	while (line)
	{
		var.h++;
		buf = ft_strjoin(buf, line);
		// free(line);
		line = get_next_line(fd);
	}
	if (!buf[0] || buf[0] == '\n')
		exit(1);
	while (buf[i])
	{
		if(buf[i] == '\n'  && buf[i + 1] == '\n')
			exit(1);
		i++;
	}
	var.buf = ft_split(buf, '\n');
	return (var);
}

int	main(int ac, char **av)
{
	t_fdf	var;
	// void	*img;
	if (ac != 2)
		exit(1);
	var.mlx_win = NULL;
	var.mlx = NULL;
	var = get_map(var, av[1]);
	map_check(var);
	var.map = (int **) malloc (sizeof(int *) * (var.h + 1));
	var.color = (int **) malloc (sizeof(int *) * (var.h + 1));
	var = get_altitude(var);
	var = get_color(var);
	var.mlx = mlx_init();
	var.mlx_win = mlx_new_window(var.mlx, 1920, 1080, "fdf");
	// img = mlx_new_image(var.mlx,1920, 1080);
	// int i = 0;
	// int	j = 0;

	mlx_loop(var.mlx);
	
}
	// for(int i = 0; i < var.h;i++)
	// {
	// 	for(int j = 0; j < var.w ;j++)
	// 		printf("%2d ",var.map[i][j]);
	// 	printf("\n");
	// }
	// for(int i = 0; i < var.h;i++)
	// {
	// 	for(int j = 0; j < var.w ;j++)
	// 		printf("%2d ",var.color[i][j]);
	// 	printf("\n");
	// }