/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_print_distance_list.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 16:18:26 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/14 16:52:12 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_distance_list(t_list *distances)
{
	t_list	*iter;
	t_pos	*curr;

	iter = distances;
	while (iter)
	{
		curr = (t_pos *)iter->content;
		ft_putendl("value :");
		ft_putnbr(curr->value);
		ft_putendl(" with path: ");
		ft_putnbr(curr->path);
		ft_putchar('\n');
		iter = iter->next;
	}
}
