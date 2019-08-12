/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate_b.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 18:02:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 07:46:03 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	rev_rotate_b(t_stacks **stacks)
{
	t_list *iter;
	t_list *trail;
	t_list *tmp;

	if (stacks == NULL)
		return ;
	if (*stacks == NULL)
		return ;
	iter = (*stacks)->b;
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
	tmp = (*stacks)->b;
	(*stacks)->b = iter;
	iter->next = tmp;
}
