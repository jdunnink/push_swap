/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 08:05:21 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/08/12 08:05:22 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_stacks(t_stacks **stacks)
{
	*stacks = NULL;
	*stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!(*stacks))
		error(2);
	(*stacks)->a = NULL;
	(*stacks)->b = NULL;
}
