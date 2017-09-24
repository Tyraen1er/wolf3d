/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 07:54:38 by eferrand          #+#    #+#             */
/*   Updated: 2017/09/23 23:19:30 by eferrand         ###   ########.fr       */
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
	data->map.view = sinh(move) / cosh(move);
	play(*data);
}

void	minimap(t_img mlx, t_map map)
{
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
