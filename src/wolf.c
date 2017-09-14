#include "wolf.h"

int		ft_display(char **map)
{
	t_mlx	one;
	t_mlx	two;

	(void)two;
	(void)one;
	(void)map;
	if (!(one.init = mlx_init()) ||
			!(one.win = mlx_new_window(one.init, 1800, 1800, "mlx 42"))
			|| !(one.two = mlx_new_window(one.init, 1800, 1800, "mlx 42")))
		exit(3);
	mlx_loop(all[0]);
	return (1);
}

int		main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_putstr("usage: ./wolf3d fichier_map\n");
		return (0);
	}
	if ((map = loadfile(argv[1])).map == NULL)
		ft_exit(1);
	ft_display(ft_convert(map));
	return (0);
}
