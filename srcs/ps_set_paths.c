/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_set_paths.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 15:26:48 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/14 16:46:15 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		check_overlap(int curr, int dest, int path)
{
	int base;

	base = 0;
	if (curr == 0 || dest == 0)
		return (path);
	while (curr > 0 && dest > 0)
	{
		base++;
		curr--;
		dest--;
	}
	return (path - base);
}

static	void	set_type(int short_dest, int short_curr, t_pos *curr)
{
	if (short_dest == curr->dest_rr_dis && short_curr == curr->rr_dis)
		curr->type = 24;
	else if (short_dest == curr->dest_r_dis && short_curr == curr->r_dis)
		curr->type = 13;
	else if (short_dest == curr->dest_r_dis && short_curr == curr->rr_dis)
		curr->type = 23;
	else
		curr->type = 14;
}

void			set_paths(t_list **distances)
{
	t_list	*iter;
	t_pos	*curr;
	int		short_curr;
	int		short_dest;

	iter = *distances;
	while (iter)
	{
		curr = (t_pos *)iter->content;
		if (curr->r_dis < curr->rr_dis)
			short_curr = curr->r_dis;
		else
			short_curr = curr->rr_dis;
		if (curr->dest_r_dis < curr->dest_rr_dis)
			short_dest = curr->dest_r_dis;
		else
			short_dest = curr->dest_rr_dis;
		set_type(short_dest, short_curr, curr);
		curr->path = short_curr + short_dest;
		if (curr->type == 13 || curr->type == 24)
			curr->path = check_overlap(short_curr, short_dest, curr->path);
		iter = iter->next;
	}
}
