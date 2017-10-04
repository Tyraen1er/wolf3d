/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 07:54:38 by eferrand          #+#    #+#             */
/*   Updated: 2017/10/01 04:16:10 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	fill_img(int x, int *height, int *color, int *img)
{
	int	a;

	a = 0;
	while (a < height[0] - 1)
	{
		img[a * WIDTH + x] = color[0];
		++a;
	}
	while (a < height[1] - 1)
	{
		img[a * WIDTH + x] = color[1];
		++a;
	}
	while (a < HEIGHT - 1)
	{
		img[a * WIDTH + x] = color[2];
		++a;
	}
}

void	wall_size(t_all dta, double distwall)
{
	int	dim;
	int	height[2];
	int	color[3];

	dim = (HEIGHT / distwall);
	color[0] = 0X808080;
	if (!dta.tmp.side)
		color[1] = (dta.tmp.stepx < 0) ? 0XFF0000 : 0xFF00;
	else
		color[1] = (dta.tmp.stepy < 0) ? 0xFF : 0xFFFF;
	color[2] = 0X663300;
	height[0] = -dim / 2 + HEIGHT / 2;
	if (height[0] < 0)
		height[0] = 0;
	height[1] = dim / 2 + HEIGHT / 2;
	if (HEIGHT <= height[1])
		height[1] = HEIGHT - 1;
	fill_img(dta.tmp.pixelx, height, color, (int*)dta.mlx.image.img);
}

void	raycasting(t_all dt)
{
	while (1)
	{
		if (dt.tmp.s.x < dt.tmp.s.y && !(dt.tmp.side = 0))
		{
			dt.tmp.s.x += dt.tmp.delta.x;
			dt.tmp.mapx += dt.tmp.stepx;
		}
		else if ((dt.tmp.side = 1))
		{
			dt.tmp.s.y += dt.tmp.delta.y;
			dt.tmp.mapy += dt.tmp.stepy;
		}
		if (dt.map.map[dt.tmp.mapy][dt.tmp.mapx])
		{
			if (dt.tmp.side == 0)
				wall_size(dt, (dt.tmp.mapx - dt.map.player.x +
							(1 - dt.tmp.stepx) / 2) / dt.tmp.raydir.x);
			else
				wall_size(dt, (dt.tmp.mapy - dt.map.player.y +
							(1 - dt.tmp.stepy) / 2) / dt.tmp.raydir.y);
			break ;
		}
	}
}

void	init(t_all dt)
{
	dt.tmp.mapx = (int)dt.map.player.x;
	dt.tmp.mapy = (int)dt.map.player.y;
	dt.tmp.delta.x = sqrt(1 + (dt.tmp.raydir.y * dt.tmp.raydir.y) /
			(dt.tmp.raydir.x * dt.tmp.raydir.x));
	dt.tmp.delta.y = sqrt(1 + (dt.tmp.raydir.x * dt.tmp.raydir.x) /
			(dt.tmp.raydir.y * dt.tmp.raydir.y));
	dt.tmp.stepx = (dt.tmp.raydir.x < 0) ? -1 : 1;
	dt.tmp.s.x = (dt.tmp.raydir.x < 0) ?
		(dt.map.player.x - (double)dt.tmp.mapx) * dt.tmp.delta.x :
		((double)dt.tmp.mapx + 1.0 - dt.map.player.x) * dt.tmp.delta.x;
	dt.tmp.stepy = (dt.tmp.raydir.y < 0) ? -1 : 1;
	dt.tmp.s.y = (dt.tmp.raydir.y < 0) ?
		(dt.map.player.y - (double)dt.tmp.mapy) * dt.tmp.delta.y :
		((double)dt.tmp.mapy + 1.0 - dt.map.player.y) * dt.tmp.delta.y;
	raycasting(dt);
}

void	play(t_all dt)
{
	dt.tmp.pixelx = -1;
	while (++dt.tmp.pixelx < WIDTH)
	{
		dt.tmp.camerax = 2 * dt.tmp.pixelx / (double)WIDTH - 1;
		dt.tmp.raydir.x = dt.tmp.view.x + dt.map.plane.x * dt.tmp.camerax;
		dt.tmp.raydir.y = dt.tmp.view.y + dt.map.plane.y * dt.tmp.camerax;
		init(dt);
	}
	mlx_put_image_to_window(dt.mlx.init, dt.mlx.win, dt.mlx.image.addr, 0, 0);
}
