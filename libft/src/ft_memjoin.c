/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 21:18:27 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/24 21:20:31 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *str1, int a, void *str2, int b)
{
	char	*ret;

	if (!str1 && !str2)
		return (NULL);
	if (!(ret = (char *)malloc(a + b)))
		return (NULL);
	--b;
	while (0 <= b)
	{
		ret[a + b] = ((char *)str2)[b];
		--b;
	}
	--a;
	while (0 <= a)
	{
		ret[a] = ((char *)str1)[a];
		--a;
	}
	return (ret);
}
