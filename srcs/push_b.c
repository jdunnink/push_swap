/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 18:02:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/22 19:09:52 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	push_b(t_stacks **stacks)
{
	t_list *a_list;

	if (stacks == NULL)
		return ;
	a_list = (*stacks)->a;
	if (a_list == NULL)
		return ;
	ft_lstpushfront(a_list->content, &(*stacks)->b, a_list->content_size);
	(*stacks)->a = a_list->next;
	free(a_list->content);
	a_list->content_size = 0;
	free(a_list);
}