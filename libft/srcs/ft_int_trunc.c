/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int_trunc.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/12 14:37:57 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/07/12 14:38:23 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	truncates an int variable, level of truncation is dependent on the
**	argument typesize. -2 --> to_char / -1 --> to_short / 0 --> to_int
**	1 --> to_long.
*/

void	ft_int_trunc(long long *value, int typesize)
{
	if (typesize == -2)
		*value = (char)*value;
	else if (typesize == -1)
		*value = (short)*value;
	else if (typesize == 0)
		*value = (int)*value;
	else if (typesize == 1)
		*value = (long)*value;
}
