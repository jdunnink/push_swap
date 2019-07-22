/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_a.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 18:02:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/22 18:24:17 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	swap_a(t_stacks **stacks)
{
	t_list	*a_curr;
	t_list	*a_next;
	int		*tmp;

	if (stacks == NULL)
		return ;
	a_curr = (*stacks)->a;
	if (a_curr == NULL)
		return ;
	a_next = a_curr->next;
	if (a_next == NULL)
		return ;
	tmp = a_curr->content;
	a_curr->content = a_next->content;
	a_next->content = tmp;
	return ;
}
