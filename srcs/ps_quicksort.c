/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_quicksort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/25 14:31:36 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/29 12:29:41 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	cmp_to_pivot_a(t_stacks **stacks, int pivot, char **solution)
{
	int		curr_top;
	char	*next_instr;

	curr_top = *(int *)(*stacks)->a->content;
	while (curr_top != pivot && ft_listlen((*stacks)->a) > 0)
	{
		if	(curr_top < pivot)
		{
			if (instruct(ft_ctostr('b'), stacks, solution) == 1)
				return ;
		}
		else if (curr_top > pivot)
		{
			if (instruct(ft_ctostr('f'), stacks, solution) == 1)
				return ;
		}
		curr_top = *(int *)(*stacks)->a->content;
	}
}

static 	int		is_tagged(int pivot, t_list **pivots)
{
	t_list *iter;
	int curr_piv;

	iter = *pivots;
	while (iter)
	{
		curr_piv = *(int *)iter->content;
		if (curr_piv == pivot)
			return (1);
		iter = iter->next;
	}
	return (0);
}

static int	is_lowest(int pivot, t_list *stack)
{
	int		lowest;
	int		second_lowest;
	t_list	*iter;

	iter = stack;
	lowest = *(int *)iter->content;
	iter = iter->next;
	while (iter)
	{
		if (*(int *)iter->content < lowest)
		{
			second_lowest = lowest;
			lowest = *(int *)iter->content;
		}
		else if (*(int *)iter->content > lowest && *(int *)iter->content < second_lowest)
			second_lowest = *(int *)iter->content;
		iter = iter->next;
	}
	if (pivot == lowest)
		return (1);
	else if (pivot == second_lowest)
		return (1);
	return (0);
}

static int	is_highest(int pivot, t_list *stack)
{
	int		highest;
	int		second_highest;
	t_list	*iter;

	iter = stack;
	highest = *(int *)iter->content;
	iter = iter->next;
	while (iter)
	{
		if (*(int *)iter->content > highest)
		{
			second_highest = highest;
			highest = *(int *)iter->content;
		}
		else if (*(int *)iter->content < highest && *(int *)iter->content > second_highest)
			second_highest = *(int *)iter->content;
		iter = iter->next;
	}
	if (pivot == highest)
		return (1);
	else if (pivot == second_highest)
		return (1);
	return (0);
}

static	char	*quick_sort_a(t_stacks **stacks, t_list **pivots)
{
	char	*solution;
	char	*next_instr;
	int		pivot;

	printf("	quick_sort_a is called!\n");

	solution = NULL;
	while (check_sort((*stacks)->a) == 0 || ft_listlen((*stacks)->a) > 0)
	{
		pivot = *(int *)(*stacks)->a->content;
		printf("	a new pivot has been set at: %i\n", pivot);
		if (is_tagged(pivot, pivots) == 1)
		{
			printf("	This pivot has been tagged --> pushing into list b!\n");
			if (instruct(ft_ctostr('b'), stacks, &solution) == 1)
				break ;
			continue ;
		}
		if (is_lowest(pivot, (*stacks)->a) == 1)
		{
			printf("	This pivot has no lower values --> pushing into list b!\n");
			if (instruct(ft_ctostr('b'), stacks, &solution) == 1)
				break ;
			continue ;
		}
		ft_lstpushfront(&pivot, pivots, sizeof(int));
		if (instruct(ft_ctostr('f'), stacks, &solution) == 1)
			break ;
		cmp_to_pivot_a(stacks, pivot, &solution);
		printf("	pivot is back at the top!\n");
		if (instruct(ft_ctostr('b'), stacks, &solution) == 1)
			break ;
	}
	printf("	quick sort a has finished\n");
	return (solution);
}

static	void	cmp_to_pivot_b(t_stacks **stacks, int pivot, char **solution)
{
	int		curr_top;
	char	*next_instr;

	curr_top = *(int *)(*stacks)->b->content;
	while (curr_top != pivot && ft_listlen((*stacks)->b) > 0)
	{
		if	(curr_top > pivot)
		{
			if (instruct(ft_ctostr('a'), stacks, solution) == 1)
				return ;
		}
		else if (curr_top < pivot)
		{
			if (instruct(ft_ctostr('g'), stacks, solution) == 1)
				return ;
		}
		curr_top = *(int *)(*stacks)->b->content;
	}
}

static	char	*quick_sort_b(t_stacks **stacks, t_list **pivots)
{
	char	*solution;
	char	*next_instr;
	int		pivot;

	printf("	quick_sort_b is called!\n");

	solution = NULL;
	while (check_sort((*stacks)->b) == 0 || ft_listlen((*stacks)->b) > 0)
	{
		pivot = *(int *)(*stacks)->b->content;
		printf("	a new pivot has been set at: %i\n", pivot);
		if (is_tagged(pivot, pivots) == 1)
		{
			printf("	This pivot has been tagged --> pushing into list a!\n");
			if (instruct(ft_ctostr('a'), stacks, &solution) == 1)
				break ;
			continue ;
		}
		ft_lstpushfront(&pivot, pivots, sizeof(int));
		if (is_highest(pivot, (*stacks)->b) == 1)
		{
			printf("	This pivot has no higher values --> pushing into list a!\n");
			if (instruct(ft_ctostr('a'), stacks, &solution) == 1)
				break ;
			continue ;
		}
		if (instruct(ft_ctostr('g'), stacks, &solution) == 1)
			break ;
		cmp_to_pivot_b(stacks, pivot, &solution);
		printf("	pivot is back at the top!\n");
		if (instruct(ft_ctostr('a'), stacks, &solution) == 1)
			break ;
	}
	printf("	quick sort b has finished\n");
	return (solution);
}

char	*quick_sort(t_stacks **stacks)
{
	char	*solution;
	t_list	*pivots;

	solution = NULL;
	pivots = NULL;

//	solution = improve_pivot(stacks);

	solution = ft_stradd(solution , quick_sort_a(stacks, &pivots));
	if (check_solved(*stacks) == 1)
		return (solution);
	solution = ft_stradd(solution, quick_sort_b(stacks, &pivots));
	return (solution);
}