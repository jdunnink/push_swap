/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_try_solution.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:51:21 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 07:58:10 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	execute(char code, t_stacks **stacks)
{
	if (code == 'a')
		push_a(stacks);
	else if (code == 'b')
		push_b(stacks);
	else if (code == 'c')
		swap_a(stacks);
	else if (code == 'd')
		swap_b(stacks);
	else if (code == 'e')
		swap_swap(stacks);
	else if (code == 'f')
		rotate_a(stacks);
	else if (code == 'g')
		rotate_b(stacks);
	else if (code == 'h')
		rotate_rotate(stacks);
	else if (code == 'i')
		rev_rotate_a(stacks);
	else if (code == 'j')
		rev_rotate_b(stacks);
	else if (code == 'k')
		rev_rotate_rotate(stacks);
}

int				try_solution(char *str, t_stacks **stacks)
{
	unsigned i;

	i = 0;
	while (str[i] != '\0')
	{
		execute(str[i], stacks);
		i++;
	}
	if (check_solved(*stacks) == 1)
		return (1);
	return (0);
}
