/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 18:02:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/22 18:27:22 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	swap_swap(t_stacks **stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}