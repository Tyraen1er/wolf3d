/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 04:49:26 by eferrand          #+#    #+#             */
/*   Updated: 2017/10/01 04:49:29 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_scalar(double *fst, double *scd)
{
	return (fst[0] * scd[0] + fst[1] * scd[1] + fst[2] * scd[2]);
}
