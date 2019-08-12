/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate_a.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 18:02:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 07:46:30 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	rev_rotate_a(t_stacks **stacks)
{
	t_list *iter;
	t_list *trail;
	t_list *tmp;

	if (stacks == NULL)
		return ;
	if (*stacks == NULL)
		return ;
	iter = (*stacks)->a;
	if (iter == NULL)
		return ;
	if (ft_listlen(iter) < 2)
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
