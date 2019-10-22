/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_choose_insert.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 11:41:36 by jdunnink       #+#    #+#                */
/*   Updated: 2019/10/22 13:12:44 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	choose_insert() inserts values from stack B into stack A, such that
**	the sortedness of stack A is not decreased. This appreach is used on
**	small lists that are already largely sorted.
*/

void	choose_insert(t_stacks **stacks, char **solution)
{
	int	top_a;
	int	top_b;

	top_a = *(int *)(*stacks)->a->content;
	top_b = *(int *)(*stacks)->b->content;
	if (top_a > top_b)
	{
		instruct(ft_ctostr('a'), stacks, solution);
		move_to_lowest(stacks, solution);
	}
	else
		instruct(ft_ctostr('f'), stacks, solution);
}
