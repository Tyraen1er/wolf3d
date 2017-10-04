/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 04:38:29 by eferrand          #+#    #+#             */
/*   Updated: 2017/10/01 04:39:45 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	border(t_map data)
{
	int		a;

	a = 0;
	while (data.map[0][a] != 0 && a < data.limitx - 1)
		++a;
	if (data.map[0][a] == 0)
		ft_exit(1);
	a = 0;
	while (data.map[a][0] != 0 && a < data.limity - 1)
		++a;
	if (data.map[a][0] == 0)
		ft_exit(1);
	a = 0;
	while (data.map[data.limity - 1][a] != 0 && a < data.limitx - 1)
		++a;
	if (data.map[data.limity - 1][a] == 0)
		ft_exit(1);
	a = 0;
	while (data.map[a][data.limitx - 1] != 0 && a < data.limity - 1)
		++a;
	if (data.map[a][data.limitx - 1] == 0)
		ft_exit(1);
}
