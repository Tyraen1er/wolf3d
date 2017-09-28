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

void	bresenham(int x, int y, int *xymax, char *img)
{
	int	*d;
	int	err[2];
	int	*s;
	int	ret[2];

	printf("x=%d\ny=%d\n", x, y);
	ret[0] = 23;
	d = (int[2]){abs(xymax[0] - x), abs(xymax[1] - y)};
	s = (int[2]){(x < xymax[0]) ? 1 : -1, (y < xymax[1]) ? 1 : -1};
	err[0] = ((d[0] > d[1]) ? d[0] : -d[1]) / 2;

int i;
 i = 0;
while (++i)
	printf("%c | %d\n", img[i], i);
	printf("img = %c\n", img[x + y * WIDTH]);
	printf("x = %d y = %d\n", x, y);
	printf("xmqx = %d ymax[0] = %d\n", xymax[0], xymax[1]);
	sleep(1);
	while (1)
	{
		if (x - 1 + y * WIDTH < (WIDTH * HEIGHT))
		//((int*)img)[x - 1 + y * WIDTH] = 0xFFFFFF;
		if (x == xymax[0] && y == xymax[1])
			break;
		err[1] = err[0];
		if (err[1] >-d[0])
		{
			err[0] -= d[1];
			x += s[0];
		}
		if (err[1] < d[1])
		{
			err[0] += d[0];
			y += s[1];
		}
	}
}

void	trace(t_all *dta, double length)
{
	int	height;

	height = WALL * length / 2;
	if (HEIGHT < height)
		height = HEIGHT - 1;
	bresenham(dta->tmp.pixelx + 1, HEIGHT / 2 - height, (int[2]){dta->tmp.pixelx + 1, HEIGHT / 2 + height}, dta->mlx.img.img);
}


void	raycasting(t_all *dta)
{
	double	length;
	double	dxy[2];
	double	xy[2];

	length = fabs(dta->map.view.y - dta->map.player.x) <= fabs(dta->map.view.x - dta->map.player.x)
		? fabs(dta->map.view.x - dta->map.player.x) : fabs(dta->map.view.y - dta->map.player.x);
	dxy[0] = (dta->map.view.x - dta->map.player.x) / length;
	dxy[1] = (dta->map.view.y - dta->map.player.y) / length;
	xy[0] = dta->map.player.x;
	xy[1] = dta->map.player.y;
	while (0 < xy[0] && xy[0] < dta->map.limitx && 0 < xy[1] && xy[1] < dta->map.limity)
	{
		if (dta->map.map[(int)xy[0]] || dta->map.map[(int)xy[1]])
			break ;
		xy[0] += dxy[0];
		xy[1] += dxy[1];
	}
	trace(dta, sqrt(pow(dta->map.player.x - xy[0], 2) + pow(dta->map.player.y - xy[1], 2)));
}

void	play(t_all *data)
{
	double	fov;

	data->tmp.pixelx = 0;
	while (data->tmp.pixelx < WIDTH)
	{
		fov = (data->tmp.pixelx + 1) * WIDTH / 160;
		data->map.view = (t_point){cosh(0.0174533 * fov), sinh(0.0174533 * fov)};
		raycasting(data);
	}
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->mlx.img.addr, 0, 0);
	(void)data;
	return ;
}
