/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ch_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 13:47:28 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 11:58:46 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	checker_program for the push_swap project. Takes a random sized list
**	of integers passed as argument, and then expects an input list
**	of operations on the standard input.
**	Instructions are only seperated by a newline.
**	After executing the listed instructions,
**	the checker program will signal to the user if the input list
**	is now correctly sorted or not.
**	During development, the checker program also shows the state
**	of the two stacks, after the execution of each instruction.
**	--> debug mode? (bonus)
*/

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = NULL;
	if (argc <= 1)
		exit(0);
	else
	{
		init_stacks(&stacks);
		read_input(argc, argv, &stacks);
	}
	get_instr(&stacks);
	if (check_solved(stacks) == 1)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (0);
}
