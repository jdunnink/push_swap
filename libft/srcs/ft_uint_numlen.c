/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uint_numlen.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/12 14:40:22 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/07/12 14:40:43 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uint_numlen(unsigned long long value, int base)
{
	size_t i;

	i = 0;
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}
