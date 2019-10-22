/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 08:05:21 by jdunnink       #+#    #+#                */
/*   Updated: 2019/10/22 11:13:36 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**	Initiate a struct (t_stacks) containing two linked lists,
**	symbolizing the two stacks (A and B). The t_stacks struct is
**	defined in the  'shared' header file.
*/

void	init_stacks(t_stacks **stacks)
{
	*stacks = NULL;
	*stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!(*stacks))
		error(2);
	(*stacks)->a = NULL;
	(*stacks)->b = NULL;
}
