/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_dynamic_sort.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 17:48:17 by jdunnink       #+#    #+#                */
/*   Updated: 2019/10/22 13:58:31 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	set_up() pushes two values from stack A to stack B and sorts them
**	in descending order. This is done to create a reference for the other
**	values in Stack A to determine their priority to be pushed.
*/

static	void	set_up(t_stacks **stacks, char **solution)
{
	int	one;
	int two;

	instruct(ft_ctostr('b'), stacks, solution);
	two = *(int *)(*stacks)->a->content;
	one = *(int *)(*stacks)->b->content;
	instruct(ft_ctostr('b'), stacks, solution);
	if (two < one)
		instruct(ft_ctostr('d'), stacks, solution);
}

/*
**	the functions check_push_a/b() check if the top value
**	of the source stack can be pushed to the destination stack,
**	such that the sortedness of the destination stack is not
**	disrupted. A valid push value has both a rotate/rev-rotate
**	distance and a destination rotate/rev-rotate distance of zero.
*/

static	int		check_push_b(t_list **distances, t_stacks **stacks, char **sol)
{
	t_list	*iter;
	t_pos	*pos;

	iter = *distances;
	while (iter)
	{
		pos = (t_pos *)iter->content;
		if (pos->r_dis == 0 || pos->rr_dis == 0)
			if (pos->dest_r_dis == 0 || pos->dest_rr_dis == 0)
			{
				instruct(ft_ctostr('b'), stacks, sol);
				return (1);
			}
		iter = iter->next;
	}
	return (0);
}

static	int		check_push_a(t_list **distances, t_stacks **stacks, char **sol)
{
	t_list	*iter;
	t_pos	*pos;

	iter = *distances;
	while (iter)
	{
		pos = (t_pos *)iter->content;
		if (pos->r_dis == 0 || pos->rr_dis == 0)
			if (pos->dest_r_dis == 0 || pos->dest_rr_dis == 0)
			{
				instruct(ft_ctostr('a'), stacks, sol);
				return (1);
			}
		iter = iter->next;
	}
	return (0);
}

/*
**	execute() checks the distances for each value, based on the
**	latest state of the stack and chooses a target to be pushed to
**	the other stack. First, the distance list is updated by calling
**	update_distances(). Then, execute() checks if the value at the
**	top of the stack can be pushed using check_push_a/b(). If the
**	top value cannot be pushed, another target is selected within
**	the source stack using choose_target().
*/

static	void	execute(t_list **dists, t_stacks **stacks, char **sol, char c)
{
	if (c == 'a')
	{
		update_distances(dists, (*stacks)->a, (*stacks)->b, c);
		if (check_push_b(dists, stacks, sol) == 0)
			choose_target(dists, stacks, sol, c);
	}
	else
	{
		update_distances(dists, (*stacks)->b, (*stacks)->a, c);
		if (check_push_a(dists, stacks, sol) == 0)
			choose_target(dists, stacks, sol, c);
	}
}

/*
**	dynamic_sort() is the main solving algorithm for the majority
**	of list sizes. It find the the best value within the stack to
**	push to the other list, by comparing, for each value, the number of
**	instructions it takes to move that value to its correct position
**	within the other stack, such that the sortedness of the
**	destination stack is not disrupted.
*/

char			*dynamic_sort(t_stacks **stacks)
{
	char		*solution;
	t_list		*distances;

	solution = NULL;
	distances = NULL;
	set_up(stacks, &solution);
	while (ft_listlen((*stacks)->a) > 3)
		execute(&distances, stacks, &solution, 'a');
	sort_a(stacks, &solution);
	while ((*stacks)->b)
		execute(&distances, stacks, &solution, 'b');
	move_to_lowest(stacks, &solution);
	ft_lstdel(&distances, &ft_del);
	return (solution);
}
