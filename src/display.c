/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:52:17 by eferrand          #+#    #+#             */
/*   Updated: 2017/09/29 14:22:27 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		press_key(int keycode, t_all *data)
{
	double			view;
	static int		deg = 0;

	if (keycode == 53)
		exit(3);
	if (keycode == 123 || keycode == 124)
	{
		deg += (keycode == 123) ? 1 : -1;
		deg = (abs(deg) == 36000) ? 0 : deg;
		view = ((keycode == 124) ? -0.0174533 : 0.0174533) * deg;
		data->map.view = (t_point){cosh(view), sinh(view)};
	}
	if (keycode == 125)
	{
		data->map.player.x -= data->map.view.x;
		data->map.player.y -= data->map.view.y;
	}
	if (keycode == 126)
	{
		data->map.player.x += data->map.view.x;
		data->map.player.y += data->map.view.y;
	}
	play(*data);
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
		|| !(mlx.image.img = mlx_new_image(mlx.init, WIDTH, HEIGHT)) ||
		!(mlx.image.addr =
		mlx_get_data_addr(mlx.image.img, &(bpp), &(s_l), &(endian))))
		exit(3);
	mlx_hook(mlx.win, 2, (1L << 0), press_key, data);
	mlx_hook(mlx.win, 17, 1L << 0, hook_close, NULL);
	data->mlx = mlx;
	data->map.view = (t_point){0, 1};
	play(*data);
	mlx_loop(mlx.init);
}

int main(int argc, char **argv)
{
	t_all data;

	data.map = (argc == 2) ? loadfile(argv[1]) : loadfile("creationsample");
	display(&data);
	return (0);
}
