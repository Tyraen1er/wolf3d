/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_allstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 21:19:47 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/24 21:19:48 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_read_allstr(int fd, void **file)
{
	int		size;
	int		rd;
	char	buf[151];
	char	*tmp;

	size = 0;
	tmp = NULL;
	*file = ft_memalloc(1);
	while ((rd = read(fd, buf, 150)) && rd != -1)
	{
		buf[rd] = 0;
		tmp = ft_strjoin(*file, buf);
		size += rd;
		free(*file);
		*file = tmp;
	}
	if (rd == -1 || !tmp || !*file)
		return (-1);
	return (size);
}
