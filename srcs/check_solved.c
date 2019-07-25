/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_solved.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:39:40 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/25 17:22:47 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int		check_solved(t_stacks *stacks)
{
	if (check_sort(stacks->a) == 0)
		return (0);
	if (check_rev_sort(stacks->b) == 0)
		return (0);
	return (1);
}