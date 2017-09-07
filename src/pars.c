#include "wolf.h"

int		pars(char *map)
{
	int	a;
	int	b;
	int	c;

	a = -1;
	b = 0;
	c = 0;
	while (!ft_isdigit(map[a]) && map[a])
		++a;
	if (ft_isdigit(map[a]) && ++c)
		while (ft_isdigit(map[a]))
			++a;
	a = -1;
	while (map[++a])
	{
		if (ft_isdigit(map[a]) && ++b)
			while (ft_isdigit(map[a]))
				++a;
		if (map[a] == '\n' && b == c)
			b = 0;
		else
			exit(1);
	}
	return (b);
}

char	**loadfile(char *argv)
{
	int		fd;
	char	*map;

	fd = open(argv, O_RDONLY);
	map = ft_readfile(fd);
	pars(map);
	//	if (a == -1 || (!(map = ft_parsing(map, fd)) &&
	//			!(ft_display(ft_convert(map)))))
	//	return (parsing(map));
	return (NULL);
}
