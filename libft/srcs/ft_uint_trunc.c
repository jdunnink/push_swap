/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uint_trunc.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/12 14:40:29 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/07/12 14:40:35 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_uint_trunc(unsigned long long *value, int typesize)
{
	if (typesize == -2)
		*value = (unsigned char)*value;
	else if (typesize == -1)
		*value = (unsigned short)*value;
	else if (typesize == 0)
		*value = (unsigned int)*value;
	else if (typesize == 1)
		*value = (unsigned long)*value;
}
