/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:18:43 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 14:14:18 by jdunnink      ########   odam.nl         */
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
	if (len <= 5)
		*solution = brute_force(stacks);
	else if (len <= 100)
	{
		*solution = position_sort(stacks, 0.10);
		*solution = ft_strjoin_free(*solution, chunk_sort(stacks, len), 3);
	}
	else
	{
		*solution = position_sort(stacks, 0.05);
		*solution = ft_strjoin_free(*solution, chunk_sort(stacks, len / 2), 3);
		*solution = ft_strjoin_free(*solution, insertion_sort(stacks), 3);
	}
}

int				main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*solution;
	size_t		len;

	stacks = NULL;
	if (argc <= 1)
		error(1);
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
