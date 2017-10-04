/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_product.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 04:49:51 by eferrand          #+#    #+#             */
/*   Updated: 2017/10/01 04:49:57 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vector_product(double *fst, double *scd, double *res)
{
	res[0] = fst[1] * scd[2] - fst[2] * scd[1];
	res[1] = fst[2] * scd[0] - fst[0] * scd[2];
	res[2] = fst[0] * scd[1] - fst[1] * scd[0];
}
