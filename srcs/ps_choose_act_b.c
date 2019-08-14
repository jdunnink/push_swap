/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_choose_act_b.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 16:01:33 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/14 17:27:56 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	do_diff(t_stacks **stacks, char **solution, t_pos *target)
{
	int place;

	place = find_sh(target);
	if (place == 0)
		instruct(ft_ctostr('g'), stacks, solution);
	else if (place == 1)
		instruct(ft_ctostr('j'), stacks, solution);
	else if (place == 2)
		instruct(ft_ctostr('f'), stacks, solution);
	else
		instruct(ft_ctostr('i'), stacks, solution);
}

static	void	do_revrotate(t_stacks **stacks, char **solution, t_pos *target)
{
	if (target->rr_dis > 0 && target->dest_rr_dis > 0)
		instruct(ft_ctostr('k'), stacks, solution);
	else
	{
		if (target->rr_dis == 0)
			instruct(ft_ctostr('i'), stacks, solution);
		else if (target->dest_rr_dis == 0)
			instruct(ft_ctostr('j'), stacks, solution);
		else if (target->rr_dis < target->dest_rr_dis)
			instruct(ft_ctostr('j'), stacks, solution);
		else
			instruct(ft_ctostr('i'), stacks, solution);
	}
}

static	void	do_rotate(t_stacks **stacks, char **solution, t_pos *target)
{
	if (target->r_dis > 0 && target->dest_r_dis > 0)
		instruct(ft_ctostr('h'), stacks, solution);
	else
	{
		if (target->r_dis == 0)
			instruct(ft_ctostr('f'), stacks, solution);
		else if (target->dest_r_dis == 0)
			instruct(ft_ctostr('g'), stacks, solution);
		else if (target->r_dis < target->dest_r_dis)
			instruct(ft_ctostr('g'), stacks, solution);
		else
			instruct(ft_ctostr('f'), stacks, solution);
	}
}

void			choose_act_b(t_stacks **stacks, char **solution, t_pos *target)
{
	if (target->type == 14 || target->type == 23)
		do_diff(stacks, solution, target);
	else if (target->type == 24)
		do_revrotate(stacks, solution, target);
	else
		do_rotate(stacks, solution, target);
}
