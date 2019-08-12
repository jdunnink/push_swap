/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 08:00:15 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 08:00:39 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

static	void	print_stack(t_list *stack)
{
	t_list	*iter;
	int		nbr;

	iter = stack;
	while (iter)
	{
		nbr = *(int *)(iter->content);
		ft_putnbr(nbr);
		ft_putchar(' ');
		iter = iter->next;
	}
	ft_putchar('\n');
}

void			print_state(t_stacks *stacks)
{
	ft_putchar('\n');
	ft_putstr("STACK A | ");
	print_stack(stacks->a);
	ft_putstr("STACK B | ");
	print_stack(stacks->b);
	ft_putchar('\n');
}
