/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uncompress_bitmap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 21:18:11 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/24 21:20:11 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bmp	ft_uncompress_bitmap(t_bmp old)
{
	t_bmp	new;
	int		a;
	int		b;

	a = 0;
	b = 0;
	new = old;
	new.info.compression = 0;
	new.palette = (unsigned int*)ft_read_bits(old.picture,
			old.info.bits_per_pixel, old.info.width * old.info.height);
	new.picture = (unsigned char*)malloc(old.info.width * old.info.height * 4);
	while (a < old.info.width * old.info.height)
	{
		new.picture[b++] = old.palette[new.palette[a]];
		new.picture[b++] = old.palette[new.palette[a]] >> 8;
		new.picture[b++] = old.palette[new.palette[a]] >> 16;
		++a;
	}
	a = 0;
	ft_memdel((void*)&new.palette);
	return (new);
}
