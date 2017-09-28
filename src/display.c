int		press_key(int keycode, t_all *data)
{
	if (keycode == 53)
		exit(3);
	play(data);
	return (0);
}

static int  hook_close(t_mlx mlx)
{
	(void)mlx;
	exit(3);
	return (0);
}

void	init(t_all *data, int vision, int move)
{
	static t_point view = {0, 1};
	static t_point player;

	data->map.view = ;
	data->map.player = player;
	play(*data);
}

void	display(t_all *data)
{
	t_mlx	mlx;
	int		bpp;
	int		s_l;
	int		endian;

	bpp = 0;
	s_l = 0;
	endian = 0;
	if (!(mlx.init = mlx_init()) ||
		!(mlx.win = mlx_new_window(mlx.init, WIDTH, HEIGHT, "wolf42"))
		|| !(mlx.image.img = mlx_new_image(mlx.init, WIDTH, HEIGHT)) ||
		!(mlx.img.addr =
		mlx_get_data_addr(mlx.img.img, &(bpp), &(s_l), &(endian))))
		exit(3);
	mlx_hook(mlx.win, 2, (1L << 0), press_key, data);
	mlx_hook(mlx.win, 17, 1L << 0, hook_close, NULL);
	data->mlx = mlx;
	init(data);
	mlx_loop(mlx.init);
}

int main()
{
	t_all data;

	data.map = (argc == 2) ? loadfile(argv[1]) : loadfile("creationsample");
	ft_display(&data);
	return (0);
}
