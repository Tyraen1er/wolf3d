/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 07:54:38 by eferrand          #+#    #+#             */
/*   Updated: 2017/09/25 11:02:36 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	rotation(t_all *data, char sense, char change)
{
	double			move;
	static double	sensibility = 1;

	if (change == '+' || change == '-')
	{
		sensibility *=  (change == '+') ? 1.1 : 0.9;
		return ;
	}
	move = ((sense == '-') ? -0.0174533 : 0.0174533) * sensibility;
	data->map.view = (t_point){cosh(move), sinh(move)};
	play(*data);
}

double	raycasting(t_map dta);
{
	int		a;
	double	length;
	double	dxy[2];
	double	xy[2];

	length = fabs(dta.view.y - dta.player.x) <= fabs(dta.view.x - dta.player.x)
		? fabs(dta.view.x - dta.player.x) : fabs(dta.view.y - dta.player.x);
	dxy[0] = (dta.view.x - dta.player.x) / length;
	dxy[1] = (dta.view.y - dta.player.y) / length;
	xy[0] = dta.player.x + 0.5;
	xy[1] = dta.player.y + 0.5;
	a = 0;
	while (++a <= length)
	{
		if (dta.map[(int)xy[0]] || dta.map[(int)xy[1]])
			return (distance);
		xy[0] += dxy[0];
		xy[1] += dxy[1];
	}
}

void	minimap(t_img mlx, t_map map)
{
	int		a;
	double	scalex;
	double	scaley;

	a = -1;
	scalex = 120 / WIDTH;
	scaley = 120 / HEIGHT;
	while (++a < 120)
	{

	}
	(void)mlx;
	(void)map;
}

void	play(t_all all)
{
	minimap(all.mlx.img[1], all.map);
	mlx_put_image_to_window(all.mlx.init, all.mlx.win, all.mlx.img[1].addr, 0, 0);
	(void)all;
	return ;
}
