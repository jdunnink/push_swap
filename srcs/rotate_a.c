/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_a.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 18:02:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 07:46:31 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	rotate_a(t_stacks **stacks)
{
	t_list	*target;
	t_list	*iter;

	target = (*stacks)->a;
	iter = (*stacks)->a;
	if (target == NULL || target == NULL)
		return ;
	while (iter->next)
		iter = iter->next;
	iter->next = target;
	(*stacks)->a = (*stacks)->a->next;
	target->next = NULL;
}
