/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:18:43 by jdunnink       #+#    #+#                */
/*   Updated: 2019/10/22 11:55:17 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	free_stacks() cleans the memory used for the stack
**	values after a solution has been presented or an error
**	has occurred.
*/

static	void	free_stacks(t_stacks **stacks)
{
	t_list *a;
	t_list *b;

	a = (*stacks)->a;
	b = (*stacks)->b;
	if (a)
		ft_lstdel(&a, &ft_del);
	if (b)
		ft_lstdel(&b, &ft_del);
	free(*stacks);
}

/*
**	choose_path() determines which algorithm to use based of the
**	number of values present in stack A. lists with a length of 4
**	and below are solved using brute force iteration. Lists of 5
**	us select_sort() and everything else uses dynamic_sort().
*/

static	void	choose_path(size_t len, t_stacks **stacks, char **solution)
{
	if (len <= 4)
		*solution = brute_force(stacks);
	else if (len <= 5)
		*solution = select_sort(stacks);
	else
		*solution = dynamic_sort(stacks);
}

/*
**	Starting the push_swap program, the stacks are initiated
**	and the input list is read into stack A. If the list
**	is longer than one and is currently not sorted, the program
**	chooses an appropriate algorithm based on the length of the
**	list, using choose_path(). Afterwards, a solution is presented
**	to the user using print_solution() in the form of an instruction list
**	which can be interpreted by the 'checker' program.
*/

int				main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*solution;
	size_t		len;

	stacks = NULL;
	if (argc <= 1)
		return (0);
	else
	{
		init_stacks(&stacks);
		read_input(argc, argv, &stacks);
	}
	len = ft_listlen(stacks->a);
	if (len > 1 && check_solved(stacks) == 0)
	{
		choose_path(len, &stacks, &solution);
		print_solution(solution);
		free(solution);
	}
	free_stacks(&stacks);
	return (0);
}
