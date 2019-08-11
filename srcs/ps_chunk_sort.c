/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_chunk_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/10 16:00:33 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/11 12:43:21 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list *get_sorted(t_stacks **stacks)
{
	t_list *dest;

	dest = ft_lstcpy((*stacks)->a);
	dest = ft_lst_mergesort(dest);
	return (dest);
}

static 	t_list	*add_indices(t_stacks **stacks)
{
	t_list		*iter;
	t_list		*sorted;
	t_index		new;
	t_list		*dest;
	unsigned	i;

	i = 0;
	dest = NULL;
	sorted = get_sorted(stacks);
	iter = sorted;
	while (iter)
	{
		new.index = i;
		new.nb = *(int *)iter->content;
		ft_lstpushback(&dest, &new, sizeof(t_index));
		i++;
		iter = iter->next;
	}
	ft_lstdel(&sorted, &ft_del);
	return (dest);
}

static 	void	adjust_indices(t_list *indices, int p_rate)
{
	size_t len;
	int	nbs_per_chunk;
	int			i;
	int 		j;
	t_list *iter;
	t_index *curr;

	printf("	adjust indices is called!\n");

	len = ft_listlen(indices);
	nbs_per_chunk = len / p_rate;
	iter = indices;
	i = 0;
	j = nbs_per_chunk;
	while (iter)
	{
		curr = (t_index *)iter->content;
		curr->index = i;
		printf("	setting index of value: %i to %i\n", curr->nb, curr->index);
		j--;
		if (j == 0)
		{
			j = nbs_per_chunk;
			i++;
		}
		iter = iter->next;
	}
}

static int	lookup_index(int *value, t_list *indices)
{
	int	val;
	t_list		*iter;
	t_index 	*curr;

	val = *value;
	iter = indices;
	while (iter)
	{
		curr = iter->content;
		if (val == curr->nb)
			return (curr->index);
		iter = iter->next;
	}
	return (-1);
}

static 	int 	find_next_target(t_list *stack, t_list *indices, int *curr_chunk, int p_rate)
{
	int distance;
	int median;
	size_t len;
	t_list *iter;
	int 	chunk_nb;
	int 	eval;
	int 	lowest;
	int		trig;

	lowest = INT32_MAX;
	distance = 0;
	len = ft_listlen(stack);
	median = len / 2;
	iter = stack;
	trig = 0;
	while (iter)
	{
		chunk_nb = lookup_index((int *)iter->content, indices);
		if (chunk_nb == *curr_chunk)
		{
			printf("	value: %i, a member of chunk %i was found at absolute distance: %i\n", *(int *)iter->content, *curr_chunk, distance);
			if (distance > median)
			{
				eval = (int)len - distance;
				trig = eval;
				printf("		absolute distance %i is higher than median %i, calculating real distance: %i\n", distance, median, (int)len - distance);
			}
			else
				eval = distance;
			if (eval < lowest)
			{
				lowest = eval;
				printf("	a new lowest distance has been set at %i\n", eval);
			}
		}
		distance++;
		iter = iter->next;
		if (iter == NULL && lowest == INT32_MAX)
		{
			printf("	no members of current chunk number: %i, moving to next chunk: %i\n", *curr_chunk, (*curr_chunk) + 1);
			(*curr_chunk)++;
			if (*curr_chunk > p_rate)
				return (INT32_MAX);
			iter = stack;
			distance = 0;
		}
		
	}
	if (trig == lowest)
		lowest *= -1;
	printf("	target was found at: %i\n", lowest);
	return (lowest);
}

static	t_list	*update_indices(t_stacks **stacks, t_list **indices)
{
	t_list		*new;
	t_list		*iter;
	t_index 	*curr;

	printf("	update indices is called!\n");

	if (!(*stacks)->a)
		return (*indices);

	new = add_indices(stacks);
	iter = new;
	while (iter)
	{
		curr = iter->content;
		curr->index = lookup_index(&(curr->nb), *indices);
		printf(" the index of value %i has been set at %i\n", curr->nb, curr->index);
		iter = iter->next;
	}
	ft_lstdel(indices, &ft_del);
	return (new);
}

static 	void	push_swap(t_stacks **stacks, char **solution, char which)
{
	int top;
	int next;
	
	if (which == 'b')
	{
		instruct(ft_ctostr('b'), stacks, solution);
		if (ft_listlen((*stacks)->b) > 1)
		{
			top = *(int *)(*stacks)->b->content;
			next = *(int *)(*stacks)->b->next->content;
			if (next > top)
				instruct(ft_ctostr('d'), stacks, solution);
		}
	}
	else if (which == 'a')
	{
		instruct(ft_ctostr('a'), stacks, solution);
		if (ft_listlen((*stacks)->a) > 1)
		{
			top = *(int *)(*stacks)->a->content;
			next = *(int *)(*stacks)->a->next->content;
			if (next > top)
				instruct(ft_ctostr('c'), stacks, solution);
		}
	}
}

char	*chunk_sort(t_stacks **stacks, int p_rate)				// p_rate == partition rate (how many chunks?)
{
	t_list	*indices;
	t_list	*iter;
	char 	*solution;
	int 	curr_chunk;
	int 	distance;

	solution = NULL;
	indices = add_indices(stacks);
	adjust_indices(indices, p_rate);
	curr_chunk = 0;
	iter = (*stacks)->a;
	while ((*stacks)->a)									//	 while stack A is not empty
	{
		distance = find_next_target((*stacks)->a, indices, &curr_chunk, p_rate);	//	find the next number to push
		if (distance == INT32_MAX)
			break ;
		if (distance == 0)													//	if number is at the top,
			push_swap(stacks, &solution, 'b');
		else if (distance > 0)												//	if the number is in the top half of the stack,
		{
			while (distance > 0)
			{
				instruct(ft_ctostr('f'), stacks, &solution);				//		rotate until number is at the top
				distance--;
			}
			push_swap(stacks, &solution, 'b');
		}
		else if (distance < 0)												//  if the number is in the bottom half of the stack,
		{
			while (distance < 0)
			{
				instruct(ft_ctostr('i'), stacks, &solution);				//		rev_rotate until number is at the top
				distance++;
			}
			push_swap(stacks, &solution, 'b');
		}
		indices = update_indices(stacks, &indices);
	}
	return (solution);									// return partial solution
}