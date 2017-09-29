/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 07:54:38 by eferrand          #+#    #+#             */
/*   Updated: 2017/09/29 19:15:22 by eferrand         ###   ########.fr       */
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
	color[1] = (side) ? 0xFF0000 : 0xFF;
	height[1] = HEIGHT / 2 + length / 2;
	//	couleur du sol
	color[2] = 0X663300;
	if (HEIGHT < height[1])
		height[1] = HEIGHT - 1;
	fill_img(dta.tmp.pixelx, height, color, (int*)dta.mlx.image.img);
}

void	raycasting(t_all data)
{
	int	mapxy[2];
	double sidedistxy[2];
	double deltadistxy[2];
	int	stepxy[2];
	int	side;

	mapxy[0] = (int)(data.tmp.rayposx);
	mapxy[1] = (int)(data.tmp.rayposy);
	deltadistxy[0] = sqrt(1 + (data.tmp.raydiry * data.tmp.raydiry) / (data.tmp.raydirx * data.tmp.raydirx));
	deltadistxy[1] = sqrt(1 + (data.tmp.raydirx * data.tmp.raydirx) / (data.tmp.raydiry * data.tmp.raydiry));
	if (data.tmp.raydirx < 0)
	{
		stepxy[0] = -1;
		sidedistxy[0] = (data.tmp.rayposx - mapxy[0]) * deltadistxy[0];
	}
	else
	{
		stepxy[0] = 1;
		sidedistxy[0] = (mapxy[0] + 1.0 - data.tmp.rayposx) * deltadistxy[0];
	}
	if (data.tmp.raydiry < 0)
	{
		stepxy[1] = -1;
		sidedistxy[1] = (data.tmp.rayposy - mapxy[1]) * deltadistxy[1];
	}
	else
	{
		stepxy[1] = 1;
		sidedistxy[1] = (mapxy[1] + 1.0 - data.tmp.rayposy) * deltadistxy[1];
	}
	printf("salut mec ça va tu vas bien ?\n");
	while (1)
	{
		if (sidedistxy[0] < sidedistxy[1])
		{
			sidedistxy[0] += deltadistxy[0];
			mapxy[0] += stepxy[0];
			side = 0;
		}
		else
		{
			sidedistxy[1] += deltadistxy[1];
			mapxy[1] += stepxy[1];
			side = 1;
		}
		printf("map[%d][%d]\n", mapxy[0], mapxy[1]);
		printf("== %f\n", data.map.map[mapxy[1]][mapxy[0]]);
		if (data.map.map[mapxy[1]][mapxy[0]] || mapxy[1] == data.map.limity || mapxy[0] == data.map.limitx)
		{
			printf("on se presente ? Mais non tu nous connais !\n");
			if (side == 0)
				wall_size(data, (mapxy[0] - data.tmp.rayposx + (1 - stepxy[0]) / 2) / data.tmp.raydirx, side);
			else
				wall_size(data, (mapxy[1] - data.tmp.rayposy + (1 - stepxy[1]) / 2) / data.tmp.raydiry, side);
			break ;
		}
	}
}

void	play(t_all data)
{
	double	fov;

	data.tmp.pixelx = 0;
	while (data.tmp.pixelx < WIDTH)
	{
		fov = (data.tmp.pixelx + 1) * WIDTH / 160;
		data.map.view = (t_point){cosh(0.0174533 * fov), sinh(0.0174533 * fov)};
//foireux
		data.tmp.camerax = 2 * data.tmp.pixelx / WIDTH -1;
		data.tmp.rayposx = data.map.player.x;
		data.tmp.rayposy = data.map.player.y;
		data.tmp.raydirx = data.map.view.x;
		data.tmp.raydiry = data.map.view.y;
		printf("data.tmp.pixelx = %d\nvecteur(%f\t%f)\n", data.tmp.pixelx, data.map.view.x, data.map.view.y);
		raycasting(data);
		++data.tmp.pixelx;
	}
	printf("Hello World !\n");
	mlx_put_image_to_window(data.mlx.init, data.mlx.win, data.mlx.image.addr, 0, 0);
	(void)data;
	return ;
}
