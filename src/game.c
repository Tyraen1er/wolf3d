/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 07:54:38 by eferrand          #+#    #+#             */
/*   Updated: 2017/09/29 14:51:09 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"


/*
 **	int height = point de separation des couleurs
 **
 */
void	fill_img(int x, int *height, int *color, char *img)
{
	int	a;
	int	b;

	a = -1;
	b = -1;
	while (++a < HEIGHT && ++b < 3)
		while (a < height[b])
			img[x + a * height[b] * WIDTH] = color[b];
}

// a refaire
void	wall_size(t_all dta, double length, int side)
{
	int	height[2];
	int	color[2];

	//	couleur du plafond
	color[0] = 0X808080;
	// limite haute du mur en y
	height[0] = (int)(WALL * length) / 2;
	color[0] = (side) ? 0xFF0000 : 0xFF;
	height[0] = (int)(WALL * length) / 2;
	//	couleur du sol
	color[1] = 0X663300;
	if (HEIGHT < height[1] - height[0])
	{
		height[0] = 0;
		height[1] = HEIGHT - 1;
	}
	fill_img(dta.tmp.pixelx, height, color, dta.mlx.image.img);
}

void	raycasting(t_all data)
{
	int	mapxy[2];
	double sidedistxy[2];
	double deltadistxy[2];
	int	stepxy[2];
	int	hit_side[2];

	mapxy[0] = (int)(data.tmp.rayposx);
	mapxy[1] = (int)(data.tmp.rayposy);
	deltadistxy[0] = sqrt(1 + (data.tmp.raydiry * data.tmp.raydiry) / (data.tmp.raydirx * data.tmp.raydirx));
	deltadistxy[1] = sqrt(1 + (data.tmp.raydirx * data.tmp.raydirx) / (data.tmp.raydiry * data.tmp.raydiry));
	hit_side[0] = 0;
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
	while (hit_side[0] == 0)
	{
		if (sidedistxy[0] < sidedistxy[1])
		{
			sidedistxy[0] += deltadistxy[0];
			mapxy[0] += stepxy[0];
			hit_side[1] = 0;
		}
		else
		{
			sidedistxy[1] += deltadistxy[1];
			mapxy[1] += stepxy[1];
			hit_side[1] = 1;
		}
		printf("map[%d][%d]\n", mapxy[0], mapxy[1]);
		if (data.map.map[mapxy[0]][mapxy[1]])
			hit_side[0] = 1;
	}
}

/*
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
   printf("\nlength = %f\ndxy[0] = %f\ndxy[1] = %f\nxy[0] = %f\nxy[1] = %f\nlimitx = %d\nlimity = %d\nwhile (0 < xy[0] && xy[0] < dta.map.limitx && 0 < xy[1] && xy[1] < dta.map.limity)\n", length, dxy[0], dxy[1], xy[0], xy[1], dta.map.limitx, dta.map.limity);
   while (0 < xy[0] && xy[0] < dta.map.limitx && 0 < xy[1] && xy[1] < dta.map.limity)
   {
   if (dta.map.map[(int)xy[0]] || dta.map.map[(int)xy[1]])
   break ;
   xy[0] += dxy[0];
   xy[1] += dxy[1];
   }
   wall_size(dta, sqrt(pow(dta.map.player.x - xy[0], 2) + pow(dta.map.player.y - xy[1], 2)));
   }
   */

void	play(t_all data)
{
	double	fov;

	printf("%f\n", data.map.map[0][0]);
	printf("je l ai passé\n");
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
		raycasting(data);
	}
	mlx_put_image_to_window(data.mlx.init, data.mlx.win, data.mlx.image.addr, 0, 0);
	(void)data;
	return ;
}
