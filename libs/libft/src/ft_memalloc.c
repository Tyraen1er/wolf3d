/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:24:17 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/29 02:32:58 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t sze)
{
	void	*spc;

	if (!(spc = malloc(sze)))
		ft_exit(2);
	else
	{
		while (sze--)
			((char *)spc)[sze] = 0;
		return (spc);
	}
}
