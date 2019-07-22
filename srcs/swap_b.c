/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 18:02:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/22 18:27:03 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	swap_b(t_stacks **stacks)
{
	t_list	*b_curr;
	t_list	*b_next;
	int		*tmp;

	if (stacks == NULL)
		return ;
	b_curr = (*stacks)->b;
	if (b_curr == NULL)
		return ;
	b_next = b_curr->next;
	if (b_next == NULL)
		return ;
	tmp = b_curr->content;
	b_curr->content = b_next->content;
	b_next->content = tmp;
	return ;
}