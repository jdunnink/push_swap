/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_get_dest_distances.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 15:49:26 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/14 17:02:17 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		find_place_rev(t_list *stack, int value)
{
	int			dis;
	int			highest;
	int			high_dis;
	t_list		*iter;

	dis = 1;
	highest = get_highest(stack, &high_dis);
	if (value > highest)
		return (high_dis);
	iter = stack;
	while (iter->next)
	{
		if (*(int *)iter->content > value &&
			*(int *)iter->next->content < value)
			return (dis);
		else if (*(int *)iter->content > value &&
			*(int *)iter->next->content > value &&
			*(int *)iter->next->content == highest)
			return (dis);
		dis++;
		iter = iter->next;
	}
	return (0);
}

static	int		find_place(t_list *stack, int val, int *low_dis)
{
	int		dis;
	int		highest;
	int		high_dis;
	int		lowest;
	t_list	*iter;

	dis = 1;
	highest = get_highest(stack, &high_dis);
	lowest = get_lowest(stack, low_dis);
	if (val > highest)
		return (high_dis + 1);
	iter = stack;
	while (iter->next)
	{
		if (*(int *)iter->content < val && *(int *)iter->next->content > val)
			return (dis);
		else if (val < *(int *)iter->content &&
			val < *(int *)iter->next->content &&
			*(int *)iter->next->content == lowest)
			return (dis);
		dis++;
		iter = iter->next;
	}
	return (0);
}

void			get_dest_distances(t_list **distances, t_list *stack, char c)
{
	t_list	*iter;
	t_pos	*curr;
	int		low_dis;

	low_dis = 0;
	iter = *distances;
	while (iter)
	{
		curr = (t_pos *)iter->content;
		if (c == 'a')
			curr->dest_r_dis = find_place_rev(stack, curr->value);
		else
			curr->dest_r_dis = find_place(stack, curr->value, &low_dis);
		curr->dest_rr_dis = ft_listlen(stack) - curr->dest_r_dis;
		iter = iter->next;
	}
}
