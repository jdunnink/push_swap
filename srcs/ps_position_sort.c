/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_position_sort.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 07:48:55 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 07:49:43 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_list	*add_indices(t_stacks **stacks)
{
	t_list		*iter;
	t_list		*sorted;
	t_index		new;
	t_list		*dest;
	unsigned	i;

	i = 0;
	dest = NULL;
	sorted = get_sorted((*stacks)->a);
	iter = sorted;
	while (iter)
	{
		new.index = i;
		new.nb = *(int *)iter->content;
		ft_lstpushback(&dest, &new, sizeof(t_index));
		i++;
		iter = iter->next;
	}
	ft_lstdel(&sorted, &ft_del);
	return (dest);
}

char			*position_sort(t_stacks **stacks, double precision)
{
	t_list	*indices;
	char	*solution;
	int		curr_pos;
	int		curr_index;
	int		limit;

	limit = ft_listlen((*stacks)->a) * precision;
	indices = add_indices(stacks);
	curr_pos = 0;
	solution = NULL;
	while ((*stacks)->a)
	{
		curr_index = lookup_index((*stacks)->a->content, indices);
		if (curr_index <= curr_pos + limit && curr_index >= curr_pos - limit)
		{
			instruct(ft_ctostr('b'), stacks, &solution);
			curr_pos++;
		}
		else if (curr_index < curr_pos)
			instruct(ft_strdup("bg"), stacks, &solution);
		else
			instruct(ft_ctostr('f'), stacks, &solution);
	}
	ft_lstdel(&indices, &ft_del);
	return (solution);
}
