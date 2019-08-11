/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_adjust_indices.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/10 16:00:33 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/11 20:01:36 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adjust_indices(t_list *indices, int p_rate)
{
	size_t len;
	int	nbs_per_chunk;
	int			i;
	int 		j;
	t_list *iter;
	t_index *curr;

	len = ft_listlen(indices);
	nbs_per_chunk = len / p_rate;
	iter = indices;
	i = 0;
	j = nbs_per_chunk;
	while (iter)
	{
		curr = (t_index *)iter->content;
		curr->index = i;
		j--;
		if (j == 0)
		{
			j = nbs_per_chunk;
			i++;
		}
		iter = iter->next;
	}
}