/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_track_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:51:21 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/24 17:24:30 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_next_instr(t_stacks **stacks, int *direction)
{
	if (*direction == -1)
		return (push_ab(stacks, direction));
	else if (*direction == 1)
		return (push_ba(stacks, direction));
	return (NULL);
}

char	*read_instr(char *next_instr)
{
	if (next_instr == NULL)
		return (NULL);
	if (ft_strcmp(next_instr, "a") == 0)
		return ("push_a");
	else if (ft_strcmp(next_instr, "b") == 0)
		return ("push_b");
	else if (ft_strcmp(next_instr, "c") == 0)
		return ("swap_a");
	else if (ft_strcmp(next_instr, "d") == 0)
		return ("swap_b");
	else if (ft_strcmp(next_instr, "e") == 0)
		return ("swap_swap");
	else if (ft_strcmp(next_instr, "f") == 0)
		return ("rotate_a");
	else if (ft_strcmp(next_instr, "g") == 0)
		return ("rotate_b");
	else if (ft_strcmp(next_instr, "h") == 0)
		return ("rotate_rotate");
	else if (ft_strcmp(next_instr, "i") == 0)
		return ("rev_rotate_a");
	else if (ft_strcmp(next_instr, "j") == 0)
		return ("rev_rotate_b");
	else if (ft_strcmp(next_instr, "k") == 0)
		return ("rev_rotate_rotate");
	else
		return (NULL);
}

char	*track_sort(t_stacks **stacks)
{
	char	*solution;
	char	*next_instr;
	int		direction;

	solution = NULL;
	next_instr = NULL;
	direction = -1;
	while (check_sort((*stacks)->a) == 0 || check_rev_sort((*stacks)->b) == 0)
	{
		next_instr = get_next_instr(stacks, &direction);
		if (direction == 0)
				break ;
		printf("	next instruction: %s\n", read_instr(next_instr));
		if (next_instr != NULL)
			if (try_solution(next_instr, stacks) == 1)
				break ;
		solution = ft_stradd(solution, next_instr);
		print_state(*stacks);
	}
	return (solution);
}