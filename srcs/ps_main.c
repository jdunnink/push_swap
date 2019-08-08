/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:18:43 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/08 17:04:27 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*solution;
	char		*solution_two; 
	char 		*solution_three;
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
	else if (len <= 25)
		solution = insertion_sort(&stacks);				// change to selection sort
	else
	{
		if (len > 250)
			solution = position_sort(&stacks, 0.05);
		else
			solution = position_sort(&stacks, 0.10);
		printf("	positional sort done --> calling selection sort\n");
		solution_two = selection_sort(&stacks);
		solution = ft_strjoin_free(solution, solution_two, 3);
		solution_three = insertion_sort(&stacks);
		solution = ft_strjoin_free(solution, solution_three, 3);
	}
	printf("ending solution  : %s\n", solution);
	printf("total instructions: %lu\n", ft_strlen(solution));
	print_state(stacks);
	return (0);
}