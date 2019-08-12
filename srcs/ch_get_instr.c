/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ch_get_instr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/11 19:56:27 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 14:34:21 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	void	execute(char *code, t_stacks **stacks)
{
	if (ft_strcmp("sa", code) == 0)
		swap_a(stacks);
	else if (ft_strcmp("sb", code) == 0)
		swap_b(stacks);
	else if (ft_strcmp("ss", code) == 0)
		swap_swap(stacks);
	else if (ft_strcmp("pa", code) == 0)
		push_a(stacks);
	else if (ft_strcmp("pb", code) == 0)
		push_b(stacks);
	else if (ft_strcmp("ra", code) == 0)
		rotate_a(stacks);
	else if (ft_strcmp("rb", code) == 0)
		rotate_b(stacks);
	else if (ft_strcmp("rr", code) == 0)
		rotate_rotate(stacks);
	else if (ft_strcmp("rra", code) == 0)
		rev_rotate_a(stacks);
	else if (ft_strcmp("rrb", code) == 0)
		rev_rotate_b(stacks);
	else if (ft_strcmp("rrr", code) == 0)
		rev_rotate_rotate(stacks);
	else
		error(6);
}

void			get_instr(t_stacks **stacks)
{
	char *instruction;

	while (get_next_line(0, &instruction) > 0)
	{
		if (ft_strlen(instruction) == 0)
			break ;
		if (instruction)
		{
			execute(instruction, stacks);
			free(instruction);
		}
	}
}
