/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_brute_force.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:51:21 by jdunnink       #+#    #+#                */
/*   Updated: 2019/10/22 12:07:48 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	is_all_k() checks if a given solution
**	contains only 'k' characters.
*/

static	int		is_all_k(char *solution)
{
	unsigned i;

	i = 0;
	while (solution[i] != '\0')
	{
		if (solution[i] != 'k')
			return (0);
		i++;
	}
	return (1);
}

/*
**	mod_solution() changes the next solution to try,
**	by changing the letter to the next one in alphabetical order,
**	'a' becomes 'b', 'b' becomes 'c'. until 'k' is reached.
**	if the last tried solution contained only 'k',
**	the instruction count is increased: 'k' becomes 'aa',
**	'kk' becomes 'aaa'.
*/

static	void	mod_solution(char **str)
{
	char	*tail;

	if (is_all_k(*str) == 1)
	{
		*str = ft_memset(*str, 'a', ft_strlen(*str));
		*str = ft_stradd(*str, ft_ctostr('a'));
		return ;
	}
	else
	{
		tail = ft_str_tail(*str);
		while (*tail == 'k')
		{
			*tail = 'a';
			tail--;
		}
		(*tail)++;
	}
}

/*
**	brute_force() tries to find a solution that sorts
**	the stacks by trying different combinations of instructions
**	iteratively. In this approach, every instruction is codified
**	with a letter ranging from 'a' to 'k'. Different alphabetical
**	combinations are tried until a valid solution is found.
*/

char			*brute_force(t_stacks **stacks)
{
	char		*solution;
	int			res;
	t_stacks	*backup;

	res = 0;
	solution = ft_ctostr('a');
	while (1)
	{
		backup = copy_stacks(*stacks);
		if (try_solution(solution, stacks) == 1)
			break ;
		else
		{
			mod_solution(&solution);
			reset_stacks(stacks, &backup);
		}
	}
	return (solution);
}
