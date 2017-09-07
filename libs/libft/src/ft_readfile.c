#include "libft.h"

char	*ft_readfile(int fd)
{
	int		a;
	char	buf[151];
	char	*tmp;
	char	*map;

	map = ft_memalloc(1);
	while ((a = read(fd, buf, 150)) && a != -1)
	{
		buf[a] = 0;
		tmp = ft_strjoin(map, buf);
		ft_memdel((void *)&map);
		map = tmp;
	}
	return (map);
}
