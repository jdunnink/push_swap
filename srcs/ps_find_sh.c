/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_find_sh.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 15:58:20 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/14 17:31:41 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_sh(t_pos *target)
{
	if (target->type == 14)
	{
		if (target->r_dis == 0)
			return (3);
		else if (target->dest_rr_dis == 0)
			return (0);
		else if (target->r_dis < target->dest_rr_dis)
			return (0);
		else
			return (3);
	}
	if (target->rr_dis == 0)
		return (2);
	else if (target->dest_r_dis == 0)
		return (1);
	else if (target->rr_dis < target->dest_r_dis)
		return (1);
	else
		return (2);
}
