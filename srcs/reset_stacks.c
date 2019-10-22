/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_stacks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 13:37:26 by jdunnink       #+#    #+#                */
/*   Updated: 2019/10/22 12:21:51 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/*
**	free_stacks() frees the 'stacks' struct passed as argument,
**	including its contents.
*/

static void	free_stacks(t_stacks **stacks)
{
	t_stacks *target;

	target = *stacks;
	if (!target)
		return ;
	if (target->a != NULL)
		ft_lstdel(&(target->a), &ft_del);
	if (target->b != NULL)
		ft_lstdel(&(target->b), &ft_del);
	free(*stacks);
	*stacks = NULL;
}

/*
**	reset_stacks() takes a 'stacks' struct a and backup version
**	and resets the primary stack to the previous state represented
**	by the backup.
*/

void		reset_stacks(t_stacks **stacks, t_stacks **backup)
{
	free_stacks(stacks);
	*stacks = *backup;
	*backup = NULL;
}
