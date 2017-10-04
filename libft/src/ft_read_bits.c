/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 20:58:00 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/24 20:58:01 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	len = nombre de buffer en bits a lire
**	buf = bits a lire pour 1 donnée
**	comp = chaine de données
*/

int		*ft_read_bits(unsigned char *comp, int buf, int len)
{
	int		*data;
	int		*var;

	var = (int[3]){0};
	data = (int*)ft_memalloc(len * sizeof(int));
	while (len--)
	{
		if (8 < var[2] + buf)
		{
			data[var[0]] = (comp[var[1]] >> var[2]);
			++var[1];
			data[var[0]] |= (comp[var[1]] >> (16 - buf - var[2]));
			comp[var[1]] = comp[var[1]] << (buf - 8 + var[2]);
			var[2] = buf - 8 + var[2];
		}
		else
		{
			data[var[0]] = comp[var[1]] >> (8 - buf);
			comp[var[1]] = comp[var[1]] << buf;
			var[2] += buf;
		}
		++var[0];
	}
	return (data);
}
