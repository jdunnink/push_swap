/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_solved.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:39:40 by jdunnink       #+#    #+#                */
/*   Updated: 2019/10/22 11:46:37 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/*
**	check_solved() checks if the current state of
**	the stack qualifies as a valid solution.
**	criteria:
**	- stack A is sorted in ascending order.
**	- stack B is empty.
*/

int		check_solved(t_stacks *stacks)
{
	if (check_sort(stacks->a) == 0)
		return (0);
	if (ft_listlen(stacks->b) > 0)
		return (0);
	return (1);
}
