/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   copy_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 13:30:42 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 08:06:18 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

t_stacks	*copy_stacks(t_stacks *stacks)
{
	t_stacks *dest;

	dest = (t_stacks *)malloc(sizeof(t_stacks));
	if (!dest)
		error(2);
	if (stacks->a != NULL)
		dest->a = ft_lstcpy(stacks->a);
	else
		dest->a = NULL;
	if (stacks->b != NULL)
		dest->b = ft_lstcpy(stacks->b);
	else
		dest->b = NULL;
	return (dest);
}
