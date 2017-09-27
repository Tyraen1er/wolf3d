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

// probablement faux !

void	rotation(t_all *data, char sense, char change)
{
	double			move;
	static double	sensibility = 1;

//	rotation d un vecteur (0 ; 1)

	if (change == '+' || change == '-')
	{
		sensibility *=  (change == '+') ? 1.1 : 0.9;
		return ;
	}
	move = ((sense == '-') ? -0.0174533 : 0.0174533) * sensibility;
	data->map.view = (t_point){cosh(move), sinh(move)};
	play(data);
}

double	raycasting(t_all *dta)
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
	return (sqrt(pow(dta->map.player.x - xy[0], 2) + pow(dta->map.player.y - xy[1], 2)));
}

void	minimap(t_all *data, int img)
{
	int		a;
	int		b;
	int		offset;
	t_quad	plan;
	t_quad	win;

	if ((offset = (data->map.limitx / WIDTH_M) / 2) < 2)
		return ;
	plan = (t_quad){.tl = {0, 0}, .br = {data->map.limitx, data->map.limity}};
	win = (t_quad){.tl = {1, 1}, .br = {WIDTH_M, HEIGHT_M}};
	a = -1;
	while (++a < data->map.limity)
	{
		b = -1;
		while (++b < data->map.limitx)
			if (map[a][b])
			{
				ft_point_change_quad((t_point){0, 0}, plan, win);
			}
	}
}

/*
void	minimap(t_all *data, int img)
{
	int			a;
	int			b;
	double		scalex;
	double		scaley;
	pthread_t	th[NB_THREADS];

	b = -1;
	scalex = 120 / WIDTH;
	scaley = 120 / HEIGHT;
	(void)img;
	while (++b < WIDTH_M)
	{
		a = -1;
		while (++a < NB_THREADS)
			if (pthread_create(&th[a], NULL, fillingmini, (void*)data))
				ft_exit(4);
		a = -1;
		while (++a < NB_THREADS)
			if (pthread_join(th[a], NULL))
				ft_exit(4);
	}
}
*/

void	play(t_all *all)
{
	minimap(all, 1);
	mlx_put_image_to_window(all->mlx.init, all->mlx.win, all->mlx.img[1].addr, 0, 0);
	(void)all;
	return ;
}
