/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_a.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 18:02:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/22 19:09:02 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	push_a(t_stacks **stacks)
{
	t_list *b_list;

	if (stacks == NULL)
		return ;
	b_list = (*stacks)->b;
	if (b_list == NULL)
		return ;
	ft_lstpushfront(b_list->content, &(*stacks)->a, b_list->content_size);
	(*stacks)->b = b_list->next;
	free(b_list->content);
	b_list->content_size = 0;
	free(b_list);
}