/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_dynamic_sort.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 17:48:17 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/15 15:58:22 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
