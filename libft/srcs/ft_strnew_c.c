/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_add_pad.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 18:02:52 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 18:03:19 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	allocates a new null-terminated string, initialized to char c.
*/

char	*ft_strnew_c(size_t len, char c)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	ft_memset(str, c, len);
	return (str);
}
