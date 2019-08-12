/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_solved.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:39:40 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 07:45:42 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int		check_solved(t_stacks *stacks)
{
	if (check_sort(stacks->a) == 0)
		return (0);
	if (ft_listlen(stacks->b) > 0)
		return (0);
	return (1);
}
