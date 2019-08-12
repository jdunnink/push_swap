/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_rotate.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 18:02:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 07:46:32 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	rotate_rotate(t_stacks **stacks)
{
	rotate_b(stacks);
	rotate_a(stacks);
}
