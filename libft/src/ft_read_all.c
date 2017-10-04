/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 21:19:33 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/24 21:19:35 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_read_all(int fd, void **file)
{
	int		size;
	int		rd;
	char	buf[1000];
	char	*tmp;

	size = 0;
	tmp = NULL;
	*file = malloc(1);
	while ((rd = read(fd, buf, 1000)) && rd != -1)
	{
		tmp = ft_memjoin(*file, size, buf, rd);
		size += rd;
		free(*file);
		*file = tmp;
	}
	if (rd == -1 || !tmp || !*file)
		return (-1);
	return (size);
}
