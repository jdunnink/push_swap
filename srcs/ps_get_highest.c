/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_get_highest.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 15:36:11 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/14 17:13:44 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_highest(t_list *stack, int *high_dis)
{
	int		highest;
	t_list	*iter;
	int		i;

	i = 0;
	highest = *(int *)stack->content;
	iter = stack;
	while (iter)
	{
		if (*(int *)iter->content > highest)
		{
			*high_dis = i;
			highest = *(int *)iter->content;
		}
		iter = iter->next;
		i++;
	}
	return (highest);
}
