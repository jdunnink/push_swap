/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_lookup_index.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/09 12:56:11 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 07:58:53 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lookup_index(int *value, t_list *indices)
{
	int			val;
	t_list		*iter;
	t_index		*curr;

	val = *value;
	iter = indices;
	while (iter)
	{
		curr = iter->content;
		if (val == curr->nb)
			return (curr->index);
		iter = iter->next;
	}
	return (-1);
}
