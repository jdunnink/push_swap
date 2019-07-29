/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_selection_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/29 13:01:34 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/29 15:48:30 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	char	*adjust_target(t_stacks **stacks, char **solution, int *direction)
{
	t_list	*target;
	int		curr;
	int 	next;
	int		next_next;

	if (*direction == -1)
		target = (*stacks)->b;
	else
		target = (*stacks)->a;

	if (ft_listlen(target) <= 1)
		return (NULL);
	curr = *(int *)

	
} 

static 	char 	*choose_rev_rotate(t_stacks **stacks, char **solution, int *direction)
{
	if (*direction == -1)
		instruct(ft_ctostr('i'), stacks, solution);		// rev rotate a
	else
	instruct(ft_ctostr('j'), stacks, solution);			// rev rotate b
	return (*solution);
}

static 	char 	*choose_rotate(t_stacks **stacks, char **solution, int *direction)
{
	int top_o;				// the top of the other stack
	int last_o;				// the next of the other stack
	t_list *iter;

	printf("	choose_rotate is called!\n");

	if (*direction == -1)
		iter = (*stacks)->b;
	else
		iter = (*stacks)->a;
	top_o = *(int *)iter->content;
	while (iter->next)
		iter = iter->next;
	last_o = *(int *)iter->content;
	if (top_o <= last_o && *direction == -1)
		instruct(ft_ctostr('h'), stacks, solution);			// rotate both
	else if (top_o >= last_o && *direction == 1)
		instruct(ft_ctostr('h'), stacks, solution);			// rotate both
	else if(*direction == -1)
		instruct(ft_ctostr('f'), stacks, solution);			// rotate a
	else
		instruct(ft_ctostr('g'), stacks, solution);				// rotate b
	return (*solution);
} 

static 	char 	*choose_swap(t_stacks **stacks, char **solution, int *direction)
{
	int top_o;				// the top of the other stack
	int next_o;				// the next of the other stack
	t_list *iter;

	printf("	choose_swap is called!\n");

	if (*direction == -1)
		iter = (*stacks)->b;
	else
		iter = (*stacks)->a;

	if (ft_listlen(iter) <= 1)
	{
		if (*direction == -1)
			instruct(ft_ctostr('c'), stacks, solution);		// swap stack a
		else
			instruct(ft_ctostr('d'), stacks, solution);			// swap stack b
		return (*solution);
	}

	top_o = *(int *)iter->content;
	next_o = *(int *)iter->next->content;
	printf("	direction == %i\n ", *direction);
	if (next_o > top_o && *direction == -1)
		instruct(ft_ctostr('e'), stacks, solution);		// swap both stacks
	else if (next_o < top_o && *direction == 1)
		instruct(ft_ctostr('e'), stacks, solution);		// swap both stacks
	else if (*direction == -1)
		instruct(ft_ctostr('c'), stacks, solution);		// swap stack a
	else 
		instruct(ft_ctostr('d'), stacks, solution);			// swap stack b
	return (*solution);
}

//	push the top int into the other stack, change direction if the src list is empty after pushing.

static	char	*choose_curr(t_stacks **stacks, char **solution, int *direction)
{
	printf("	choose_curr is called!\n");

	if (*direction == -1)
		instruct(ft_ctostr('b'), stacks, solution);					// push into b
	else
		instruct(ft_ctostr('a'), stacks, solution);					// push into  a
	if (*direction == -1 && ft_listlen((*stacks)->a) == 0)
	{
		printf("	direction is flipped !\n");
		*direction = 1;												// change direction from A -> B to A <- B
	}
	else if (*direction == 1 && ft_listlen((*stacks)->b) == 0)
	{
		printf("	direction is flipped !\n");
		*direction = -1;												// change direction from A <- B to A -> B
	}
	return (*solution);
}

//	move the next value to the top of the active stack using either swap/rotate/rev_rotate

