/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_show_redundant.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/09 11:38:47 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/09 12:10:52 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// main redundancy 1: rev-rotate-a into rotate-a --> should be just rotate-a
// main redundancy 2: push_b --> rev_rotate_a --> rotate_a --> rotate_a --> push_a --> should be swap

void	show_redundant(char *solution)
{
	unsigned	i;
	int			trig;
	unsigned	counter;

	trig = 0;
	i = 0;
	counter = 0;
	while (solution[i + 1] != '\0')
	{
		if (solution[i] != solution[i + 1])
		{
			if (solution[i] == 'i' && solution[i + 1] == 'f')
				trig = 1;
			else if (solution[i] == 'f' && solution[i + 1] == 'i')
				trig = 1;
			if (trig == 1)
				counter++;
			trig = 0;
		}
		i++;
	}	
	printf("	%i redundancies found!\n", counter);
}