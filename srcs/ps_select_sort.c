/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_select_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 10:41:54 by jdunnink       #+#    #+#                */
/*   Updated: 2019/10/22 13:06:54 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	choose_next moves the next value in the active stack
**	to the top.
*/

static	void	choose_next(t_stacks **stacks, char **solution, char c)
{
	int			top;
	int			next_next;
	t_list		*iter;

	if (c == 'a')
		iter = (*stacks)->a;
	else
		iter = (*stacks)->b;
	top = *(int *)iter->content;
	next_next = *(int *)iter->next->next->content;
	if (top < next_next && c == 'a')
		instruct(ft_ctostr('c'), stacks, solution);
	else if (top < next_next && c == 'b')
		instruct(ft_ctostr('d'), stacks, solution);
	else if (top > next_next && c == 'a')
		instruct(ft_ctostr('f'), stacks, solution);
	else
		instruct(ft_ctostr('g'), stacks, solution);
}

/*
**	choose_last() moves the last value in the active stack
**	to the top.
*/

static	void	choose_last(t_stacks **stacks, char **solution, char c)
{
	if (c == 'a')
		instruct(ft_ctostr('i'), stacks, solution);
	else
		instruct(ft_ctostr('j'), stacks, solution);
}

/*
**	choose_two() compares two values (top and next) in a stack,
**	and determines which value is best to push.
**	This function is used when a listsize has dropped below 3.
*/

static	void	choose_two(t_stacks **stacks, char **solution, char c)
{
	int			top;
	int			next;
	t_list		*iter;

	if (c == 'a')
		iter = (*stacks)->a;
	else
		iter = (*stacks)->b;
	top = *(int *)iter->content;
	next = *(int *)iter->next->content;
	if (top < next && c == 'a')
		instruct(ft_ctostr('b'), stacks, solution);
	else if (top < next && c == 'b')
		instruct(ft_ctostr('a'), stacks, solution);
	else if (next < top && c == 'a')
		instruct(ft_ctostr('f'), stacks, solution);
	else
		instruct(ft_ctostr('g'), stacks, solution);
}

/*
**	choose_three() compares three values in a stack, and determines
**	which value would be best to push to the other stack. If the top
**	value is the best, it is handled directly using instruct(),
**	otherwise, choose_next() or choose_last() is called to determine
**	another course of action.
*/

static void		choose_three(t_stacks **stacks, char **solution, char c)
{
	int			top;
	int			next;
	int			last;
	t_list		*iter;

	if (c == 'a')
		iter = (*stacks)->a;
	else
		iter = (*stacks)->b;
	top = *(int *)iter->content;
	next = *(int *)iter->next->content;
	while (iter->next)
		iter = iter->next;
	last = *(int *)iter->content;
	if (top < last && top < next && c == 'a')
		instruct(ft_ctostr('b'), stacks, solution);
	else if (top < last && top < next && c == 'b')
		instruct(ft_ctostr('a'), stacks, solution);
	else if (next < top && next < last)
		choose_next(stacks, solution, c);
	else
		choose_last(stacks, solution, c);
}

/*
**	select_sort() tries to solve the stacks by comparing values that
**	can be pushed to the other stack within two moves -> these values are
**	top, next and last. By comparing these values, a short range selection_sort
**	is made, which works well for small list sizes. At first, the lowest value
**	in stack A is moved to the top. Then the algorithm chooses if
**	it should compare two or three values (choose__three / choose_two).
**	after all values values have been pushed to stack B, or stack A is sorted,
**	values are pushed back into stack A using insertion_sort (choose_insert).
*/

char			*select_sort(t_stacks **stacks)
{
	char *solution;

	solution = NULL;
	move_to_lowest(stacks, &solution);
	while (check_sort((*stacks)->a) == 0)
	{
		if (ft_listlen((*stacks)->a) > 2)
			choose_three(stacks, &solution, 'a');
		else
			choose_two(stacks, &solution, 'a');
	}
	while (ft_listlen((*stacks)->b) > 0)
		choose_insert(stacks, &solution);
	return (solution);
}