static	char	*choose_next(t_stacks **stacks, char **solution, int *direction)
{
	int curr;
	int next_next;
	t_list *iter;

	printf("	choose_next is called!\n");

	if (*direction == -1)
		iter = (*stacks)->a;
	else
		iter = (*stacks)->b;
	curr = *(int *)iter->content;
	if (ft_listlen(iter) == 2)
		return (choose_swap(stacks, solution, direction));			// choose swap or swapswap
	iter = iter->next;
	next_next = *(int *)iter->next->content;
	if (*direction == -1)
	{
		if (curr <= next_next)								
			return (choose_swap(stacks, solution, direction));			// choose swap or swapswap
		return (choose_rotate(stacks, solution, direction));			// choose rotate or rotate/rotate
	}
	else 
	{
		if (curr >= next_next)								
			return (choose_swap(stacks, solution, direction));			// choose swap or swapswap
		return (choose_rotate(stacks, solution, direction));			// choose rotate or rotate/rotate
	}
}

//	when listlen == 2, choose the lowest value and either push or move to top using swap/rotate/rev_rotate

static	char	*choose_two(t_stacks **stacks, char **solution, int *direction)
{
	int		curr;
	int		next;
	t_list	*iter;

	printf("	choose_two is called!\n");

	if (*direction == -1)
		iter = (*stacks)->a;
	else
		iter = (*stacks)->b;
	curr = *(int *)iter->content;
	next = *(int *)iter->next->content;
	if (*direction == -1)
	{
		if (curr <= next)
			return (choose_curr(stacks, solution, direction));		// push the top of the stack into the other stack
		else
			return (choose_next(stacks, solution, direction));		// move the next value to the top of the active stack
	}
	else
	{
		if (curr >= next)
			return (choose_curr(stacks, solution, direction));		// push the top of the stack into the other stack
		else
			return (choose_next(stacks, solution, direction));		// move the next value to the top of the active stack
	}
}

//	when listlen is >= 3, choose the lowest value and either push or move to top using swap/rotate/rev_rotate

static	char	*choose_three(t_stacks **stacks, char **solution, int *direction)
{
	int	curr;
	int next;
	int last;
	t_list *iter;

	printf("	choose_three is called!\n");

	if (*direction == -1)
		iter = (*stacks)->a;
	else
		iter = (*stacks)->b;
	curr = *(int *)iter->content;
	next = *(int *)iter->next->content;
	while (iter->next)
		iter = iter->next;
	last = *(int *)iter->content;
	if (*direction == -1)
	{
		if (curr <= next && curr <= last)
			return (choose_curr(stacks, solution, direction));		// push the top of the stack into the other stack
		else if (next < last && next < curr)
			return (choose_next(stacks, solution, direction));		// move the next value to the top of the active stack
		else
			return (choose_rev_rotate(stacks, solution, direction));	// move the last value to the top of the active stack
	}
	else
	{
		if (curr >= next && curr >= last)
			return (choose_curr(stacks, solution, direction));		// push the top of the stack into the other stack
		else if (next > last && next > curr)
			return (choose_next(stacks, solution, direction));		// move the next value to the top of the active stack
		else
			return (choose_rev_rotate(stacks, solution, direction));	// move the last value to the top of the active stack
	}
}

// based on the size of the list, choose between pushing the first, next or last value

static	char	*select_push(t_stacks **stacks, char **solution, int *direction)
{
	t_list	*iter;
	char	*last_instr;

	printf("select_push is called1! \n");

	if (*solution != NULL)
	{
		last_instr = ft_str_tail(*solution);
		if (*last_instr == 'a' || *last_instr == 'b')				// if the previous instruction was a push
		{
			if (adjust_target(stacks, solution, direction) != NULL)
				return (*solution);										// order the just pushed element
		}
	}
	if (*direction == -1)
		iter = (*stacks)->a;
	else
		iter = (*stacks)->b;
	if (ft_listlen(iter) == 1)
		return (choose_curr(stacks, solution, direction));		// push the top of the stack into the other stack
	else if (ft_listlen(iter) >= 3)
		return (choose_three(stacks, solution, direction));		// choose between three values
	return (choose_two(stacks, solution, direction));			// choose between two values
}

//	sort the given stacks using selection sort

char	*selection_sort(t_stacks **stacks)
{
	char	*solution;
	int 	direction;

	solution = NULL;
	direction = -1;
	while (check_sort((*stacks)->a) == 0 || check_rev_sort((*stacks)->b) == 0)
	{
		solution = select_push(stacks, &solution, &direction);	// select a course of action
	}
	return (solution);
}