/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:18:43 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/23 21:23:00 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*solution;
	
	stacks = NULL;
	if (argc <= 1)
		error(1);
	else
	{
		init_stacks(&stacks);
		read_input(argc, argv, &stacks);
	}
	print_state(stacks);


	if (ft_listlen(stacks->a) <= 5)
		solution = brute_force(&stacks);
	else
		solution = track_sort(&stacks);
	
	printf("ending solution  : %s\n", solution);
	print_state(stacks);
	return (0);
}