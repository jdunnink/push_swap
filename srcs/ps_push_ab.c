/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_push_ab.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:51:21 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/24 16:47:53 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	char	*choose_swap(t_stacks **stacks)
{
	int b_curr;
	int b_next;

	if (ft_listlen((*stacks)->b) < 2)
		return (ft_ctostr('c'));
	b_curr = *(int *)(*stacks)->b->content;
	b_next = *(int *)(*stacks)->b->next->content;
	if (b_curr < b_next)
		return (ft_ctostr('e'));
	return (ft_ctostr('c'));
}

static	char	*choose_rotate(t_stacks **stacks)
{
	int		b_last;
	int		b_curr;
	t_list	*iter;

	if (ft_listlen((*stacks)->b) < 2)
		return (ft_ctostr('f'));
	iter = (*stacks)->b;
	while (iter->next)
		iter = iter->next;
	b_last = *(int *)iter->content;
	b_curr = *(int *)(*stacks)->b->content;
	if (b_curr < b_last)
		return (ft_ctostr('h'));
	return (ft_ctostr('f'));
}

static	char	*choose_next(t_stacks **stacks)
{
	int		curr;
	int		next_next;
	t_list *iter;

	if (ft_listlen((*stacks)->a) < 4)
		return (choose_swap(stacks));
	curr = *(int *)(*stacks)->a->content;
	iter = (*stacks)->a->next;
	iter = iter->next;
	next_next = *(int *)iter->content;
	if (curr < next_next)
		return (choose_swap(stacks));
	return (choose_rotate(stacks));
} 

static	char	*choose_last(t_stacks **stacks)
{
	int		b_last;
	int		b_curr;
	t_list	*iter;

	if (ft_listlen((*stacks)->b) < 2)
		return (ft_ctostr('i'));
	iter = (*stacks)->b;
	while (iter->next)
		iter = iter->next;
	b_last = *(int *)iter->content;
	b_curr = *(int *)(*stacks)->b->content;
	if (b_last > b_curr)
		return (ft_ctostr('k'));
	return (ft_ctostr('i'));
}

static	char	*choose_three(t_stacks **stacks)
{
	int curr;
	int next;
	int last;
	t_list *iter;

	iter = (*stacks)->a;
	while (iter->next)
		iter = iter->next;
	curr = *(int *)(*stacks)->a->content;
	next = *(int *)(*stacks)->a->next->content;
	last = *(int *)iter->content;		
	if (last < curr && last < next)
		return (choose_last(stacks));
	else if (next < curr && next < last)
		return (choose_next(stacks));
	return (ft_ctostr('b'));
}

static	char	*choose_two(t_stacks **stacks)
{
	int curr;
	int next;

	curr = *(int *)(*stacks)->a->content;
	next = *(int *)(*stacks)->a->next->content;
	if (curr <= next)
		return (ft_ctostr('b'));
	return (choose_swap(stacks));
}

char	*push_ab(t_stacks **stacks, int *direction)
{
	int		b_curr;
	int		b_next;
	int		b_last;
	int		b_next_next;
	t_list	*iter;

	if (ft_listlen((*stacks)->b) > 1)
	{
		b_curr = *(int *)(*stacks)->b->content;
		b_next = *(int *)(*stacks)->b->next->content;
		iter = (*stacks)->b;
		while (iter->next)
			iter = iter->next;
		b_last = *(int *)iter->content;
		if (b_curr < b_last && ft_listlen((*stacks)->b) > 2)
			return (ft_ctostr('g'));		//	check for double rotate here
		if (b_curr < b_next && ft_listlen((*stacks)->b) <= 3)
			return (ft_ctostr('d'));		//	also check for double swap here
		if (b_curr < b_next && ft_listlen((*stacks)->b) > 3)
		{
			iter = (*stacks)->b->next;
			iter = iter->next;
			if (iter)
			{
				b_next_next = *(int *)iter->content;
				if (b_curr > b_next_next)
					return (ft_ctostr('d'));
				else
					return (ft_ctostr('g'));
			}
		}
	}
	if (check_sort((*stacks)->a) == 0)
	{
		if (ft_listlen((*stacks)->a) >= 3)
			return (choose_three(stacks));
		else if (ft_listlen((*stacks)->a) == 2)
			return (choose_two(stacks));
	}
	*direction = 1;
	return (NULL);
}