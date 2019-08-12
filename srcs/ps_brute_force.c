/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_brute_force.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:51:21 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 07:45:53 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
