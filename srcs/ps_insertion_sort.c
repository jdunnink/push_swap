/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_insertion_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/29 09:25:25 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/29 12:49:32 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_lowest(int pivot, t_list *stack)
{
	int		lowest;
	t_list	*iter;

	iter = stack;
	lowest = *(int *)iter->content;
	iter = iter->next;
	while (iter)
	{
		if (*(int *)iter->content < lowest)
			lowest = *(int *)iter->content;
		iter = iter->next;
	}
	if (pivot == lowest)
		return (1);
	return (0);
}

static int	is_highest(int pivot, t_list *stack)
{
	int		highest;
	t_list	*iter;

	iter = stack;
	highest = *(int *)iter->content;
	iter = iter->next;
	while (iter)
	{
		if (*(int *)iter->content > highest)
			highest = *(int *)iter->content;
		iter = iter->next;
	}
	if (pivot == highest)
		return (1);
	return (0);
}

char	*insertion_sort(t_stacks **stacks)
{
	char	*solution;
	int		curr;
	int		curr_b;
	int		next;

	printf("insertion sort is called with state: \n");

	print_state(*stacks);
	solution = NULL; 
	while (1)
	{
		curr = *(int *)(*stacks)->a->content;
		next = *(int *)(*stacks)->a->next->content;
		if (curr > next && is_highest(curr, (*stacks)->a) == 0)
		{
			if (instruct(ft_strdup("bi"), stacks, &solution) == 1)
				break ;
		}
		else if (ft_listlen((*stacks)->b) > 0)
		{
			curr_b = *(int *)(*stacks)->b->content;
			if (curr < curr_b && next > curr_b)
			{
				if (instruct(ft_strdup("fa"), stacks, &solution) == 1)
					break ;
			}
			else
			{
				if (instruct(ft_ctostr('f'), stacks, &solution) == 1)
					break ;		
			}
		}
		else
		{
			if (instruct(ft_ctostr('f'), stacks, &solution) == 1)
				break ;
		}
	}
	while (ft_listlen((*stacks)->b) > 0)
		instruct(ft_ctostr('a'), stacks, &solution);
	return (solution);
}