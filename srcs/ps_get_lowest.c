/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_get_lowest.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 15:37:56 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/14 17:13:41 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lowest(t_list *stack, int *low_dis)
{
	int		lowest;
	t_list	*iter;
	int		i;

	i = 0;
	lowest = *(int *)stack->content;
	iter = stack;
	while (iter)
	{
		if (*(int *)iter->content < lowest)
		{
			*low_dis = i;
			lowest = *(int *)iter->content;
		}
		iter = iter->next;
		i++;
	}
	return (lowest);
}
