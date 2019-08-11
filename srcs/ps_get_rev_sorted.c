/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_get_rev_sorted.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/10 16:00:33 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/11 19:59:11 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *get_rev_sorted(t_stacks **stacks)
{
	t_list *dest;
	t_list *tmp;

	dest = NULL;
	dest = ft_lstcpy((*stacks)->b);
	dest = ft_lst_mergesort(dest);
	tmp = dest;
	dest = ft_lstrev(dest);
	ft_lstdel(&tmp, &ft_del);
	return (dest);
}