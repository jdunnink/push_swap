/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_update_indices.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/10 16:00:33 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/11 20:04:46 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*update_indices(t_stacks **stacks, t_list **indices)
{
	t_list		*new;
	t_list		*iter;
	t_index 	*curr;

	if (!(*stacks)->b)
	{
		ft_lstdel(indices, &ft_del);
		return (NULL);
	}
	new = set_indices(stacks);
	iter = new;
	while (iter)
	{
		curr = iter->content;
		curr->index = find_index(&(curr->nb), *indices);
		iter = iter->next;
	}
	ft_lstdel(indices, &ft_del);
	return (new);
}