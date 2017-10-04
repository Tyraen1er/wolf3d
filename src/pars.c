/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 07:54:46 by eferrand          #+#    #+#             */
/*   Updated: 2017/10/01 04:36:09 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		nb_nb_line(char *map)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (map[a] != '\n' && map[a])
	{
		while (!ft_isdigit(map[a]) && map[a] != 'X' && map[a] && map[a] != '\n')
			++a;
		if ((ft_isdigit(map[a]) || (map[a] == 'X' && ++a)) && ++b)
			while (ft_isdigit(map[a]))
				++a;
	}
	return (b);
}

int		nb_lines(char *map)
{
	int	a;
	int	limity;

	a = -1;
	limity = 0;
	while (map[++a])
		if (map[a] == '\n')
			++limity;
	return (limity);
}

int		checkmap(char *map)
{
	int	a;
	int	b;
	int	c;
	int	x;

	x = 0;
	c = nb_nb_line(map);
	a = -1;
	while (map[++a] && !(b = 0))
	{
		while (map[a] != '\n' && map[a])
		{
			while (!ft_isdigit(map[a]) && map[a] != 'X' && map[a] &&
					map[a] != '\n')
				++a;
			if ((ft_isdigit(map[a]) || (map[a] == 'X' && ++x && ++a)) && ++b)
				while (ft_isdigit(map[a]))
					++a;
		}
		if (b != c)
			ft_exit(1);
	}
	if (x != 1)
		ft_exit(1);
	return (b);
}

void	load_data(t_map *data, char *map)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	data->map = ft_memalloc(sizeof(double *) * data->limity);
	while (++i < data->limity)
	{
		j = -1;
		data->map[i] = ft_memalloc(sizeof(double) * data->limitx);
		while (map[k] && !ft_isdigit(map[k]) && map[k] != 'X')
			k++;
		while (++j < data->limitx)
		{
			if (map[k] == 'X' && (data->player.x = j + 0.5))
				data->player.y = i + 0.5;
			data->map[i][j] = (double)ft_atoi(map + k);
			while (ft_isdigit(map[k]))
				++k;
			while (map[++k] && !ft_isdigit(map[k]) &&
					map[k] != '\n' && map[k] != 'X')
				;
		}
	}
}

t_map	loadfile(char *argv)
{
	int		fd;
	char	*map;
	t_map	data;

	fd = open(argv, O_RDONLY);
	map = ft_readfile(fd);
	data.limitx = checkmap(map);
	data.limity = nb_lines(map);
	if (!data.limitx && !data.limity)
		ft_exit(1);
	load_data(&data, map);
	border(data);
	return (data);
}
