/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_move_to_lowest.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 16:10:57 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/14 17:11:11 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_lowest(t_stacks **stacks, char **solution)
{
	int		lowest;
	int		low_dis;
	int		rev_dis;

	lowest = get_lowest((*stacks)->a, &low_dis);
	rev_dis = (int)ft_listlen((*stacks)->a) - low_dis;
	if (rev_dis < low_dis)
		while (*(int *)(*stacks)->a->content != lowest)
			instruct(ft_ctostr('i'), stacks, solution);
	else
		while (*(int *)(*stacks)->a->content != lowest)
			instruct(ft_ctostr('f'), stacks, solution);
}
