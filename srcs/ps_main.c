/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:18:43 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/28 10:43:26 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static	void	choose_path(size_t len, t_stacks **stacks, char **solution)
{
	if (len <= 4)
		*solution = brute_force(stacks);
	else if (len <= 5)
		*solution = select_sort(stacks);
	else
		*solution = dynamic_sort(stacks);
}

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
