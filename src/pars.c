/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 07:54:46 by eferrand          #+#    #+#             */
/*   Updated: 2017/09/22 07:58:06 by eferrand         ###   ########.fr       */
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
		while (!ft_isdigit(map[a]) && map[a] != 'X' && map[a])
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
	int	nbl;

	a = -1;
	nbl = 0;
	while (map[++a])
		if (map[a] == '\n')
			++nbl;
	return (nbl);
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
			while (!ft_isdigit(map[a]) && map[a] != 'X' && map[a])
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

t_map	load_data(int nbl, int nb_elem, char *map, int i)
{
	t_map	data;
	int		j;
	int		k;

	k = 0;
	data.map = ft_memalloc(sizeof(float *) * nbl);
	while (++i < nbl)
	{
		j = -1;
		data.map[i] = ft_memalloc(sizeof(float) * nb_elem);
		while (map[k] && !ft_isdigit(map[k]) && map[k] != 'X')
			k++;
		while (++j < nb_elem)
		{
			if (map[k] == 'X' && (data.player.x = j + 0.5))
				data.player.y = i + 0.5;
			data.map[i][j] = (float)ft_atoi(map + k);
			while (ft_isdigit(map[k]))
				++k;
			while (map[++k] && !ft_isdigit(map[k]) &&
					map[k] != '\n' && map[k] != 'X')
				;
		}
	}
	return (data);
}

t_map	loadfile(char *argv)
{
	int		fd;
	int		nb_elem;
	int		nbl;
	char	*map;
	t_map	data;

	fd = open(argv, O_RDONLY);
	map = ft_readfile(fd);
	nb_elem = checkmap(map);
	nbl = nb_lines(map);
	data = load_data(nbl, nb_elem, map, -1);
	return (data);
}
