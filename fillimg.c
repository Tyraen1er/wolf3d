#include "wolf.h"

#define	WIDTH 100
#define	HEIGHT 100

void	fill_img(int x, int *height, int *color, char *img)
{
	int		a;

	a = 0;
	while (a < height[0] - 1)
	{
		img[(a + 1) * WIDTH + x] = color[0];
		++a;
	}
	while (a < height[1] - 1)
	{
		img[(a + 1) * WIDTH + x] = color[1];
		++a;
	}
	while (a < HEIGHT)
	{
		img[(a + 1) * WIDTH + x] = color[2];
		++a;
	}
}

void	display()
{
	t_mlx	mlx;
	int		bpp;
	int		s_l;
	int		endian;

	bpp = 0;
	s_l = 0;
	endian = 0;
	if (!(mlx.init = mlx_init()) ||
		!(mlx.win = mlx_new_window(mlx.init, WIDTH, HEIGHT, "wolf42")) ||
		!(mlx.image.img = mlx_new_image(mlx.init, WIDTH, HEIGHT)) ||
		!(mlx.image.addr = mlx_get_data_addr(mlx.image.img, &(bpp), &(s_l), &(endian))))
			exit(3);
	fill_img(50, (int[2]){20, 70}, (int[3]){0xFFFFFF, 0xFF0000, 0xFF}, mlx.image.img);
	mlx_loop(mlx.init);
}

int main()
{
	display();
	return (0);
}
