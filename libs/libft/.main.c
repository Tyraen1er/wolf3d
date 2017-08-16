#include "libft.h"
#include "libft.h"
#include "mlx.h"

void	ft_mlx_put_bmp(t_bmp bmp, void **mlx)
{
	int		x;
	int		y;
	int		b;

	x = 0;
	b = 0;
	y = bmp.info.height;
	while (0 < y-- && (x = -1))
		while (++x < bmp.info.height)
		{
			((int*)mlx[3])[x + y * bmp.info.height] = (((int*)bmp.picture)[b] & 0xFFFFFF);
			++b;
			--bmp.picture;
		}
	mlx_put_image_to_window(mlx[0], mlx[1], mlx[2], 0, 0);
}

int		ft_display(t_bmp bmp)
{
	void	*mlx[4];
	int		bpp;
	int		s_l;
	int		endian;

	bpp = 0;
	s_l = 0;
	endian = 0;
	if (!(mlx[0] = mlx_init()) ||
			!(mlx[1] = mlx_new_window(mlx[0], bmp.info.width, bmp.info.height, "bnp test")) ||
			!(mlx[2] = mlx_new_image(mlx[0], bmp.info.width, bmp.info.height)) ||
			!(mlx[3] =
				(void*)mlx_get_data_addr(mlx[2], &(bpp), &(s_l), &(endian))))
		exit(3);
	ft_mlx_put_bmp(bmp, mlx);
	mlx_loop(mlx[0]);
	return (0);
}

int main(int argc, char **argv)
{
	t_bmp	bmp;
	int		fd;

	if (argc != 2)
	{
		printf("NOPE JE VEUX UN FICHIER ;)\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if ((fd = ft_load_bitmap(fd, &bmp)))
	{
		if (fd == 1)
		{
			printf("fichier compressé\n");
			bmp = ft_uncompress_bitmap(bmp);
		}
		else
		{
			printf("Ceci ne semble pas etre un fichier bmp\n");
			return (0);
		}
	}
	ft_display(bmp);
	return (0);
}
