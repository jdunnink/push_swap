/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sort_a.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 16:08:02 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/14 17:10:58 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_stacks **stacks, char **solution)
{
	int		top;
	int		next;
	int		highest;
	int		high_dis;

	highest = get_highest((*stacks)->a, &high_dis);
	while (check_sort((*stacks)->a) == 0)
	{
		top = *(int *)(*stacks)->a->content;
		next = *(int *)(*stacks)->a->next->content;
		if (next < top && top != highest)
			instruct(ft_ctostr('c'), stacks, solution);
		else
			instruct(ft_ctostr('f'), stacks, solution);
	}
	while (*(int *)(*stacks)->a->content != highest)
		instruct(ft_ctostr('f'), stacks, solution);
}
