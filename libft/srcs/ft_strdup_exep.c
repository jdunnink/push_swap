/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup_exep.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 11:06:08 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 17:59:12 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**s	allocates a new null-terminated duplicate of the string *s1,
**	with the exclusion of all occurences of char c in the string s1.
*/

char	*ft_strdup_exep(const char *s1, char c)
{
	char	*dest;
	char	*tmp;
	size_t	len;

	len = 0;
	tmp = (char *)s1;
	while (*tmp != '\0')
	{
		if (*tmp != c)
			len++;
		tmp++;
	}
	dest = ft_strnew(len);
	tmp = dest;
	while (*s1 != '\0')
	{
		if (*s1 != c)
		{
			*dest = *s1;
			dest++;
		}
		s1++;
	}
	return (tmp);
}
