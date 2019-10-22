/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_choose_act_a.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 15:54:16 by jdunnink       #+#    #+#                */
/*   Updated: 2019/10/22 14:20:47 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	do_diff	chooses the instruction to execute on the stacks,
**	lowest distance within the distance list that is not zero.
**	(at zero distance, no further action is required in that stack).
**	double rotate/rev-rotations are excluded.
*/

static	void	do_diff(t_stacks **stacks, char **solution, t_pos *target)
{
	int place;

	place = find_sh(target);
	if (place == 0)
		instruct(ft_ctostr('f'), stacks, solution);
	else if (place == 1)
		instruct(ft_ctostr('i'), stacks, solution);
	else if (place == 2)
		instruct(ft_ctostr('g'), stacks, solution);
	else
		instruct(ft_ctostr('j'), stacks, solution);
}

/*
**	do_rev_rotate() determines which stack (or both) should
**	receive rev_rotate instructions to move the target value,
**	closer to its intended position.
*/

static	void	do_revrotate(t_stacks **stacks, char **solution, t_pos *target)
{
	if (target->rr_dis > 0 && target->dest_rr_dis > 0)
		instruct(ft_ctostr('k'), stacks, solution);
	else
	{
		if (target->rr_dis == 0)
			instruct(ft_ctostr('j'), stacks, solution);
		else if (target->dest_rr_dis == 0)
			instruct(ft_ctostr('i'), stacks, solution);
		else if (target->rr_dis < target->dest_rr_dis)
			instruct(ft_ctostr('i'), stacks, solution);
		else
			instruct(ft_ctostr('j'), stacks, solution);
	}
}

/*
**	do_rotate() determines which stack (or both) should
**	receive rotate instructions to move the target value,
**	closer to its intended position.
*/

static	void	do_rotate(t_stacks **stacks, char **solution, t_pos *target)
{
	if (target->r_dis > 0 && target->dest_r_dis > 0)
		instruct(ft_ctostr('h'), stacks, solution);
	else
	{
		if (target->r_dis == 0)
			instruct(ft_ctostr('g'), stacks, solution);
		else if (target->dest_r_dis == 0)
			instruct(ft_ctostr('f'), stacks, solution);
		else if (target->r_dis < target->dest_r_dis)
			instruct(ft_ctostr('f'), stacks, solution);
		else
			instruct(ft_ctostr('g'), stacks, solution);
	}
}

/*
**	choose_act_a() tries to find the instruction that, most efficiently,
**	moves the target, provided by choose_target() to the top
**	of the source stack. Paths are further separated into types. For example,
**	a target with path-type 14 or 23 requires different instructions
**	in both stacks, which excludes double instructions.
**	However, targets with path-type 13 or 24 include
**	double rotate/rev-rotate options.
*/

void			choose_act_a(t_stacks **stacks, char **solution, t_pos *target)
{
	if (target->type == 14 || target->type == 23)
		do_diff(stacks, solution, target);
	else if (target->type == 24)
		do_revrotate(stacks, solution, target);
	else
		do_rotate(stacks, solution, target);
}
