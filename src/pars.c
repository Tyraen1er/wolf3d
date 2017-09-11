#include "wolf.h"

int		nb_nb_line(char *map)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while(map[a] != '\n' && map[a])
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
		while(map[a] != '\n' && map[a])
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

void	printf_map(t_map data, int nbl, int nb_elem)
{
	int i;
	int j;

	i = -1;
	while(++i < nbl)
	{
		j = -1;
		while(++j < nb_elem)
			printf("%d ", (int)data.map[i][j]);
		printf("\n");
	}

}

t_map load_data(int nbl, int nb_elem, char *map, int i)
{
	t_map data;
	int j;
	int k;
	
	k = 0;
	while (!ft_isdigit(map[k]) && map[k])
		k++;
	data.map = ft_memalloc(sizeof(float *) * nbl);
	while(++i < nbl)
	{
		j = -1;
		data.map[i] = ft_memalloc(sizeof(float) * nb_elem);
		while(++j < nb_elem)
		{	
			data.map[i][j] = (float)ft_atoi(map + k);
			while (ft_isdigit(map[k]))
				++k;
			while (!ft_isdigit(map[++k]) && map[k])
				if (map[k] == 'X' && (data.player.x = j + 1))
					if (j++)
						data.player.y = i;
		}
	}
	printf_map(data, nbl, nb_elem);	
	return(data);
}

float	**loadfile(char *argv)
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
	//	if (a == -1 || (!(map = ft_parsing(map, fd)) &&
	//			!(ft_display(ft_convert(map)))))
	//	return (parsing(map));
	printf("coucou\n");
	return (NULL);
}
