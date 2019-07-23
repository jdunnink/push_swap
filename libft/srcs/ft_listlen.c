/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_listlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:41:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/23 12:42:12 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_listlen(t_list *list)
{
	size_t len;
	t_list *iter;

	len = 0;
	iter = list;
	while (iter)
	{
		iter = iter->next;
		len++;
	}
	return (len);
}