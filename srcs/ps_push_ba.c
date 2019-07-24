/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_push_ba.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:51:21 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/24 15:30:26 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	char	*choose_swap(t_stacks **stacks)
{
	int a_curr;
	int a_next;

	if (ft_listlen((*stacks)->a) < 2)
		return (ft_ctostr('d'));
	a_curr = *(int *)(*stacks)->a->content;
	a_next = *(int *)(*stacks)->a->next->content;
	if (a_curr > a_next)
		return (ft_ctostr('e'));
	return (ft_ctostr('d'));
}

static	char	*choose_rotate(t_stacks **stacks)
{
	int		a_last;
	int		a_curr;
	t_list	*iter;

	if (ft_listlen((*stacks)->a) < 2)
		return (ft_ctostr('g'));
	iter = (*stacks)->a;
	while (iter->next)
		iter = iter->next;
	a_last = *(int *)iter->content;
	a_curr = *(int *)(*stacks)->a->content;
	if (a_curr > a_last)
		return (ft_ctostr('h'));
	return (ft_ctostr('g'));
}

static	char	*choose_next(t_stacks **stacks)
{
	int		curr;
	int		next_next;
	t_list *iter;

	if (ft_listlen((*stacks)->b) < 4)
		return (choose_swap(stacks));
	curr = *(int *)(*stacks)->b->content;
	iter = (*stacks)->b->next;
	iter = iter->next;
	next_next = *(int *)iter->content;
	if (curr >= next_next)
		return (choose_swap(stacks));
	return (choose_rotate(stacks));
} 

static	char	*choose_last(t_stacks **stacks)
{
	int		a_last;
	int		a_curr;
	t_list	*iter;

	if (ft_listlen((*stacks)->a) < 2)
		return (ft_ctostr('j'));
	iter = (*stacks)->a;
	while (iter->next)
		iter = iter->next;
	a_last = *(int *)iter->content;
	a_curr = *(int *)(*stacks)->a->content;
	if (a_last < a_curr)
		return (ft_ctostr('k'));
	return (ft_ctostr('j'));
}

static	char	*choose_three(t_stacks **stacks)
{
	int curr;
	int next;
	int last;
	t_list *iter;

	iter = (*stacks)->b;
	while (iter->next)
		iter = iter->next;
	curr = *(int *)(*stacks)->b->content;
	next = *(int *)(*stacks)->b->next->content;
	last = *(int *)iter->content;		
	if (last > curr && last > next)
		return (choose_last(stacks));
	else if (next > curr && next > last)
		return (choose_next(stacks));
	return (ft_ctostr('a'));
}

static	char	*choose_two(t_stacks **stacks)
{
	int curr;
	int next;

	curr = *(int *)(*stacks)->b->content;
	next = *(int *)(*stacks)->b->next->content;
	if (curr >= next)
		return (ft_ctostr('a'));
	return (choose_swap(stacks));
}

char	*push_ba(t_stacks **stacks, int *direction)
{
	int		a_curr;
	int		a_next;
	int		a_last;
	t_list	*iter;

	if (ft_listlen((*stacks)->a) > 1)
	{
		a_curr = *(int *)(*stacks)->a->content;
		a_next = *(int *)(*stacks)->a->next->content;
		iter = (*stacks)->a;
		while (iter->next)
			iter = iter->next;
		a_last = *(int *)iter->content;
		if (a_curr > a_last && ft_listlen((*stacks)->b) > 2)
			return (ft_ctostr('f'));		//	check for double rotate here
		if (a_curr > a_next)
			return (ft_ctostr('c'));		//	also check for double swap here
	}
	if (check_rev_sort((*stacks)->b) == 0)
	{
		if (ft_listlen((*stacks)->b) >= 3)
			return (choose_three(stacks));
		else if (ft_listlen((*stacks)->b) == 2)
			return (choose_two(stacks));
	}
	*direction = 0;
	return (NULL);
}