/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_instruct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:51:21 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 18:25:33 by jdunnink      ########   odam.nl         */
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

#include <stdio.h>

int				instruct(char *str, t_stacks **stacks, char **solution)
{
	unsigned i;

	printf("	executing instruction: %s\n\n", str);

	i = 0;
	while (str[i] != '\0')
	{
		execute(str[i], stacks);
		i++;
	}
	*solution = ft_stradd(*solution, str);
	if (check_solved(*stacks) == 1)
		return (1);
	return (0);
}
