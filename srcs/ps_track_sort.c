/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_track_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:51:21 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/23 21:06:09 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*select_push_down(t_stacks	**stacks)
{
	char	*solution;
	int		*val;
	int		*next;

	if (ft_listlen((*stacks)->a) <  2)
		return (NULL);
	val = (int *)(*stacks)->a->content;
	next = (int *)(*stacks)->a->next->content;
	if (*val <= *next)
		solution = ft_ctostr('b');
	else
	{
		if (ft_listlen((*stacks)->b) > 1)
		{
			val = (int *)(*stacks)->b->content;
			next = (int *)(*stacks)->b->next->content;
			if (*val <= *next)
				solution = ft_ctostr('e');
			else
				solution = ft_ctostr('c');
		}
		else
			solution = ft_ctostr('c');
	}
	return (solution);
}

char	*select_push_up(t_stacks	**stacks)
{
	char	*solution;
	int		*val;
	int		*next;

	if (ft_listlen((*stacks)->b) <  2)
		return (NULL);
	val = (int *)(*stacks)->b->content;
	next = (int *)(*stacks)->b->next->content;
	if (*val >= *next)
		solution = ft_ctostr('a');
	else
	{
		if (ft_listlen((*stacks)->a) > 1)
		{
			val = (int *)(*stacks)->a->content;
			next = (int *)(*stacks)->a->next->content;
			if (*val >= *next)
				solution = ft_ctostr('e');
			else
				solution = ft_ctostr('d');
		}
		else
			solution = ft_ctostr('d');
	}
	return (solution);
}

char	*zigzag_sort(t_stacks **stacks)
{
	char		*solution;
	char		*next_instr;

	solution = NULL;
	while (ft_listlen((*stacks)->a) > 1)
	{
		next_instr = select_push_down(stacks);
		if (try_solution(next_instr, stacks) == 1)
			break ;
		solution = ft_stradd(solution, next_instr);
	}
	while (ft_listlen((*stacks)->b) > 1)
	{
		next_instr = select_push_up(stacks);
		if (try_solution(next_instr, stacks) == 1)
			break ;
		solution = ft_stradd(solution, next_instr);
	}
	return (solution);
}

char	*track_sort(t_stacks **stacks)
{
	char *solution;

	solution = NULL;
	while (check_sort((*stacks)->a) == 0)
		solution = ft_stradd(solution ,zigzag_sort(stacks));
	push_a(stacks);
	solution = ft_stradd(solution, ft_ctostr('a'));
	return (solution);
}