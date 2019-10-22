/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_move_to_lowest.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 16:10:57 by jdunnink       #+#    #+#                */
/*   Updated: 2019/10/22 13:09:22 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	move_to_lowest() moves the lowest value in stack A
**	top the top, using either rotate or rev-rotate, depending
**	on which way is shorter.
*/

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
