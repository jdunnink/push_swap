/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_b.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 18:02:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/22 19:15:54 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	rotate_b(t_stacks **stacks)
{
	t_list	*target;
	t_list	*iter;

	target = (*stacks)->b;
	iter = (*stacks)->b;
	if (target == NULL || target == NULL)
		return ;
	while (iter->next)
		iter = iter->next;
	iter->next = target;
	(*stacks)->b = (*stacks)->b->next;
	target->next = NULL;
}