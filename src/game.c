/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 07:54:38 by eferrand          #+#    #+#             */
/*   Updated: 2017/09/27 20:15:57 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"


void	rotation(t_all *data, char sense)
{
	double			move;

	move = ((sense == '-') ? -0.0174533 : 0.0174533);
	data->map.view = (t_point){cosh(move), sinh(move)};
	play(data);
}

/*
**	int height = point de separation des couleurs
**
*/
void	fill_img(int x, int *height, int *color, char *img)
{
	int	a;
	int	b;

	a = -1;
	b = 0;
	while (++a < HEIGHT)
	{
		while (a < height[b])
			img[x + a * height * WIDTH] = color[b];
		if (a == height[b])
			++b;
	}
}

void	wall_size(t_all dta, double length)
{
	int	height;

	height = WALL * length / 2;
	if (HEIGHT < height)
		height = HEIGHT - 1;
}


void	raycasting(t_all dta)
{
	double	length;
	double	dxy[2];
	double	xy[2];

	length = fabs(dta.map.view.y - dta.map.player.x) <= fabs(dta.map.view.x - dta.map.player.x)
		? fabs(dta.map.view.x - dta.map.player.x) : fabs(dta.map.view.y - dta.map.player.x);
	dxy[0] = (dta.map.view.x - dta.map.player.x) / length;
	dxy[1] = (dta.map.view.y - dta.map.player.y) / length;
	xy[0] = dta.map.player.x;
	xy[1] = dta.map.player.y;
	while (0 < xy[0] && xy[0] < dta.map.limitx && 0 < xy[1] && xy[1] < dta.map.limity)
	{
		if (dta.map.map[(int)xy[0]] || dta.map.map[(int)xy[1]])
			break ;
		xy[0] += dxy[0];
		xy[1] += dxy[1];
	}
	wall_size(dta, sqrt(pow(dta.map.player.x - xy[0], 2) + pow(dta.map.player.y - xy[1], 2)));
}

void	play(t_all data)
{
	double	fov;

	data.tmp.pixelx = 0;
	while (data.tmp.pixelx < WIDTH)
	{
		fov = (data.tmp.pixelx + 1) * WIDTH / 160;
		data.map.view = (t_point){cosh(0.0174533 * fov), sinh(0.0174533 * fov)};
		raycasting(data);
	}
	mlx_put_image_to_window(data.mlx.init, data.mlx.win, data.mlx.img.addr, 0, 0);
	(void)data;
	return ;
}
