/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/12 14:34:23 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/07/12 14:34:26 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_base(int c, int base)
{
	char	*str;
	char	*str2;
	int		i;

	str = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(const char *str, int base)
{
	int	i;
	int	res;
	int	neg;

	res = 0;
	i = 0;
	neg = 0;
	while (ft_isspace(str[i]) == 1)
		++i;
	if (ft_issign(str[i]) == 1)
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (get_base(str[i], base) != -1)
	{
		res = res * base;
		res = res + get_base(str[i], base);
		i++;
	}
	if (neg == 1)
		return (-res);
	return (res);
}
