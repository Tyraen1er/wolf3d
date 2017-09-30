/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 07:54:38 by eferrand          #+#    #+#             */
/*   Updated: 2017/09/30 02:12:52 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"


/*
 **	int height = point de separation des couleurs
 */
void	fill_img(int x, int *height, int *color, int *img)
{
	int		a;

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

// a refaire
void	wall_size(t_all dta, double length, int side)
{
	int	height[2];
	int	color[3];

	//	couleur du plafond
	color[0] = 0X808080;
	// limite haute du mur en y
	height[0] = HEIGHT / 2 - length / 2;
	if (abs(side) == 1)
		color[1] = (side == 1) ? 0xFFFF00 : 0xFFFF;
	else if (abs(side) == 2)
		color[1] = (side == 1) ? 0xFF0000 : 0xFF;
	else
		color[1] = 0xFFFFFF;
	height[1] = HEIGHT / 2 + length / 2;
	//	couleur du sol
	color[2] = 0X663300;
	if (HEIGHT < height[1])
		height[1] = HEIGHT - 1;
	fill_img(dta.tmp.pixelx, height, color, (int*)dta.mlx.image.img);
}

void	raycasting(t_all data)
{
	int	mapx;
	int	mapy;
	int	stepx;
	int	stepy;
	int	side;

	mapx = (int)data.map.player.x;
	mapy = (int)data.map.player.y;
	data.tmp.dx = sqrt(1 + (data.tmp.view.y * data.tmp.view.y) / (data.tmp.view.x * data.tmp.view.x));
	data.tmp.dy = sqrt(1 + (data.tmp.view.x * data.tmp.view.x) / (data.tmp.view.y * data.tmp.view.y));
	if (data.tmp.view.x < 0)
	{
		stepx = -1;
		data.tmp.sx = (data.map.player.x - (double)mapx) * data.tmp.dx;
	}
	else
	{
		stepx = 1;
		data.tmp.sx = ((double)mapx + 1.0 - data.map.player.x) * data.tmp.dx;
	}
	if (data.tmp.view.y < 0)
	{
		stepy = -1;
		data.tmp.sy = (data.map.player.y - (double)mapy) * data.tmp.dy;
	}
	else
	{
		stepy = 1;
		data.tmp.sy = ((double)mapy + 1.0 - data.map.player.y) * data.tmp.dy;
	}
	while (1)
	{
		if (data.tmp.sx < data.tmp.sy)
		{
			data.tmp.sx += data.tmp.dx;
			mapx += stepx;
			side = (data.tmp.view.x < 0) ? -2 : 2;
		}
		else
		{
			data.tmp.sy += data.tmp.dy;
			mapy += stepy;
			side = (data.tmp.view.y < 0) ? -1 : 1;
		}
		if (data.map.map[mapx][mapy] || mapx == data.map.limitx || mapy == data.map.limity || !mapx || !mapy)
		{
			side = (mapx == data.map.limitx || mapy == data.map.limity) ? 0 : side;
			wall_size(data, sqrt(pow(data.map.player.x - (double)mapx, 2) + pow(data.map.player.y - (double)mapy, 2)), side);
			break ;
		}
	}
}

void	play(t_all data)
{
	double	radian;

	data.tmp.pixelx = 0;
	while (data.tmp.pixelx < WIDTH)
	{
		data.tmp.fov = (double)data.tmp.pixelx * (double)FOV / (double)WIDTH;
		radian = 0.0174533 * data.tmp.fov;
		data.tmp.view.x = cos(radian) * data.map.view.x - sin(radian) * data.map.view.y;
		data.tmp.view.y = sin(radian) * data.map.view.x + cos(radian) * data.map.view.y;
		raycasting(data);
		++data.tmp.pixelx;
	}
	printf("Hello World !\nAffichage de l image\n");
	mlx_put_image_to_window(data.mlx.init, data.mlx.win, data.mlx.image.addr, 0, 0);
	(void)data;
	return ;
}
