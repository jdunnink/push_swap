/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:33:37 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 07:45:43 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

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
