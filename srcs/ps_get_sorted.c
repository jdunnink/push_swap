/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_get_sorted.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/11 19:12:33 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/11 19:23:13 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *get_sorted(t_list *list)
{
	t_list *dest;

	dest = ft_lstcpy(list);
	dest = ft_lst_mergesort(dest);
	return (dest);
}
