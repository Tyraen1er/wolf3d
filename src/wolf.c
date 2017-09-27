/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 08:03:40 by eferrand          #+#    #+#             */
/*   Updated: 2017/09/27 18:05:34 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int  hook_close(t_mlx mlx)
{
	(void)mlx;
	exit(3);
	return (0);
}

// faire fonctionnement clavier
// donc creation et supression de mur minimum
// et deplacement en partie obligatoire

int		press_key(int keycode, t_all *data)
{
	if (keycode == 53)
		exit(3);
	play(data);
	return (0);
}

// faire fonctionnement souris : bonus

int		mouse_event(int x, int y, t_all *data)
{
	static int	pos[2] = {0, 0};

	if (x < 0 || y < 0 || WIDTH < x || HEIGHT < y)
		return (0);
	(void)pos;
	play(data);
	return (0);
}

int		ft_display(t_map map)
{
	t_mlx	mlx;
	t_all	data;
	int		bpp;
	int		s_l;
	int		endian;

	bpp = 0;
	s_l = 0;
	endian = 0;
	if (!(mlx.init = mlx_init()) ||
			!(mlx.win = mlx_new_window(mlx.init, WIDTH, HEIGHT, "wolf42"))
			|| !(mlx.img[0].img = mlx_new_image(mlx.init, WIDTH, HEIGHT)) ||
			!(mlx.img[0].addr =
				mlx_get_data_addr(mlx.img[0].img, &(bpp), &(s_l), &(endian)))
			|| !(mlx.img[1].img = mlx_new_image(mlx.init, WIDTH_M, HEIGHT_M)) ||
			!(mlx.img[1].addr =
				mlx_get_data_addr(mlx.img[1].img, &(bpp), &(s_l), &(endian))))
		exit(3);
	mlx_hook(mlx.win, 2, (1L << 0), &press_key, NULL);
	mlx_hook(mlx.win, 6, (1L << 6), &mouse_event, NULL);
	mlx_hook(mlx.win, 17, 1L << 0, hook_close, NULL);
	data = (t_all){mlx, map};
	play(&data);
	mlx_loop(mlx.init);
	return (1);
}

int		main(int argc, char **argv)
{
	t_map	map;

	map = (argc == 2) ? loadfile(argv[1]) : loadfile("creationsample");
	ft_display(map);
	return (0);
}
