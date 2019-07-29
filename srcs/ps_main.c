/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:18:43 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/29 14:38:02 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*solution;
	char		*new;
	size_t		len;
	
	stacks = NULL;
	if (argc <= 1)
		error(1);
	else
	{
		init_stacks(&stacks);
		read_input(argc, argv, &stacks);
	}
	print_state(stacks);
	len = ft_listlen(stacks->a);
	if (len <= 5)
		solution = brute_force(&stacks);
	else if (len <= 30)
		solution = selection_sort(&stacks);
	else
	{
		solution = quick_sort(&stacks);
		solution = ft_stradd(solution, insertion_sort(&stacks));
	}
	printf("ending solution  : %s\n", solution);
	printf("total instructions: %lu\n", ft_strlen(solution));
	print_state(stacks);
	return (0);
}