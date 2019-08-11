/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_find_index.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/10 16:00:33 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/11 20:03:15 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(int *value, t_list *indices)
{
	int	val;
	t_list		*iter;
	t_index 	*curr;

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