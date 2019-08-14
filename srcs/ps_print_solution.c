/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_print_solution.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 08:35:49 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/14 16:46:48 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	print_instr(char code)
{
	if (code == 'a')
		ft_putendl("pa");
	else if (code == 'b')
		ft_putendl("pb");
	else if (code == 'c')
		ft_putendl("sa");
	else if (code == 'd')
		ft_putendl("sb");
	else if (code == 'e')
		ft_putendl("ss");
	else if (code == 'f')
		ft_putendl("ra");
	else if (code == 'g')
		ft_putendl("rb");
	else if (code == 'h')
		ft_putendl("rr");
	else if (code == 'i')
		ft_putendl("rra");
	else if (code == 'j')
		ft_putendl("rrb");
	else if (code == 'k')
		ft_putendl("rrr");
}

static	void	check_output(char **solution)
{
	char *ptr;

	while (1)
	{
		ptr = ft_strstr(*solution, "if");
		if (ptr != 0)
		{
			ptr[0] = '_';
			ptr[1] = '_';
		}
		else
			break ;
	}
	while (1)
	{
		ptr = ft_strstr(*solution, "fi");
		if (ptr != 0)
		{
			ptr[0] = '_';
			ptr[1] = '_';
		}
		else
			break ;
	}
}

void			print_solution(char *solution)
{
	unsigned i;

	i = 0;
	check_output(&solution);
	while (solution[i] != '\0')
	{
		print_instr(solution[i]);
		i++;
	}
}
