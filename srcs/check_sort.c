/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:33:37 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/29 12:58:51 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

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

int	check_sort(t_list *stack)
{
	t_list	*iter;
	int		curr;
	int		next;

	iter = stack;
	if (iter == NULL)
		return (1);
	while (iter->next)
	{
		curr = *(int *)iter->content;
		next = *(int *)iter->next->content;
		if (next < curr)
		{
			return (0);
		}
		iter = iter->next;
	}
	return (1);
}