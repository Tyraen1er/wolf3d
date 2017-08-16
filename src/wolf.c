#include "wolf.h"

char	*ft_parsing(char *file)
{
	int		x;
	
	while (get_next_line)
/*	int		y;
	int		length;
	
	length = 1;
	x = 0;
	y = 0;
	while (file[x] != '\0')
	{
		if (file[x] == '\n')
			++y;
		++x;
	}
	while (file[length] != '\n' && file[length] != '\0')
		++length;
	y = 0;
	while (file[x] != '\0' && !(x = 0))
	{
		
	}
	printf("end\n");
*/
}
/*
int		my_key_fct(int keycode, void *data)
{
	printf("keycode = %d\n", keycode);
	return (0);
}

int		ft_display(char **map)
{
	t_mlx	one;
	t_mlx	two;

	if (!(one.init = mlx_init()) ||
			!(one.win = mlx_new_window(one.init, 1800, 1800, "mlx 42"))
			|| !(one.two = mlx_new_window(one.init, 1800, 1800, "mlx 42")))
		exit(3);
	mlx_key_hook(all[1], my_key_fct, all);
	mlx_loop(all[0]);
	return (1);
}
*/
int		main(int argc, char **argv)
{
	int		fd;
	int		a;
	char	buf[151];
	char	*map;
	char	*tmp;

	map = ft_memalloc(1);
	if (argc != 2)
	{
		ft_putstr("usage: ./wolf3d fichier_map\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	while ((a = read(fd, buf, 150)) && a != -1)
	{
		buf[a] = 0;
		tmp = ft_strjoin(map, buf);
		ft_memdel((void *)&map);
		map = tmp;
	}
//	if (a == -1 || (!(map = ft_parsing(map)) &&
//			!(ft_display(ft_convert(map)))))
	if (a == -1 || (!(map = ft_parsing(map))))
		ft_putstr("error read or display\n");
	return (0);
}
