void	ft_mlx_color_quad(t_quad size, int color, t_img img, t_point br_win)
{
	int	a;
	int	b;

	b = size.tl.y - 1;
	while (++b < size.br.y && b <= br_win.y)
	{
		a = size.tl.x - 1;
		while (++a <= size.br.x)
		{
			if (br_win.x < a)
				break ;
			((int)img.img)[a - 1 + b * sizex] = color;
		}
	}
}
