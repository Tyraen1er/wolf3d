/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:52:17 by eferrand          #+#    #+#             */
/*   Updated: 2017/09/30 02:10:15 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		press_key(int keycode, t_all *dta)
{
	static int		deg = 0;

	if (keycode == 53)
		exit(3);
/*
**123 = gauche ||| 124 = droite ||| 125 = bas ||| 126 = haut
*/
	if (keycode == 123 || keycode == 124)
	{
		deg += (keycode == 123) ? 5 : -5;
		deg = (abs(deg) == 36000) ? 0 : deg;
		dta->map.view = (t_point){cos(0.0174533 * deg), sin(0.0174533 * deg)};
	}
	if (keycode == 125)
	{
		dta->map.view = (t_point){cos(0.0174533 * (deg + FOV / 2)), sin(0.0174533 * (deg + FOV / 2))};
		dta->map.player.x -= dta->map.view.x / 5;
		dta->map.player.y -= dta->map.view.y / 5;
	}
	if (keycode == 126)
	{
		dta->map.view = (t_point){cos(0.0174533 * (deg + FOV / 2)), sin(0.0174533 * (deg + FOV / 2))};
		if (!dta->map.map[(int)(dta->map.player.x + dta->map.view.x / 5)])
			dta->map.player.x += dta->map.view.x / 5;
		if (!dta->map.map[(int)(dta->map.player.y + dta->map.view.y / 5)])
			dta->map.player.y += dta->map.view.y / 5;
	}
	play(*dta);
	return (0);
}

static int  hook_close(t_mlx mlx)
{
	(void)mlx;
	exit(3);
	return (0);
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
		|| !(mlx.image.addr = mlx_new_image(mlx.init, WIDTH, HEIGHT)) ||
		!(mlx.image.img =
		mlx_get_data_addr(mlx.image.addr, &(bpp), &(s_l), &(endian))))
		exit(3);
	mlx_hook(mlx.win, 2, (1L << 0), press_key, data);
	mlx_hook(mlx.win, 17, 1L << 0, hook_close, NULL);
	data->mlx = mlx;
	data->map.view = (t_point){1, 0};
	play(*data);
	mlx_loop(mlx.init);
}

int main(int argc, char **argv)
{
	t_all data;

	data.map = (argc == 2) ? loadfile(argv[1]) : loadfile("creationsample");
//	printf("debut programme\n");
//	printf("%f\n", data.map.map[0][0]);
//	printf("debut programme2\n");
	display(&data);
	return (0);
}
