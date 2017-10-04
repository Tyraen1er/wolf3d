/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:52:17 by eferrand          #+#    #+#             */
/*   Updated: 2017/10/01 04:13:15 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	move_player(t_all *dta, double distance)
{
	if (!dta->map.map[(int)(dta->map.player.y +
				dta->tmp.view.y * distance)][(int)dta->map.player.x])
		dta->map.player.y += dta->tmp.view.y * distance;
	if (!dta->map.map[(int)dta->map.player.y][(int)(dta->map.player.x +
				dta->tmp.view.x * distance)])
		dta->map.player.x += dta->tmp.view.x * distance;
}

int		press_key(int keycode, t_all *dta)
{
	double	olddir;
	double	oldplane;
	double	rot;

	if (keycode == 53)
		exit(3);
	if (keycode == 123 || keycode == 124)
	{
		rot = (keycode == 123) ? M_PI / 30 : -M_PI / 30;
		olddir = dta->tmp.view.x;
		dta->tmp.view.x =
			dta->tmp.view.x * cos(rot) - dta->tmp.view.y * sin(rot);
		dta->tmp.view.y = olddir * sin(rot) + dta->tmp.view.y * cos(rot);
		oldplane = dta->map.plane.x;
		dta->map.plane.x =
			dta->map.plane.x * cos(rot) - dta->map.plane.y * sin(rot);
		dta->map.plane.y = oldplane * sin(rot) + dta->map.plane.y * cos(rot);
	}
	if (keycode == 125)
		move_player(dta, -WALK);
	if (keycode == 126)
		move_player(dta, WALK);
	play(*dta);
	return (0);
}

int		hook_close(t_mlx mlx)
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
	play(*data);
	mlx_loop(mlx.init);
}

int		main(int argc, char **argv)
{
	t_all data;

	data.map = (argc == 2) ? loadfile(argv[1]) : loadfile("creationsample");
	data.tmp.view = (t_point){-1, 0};
	data.map.plane = (t_point){0, 0.60};
	display(&data);
	return (0);
}
