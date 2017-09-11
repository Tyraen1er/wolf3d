#include "wolf.h"

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
	float	**map;

	if (argc != 2)
	{
		ft_putstr("usage: ./wolf3d fichier_map\n");
		return (0);
	}
	if ((map = loadfile(argv[1])) == NULL)
		ft_exit(1);
	return (0);
}
