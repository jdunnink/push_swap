/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_selection_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/29 13:01:34 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/08 15:52:55 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_lowest(t_list *stack)
{
	int lowest;
	t_list *iter;
	int	cmp;

	lowest = *(int *)stack->content;
	iter = stack->next;
	while (iter)
	{
		if (*(int *)iter->content < lowest)
			lowest = *(int *)iter->content;
		iter = iter->next;
	}
	return (lowest);
}

static	void	merge_stacks(t_stacks **stacks, char **solution)
{
	int		highest;
	int 	a_top;
	int 	a_last;
	int		b_top;
	t_list	*iter;

	iter = (*stacks)->a;
	highest = *(int *)(*stacks)->b->content;
	while ((*stacks)->b)
	{
		a_top = *(int *)(*stacks)->a->content;
		iter = (*stacks)->a;
		while (iter->next)
			iter = iter->next;
		a_last = *(int *)iter->content;
		b_top = *(int *)(*stacks)->b->content;
		if (b_top < a_top && b_top > a_last)
			instruct(ft_ctostr('a'), stacks, solution);
		else if (a_top < b_top)
			instruct(ft_ctostr('f'), stacks, solution);
		else
			instruct(ft_ctostr('i'), stacks, solution);
	}
	while (*(int *)(*stacks)->a->content != find_lowest((*stacks)->a))
		instruct(ft_ctostr('i'), stacks, solution);
}

int		find_highest(t_list *stack_b)
{
	int highest;
	t_list *iter;
	int	cmp;

	highest = *(int *)stack_b->content;
	iter = stack_b->next;
	while (iter)
	{
		if (*(int *)iter->content > highest)
			highest = *(int *)iter->content;
		iter = iter->next;
	}
	return (highest);
}

char	*selection_sort(t_stacks **stacks)
{
	char	*solution;
	int 	curr;
	int 	next;
	int		highest;
	int 	strike;

	solution = NULL;
	strike = 0;
	highest = find_highest((*stacks)->b);
	while (check_rev_sort((*stacks)->b) == 0)
	{
		curr = *(int *)(*stacks)->b->content;
		next = *(int *)(*stacks)->b->next->content;
		if (curr == highest)
			strike++;
		if (strike == 2)
			break ;
		if (curr < next)
			instruct(ft_ctostr('a'), stacks, &solution);
		else
			instruct(ft_ctostr('g'), stacks, &solution);
		
	}
	instruct(ft_ctostr('a'), stacks, &solution);
	merge_stacks(stacks, &solution);
	return (solution);
}