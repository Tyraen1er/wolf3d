/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savebitmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:53:25 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/24 22:32:09 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Beaucoup de fichier bmp ont des entetes falasieuses
** ce programme n est donc pas fonctionel dans 100% des cas
** mais normalement les fichier bmp non compressé sont nickels
*/

int		ft_load_bitmap(int fd, t_bmp *bmp)
{
	if (read(fd, (char*)&(bmp->header.bf_type), 2) != 2 ||
	read(fd, (char*)&(bmp->header.bf_size), 12) != 12 ||
					(bmp->header.bf_type !=
			0x4D42 && bmp->header.bf_type != 0x4142 && bmp->header.bf_type !=
			0x4943 && bmp->header.bf_type != 0x5043 && bmp->header.bf_type !=
			0x4349 && bmp->header.bf_type != 0x5450) ||
				read(fd, (char*)&(bmp->info), 40) != 40 ||
			bmp->info.info_size != 40 || bmp->info.nb_planes != 1)
		return (-1);
	if (bmp->info.bits_per_pixel < 24)
	{
		bmp->palette = (unsigned int*)malloc(sizeof(int) *
				bmp->info.nb_color_used);
		if (-1 == read(fd, (char*)bmp->palette, bmp->info.nb_color_used * 4) ||
				-1 == ft_read_all(fd, (void*)&bmp->picture))
			return (-1);
		return (1);
	}
	bmp->palette = NULL;
	if (-1 == ft_read_all(fd, (void*)&bmp->picture))
		return (-1);
	return (0);
}
