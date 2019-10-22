/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_choose_target.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 16:05:16 by jdunnink       #+#    #+#                */
/*   Updated: 2019/10/22 14:02:04 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	choose_target() is called when dynamic_sort() has determined
**	that a value other than the top value of the source stack
**	needs to be pushed to the destination stack. Choose_target()
**	then finds the value with the shortest path() variable in the
**	distances list and calls choose_act_a/b(), passing the target
**	value as argument.
*/

void	choose_target(t_list **distances, t_stacks **stacks, char **sol, char c)
{
	t_list	*iter;
	t_pos	*curr;
	int		shortest;
	t_pos	*target;

	iter = *distances;
	curr = (t_pos *)iter->content;
	shortest = curr->path;
	target = curr;
	while (iter)
	{
		curr = (t_pos *)iter->content;
		if (curr->path < shortest)
		{
			target = curr;
			shortest = curr->path;
		}
		iter = iter->next;
	}
	if (c == 'a')
		choose_act_a(stacks, sol, target);
	else
		choose_act_b(stacks, sol, target);
}
