/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_insertion_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 07:57:12 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 07:59:07 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		find_highest(t_list *stack_b)
{
	int		highest;
	t_list	*iter;

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

static	int		execute(char *str, t_stacks **stacks, char **solution, int val)
{
	instruct(str, stacks, solution);
	return (val);
}

char			*insertion_sort(t_stacks **stacks)
{
	char	*solution;
	t_ints	vars;

	vars.one = find_highest((*stacks)->a);
	solution = NULL;
	while (check_sort((*stacks)->a) == 0 || (*stacks)->b)
	{
		vars.two = *(int *)(*stacks)->a->content;
		vars.three = *(int *)(*stacks)->a->next->content;
		if ((*stacks)->b)
		{
			vars.five = *(int *)(*stacks)->b->content;
			if (vars.five < vars.two && vars.five > vars.four)
			{
				instruct(ft_ctostr('a'), stacks, &solution);
				continue ;
			}
		}
		if (vars.two > vars.three && vars.two != vars.one)
			vars.five = execute(ft_strdup("bi"), stacks, &solution, vars.two);
		else
			vars.four = execute(ft_ctostr('f'), stacks, &solution, vars.two);
	}
	return (solution);
}
