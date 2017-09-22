/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:20:05 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/15 14:20:47 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(int error)
{
	if (error == -1)
		ft_putstr("error read / open\n");
	else if (error == 1)
		ft_putstr("error input data\n");
	else if (error == 2)
		ft_putstr("error allocation\n");
	else if (error == 3)
		ft_putstr("error mlx\n");
	else
		ft_putstr("error\n");
	exit(3);
}
