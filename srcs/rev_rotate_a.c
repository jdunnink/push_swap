/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate_a.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 18:02:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/22 19:24:05 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	rev_rotate_a(t_stacks **stacks)
{
	t_list *iter;
	t_list *trail;
	t_list *tmp;

	iter = (*stacks)->a;
	if (iter == NULL)
		return ;
	trail = iter;
	while (iter->next)
	{
		trail = iter;
		iter = iter->next;
	}
	trail->next = NULL;
	tmp = (*stacks)->a;
	(*stacks)->a = iter;
	iter->next = tmp;
}