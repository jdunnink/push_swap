/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int_numlen.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/12 14:39:12 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/07/12 14:39:15 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_int_numlen(long long value, int base)
{
	unsigned int i;
	unsigned int neg;

	i = 0;
	neg = 0;
	if (value < 0 && base == 10)
		neg = 1;
	value = ft_llabs(value);
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i + neg);
}
