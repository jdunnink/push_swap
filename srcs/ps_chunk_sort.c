/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_chunk_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/10 16:00:33 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/11 18:17:48 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static 	t_list *ft_lstrev(t_list *list)
{
	t_list *iter;
	t_list *dest;
	int curr;

	dest = NULL;
	iter = list;
	while (iter)
	{
		curr = *(int *)iter->content;
		ft_lstpushfront(&curr, &dest, sizeof(int));
		iter = iter->next;
	}
	ft_lstdel(&list, &ft_del);
	return (dest);
}

static t_list *get_rev_sorted(t_stacks **stacks)
{
	t_list *dest;

	dest = ft_lstcpy((*stacks)->b);
	dest = ft_lst_mergesort(dest);
	dest = ft_lstrev(dest);
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
	sorted = get_rev_sorted(stacks);
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

	len = ft_listlen(indices);
	nbs_per_chunk = len / p_rate;
	iter = indices;
	i = 0;
	j = nbs_per_chunk;
	while (iter)
	{
		curr = (t_index *)iter->content;
		curr->index = i;
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
			if (distance > median)
			{
				eval = (int)len - distance;
				trig = eval;
			}
			else
				eval = distance;
			if (eval < lowest)
				lowest = eval;
		}
		distance++;
		iter = iter->next;
		if (iter == NULL && lowest == INT32_MAX)
		{
			(*curr_chunk)++;
			if (*curr_chunk > p_rate)
				return (INT32_MAX);
			iter = stack;
			distance = 0;
		}
		
	}
	if (trig == lowest)
		lowest *= -1;
	return (lowest);
}

static	t_list	*update_indices(t_stacks **stacks, t_list **indices)
{
	t_list		*new;
	t_list		*iter;
	t_index 	*curr;

	if (!(*stacks)->b)
		return (*indices);

	new = add_indices(stacks);
	iter = new;
	while (iter)
	{
		curr = iter->content;
		curr->index = lookup_index(&(curr->nb), *indices);
		iter = iter->next;
	}
	ft_lstdel(indices, &ft_del);
	return (new);
}

char	*chunk_sort(t_stacks **stacks, int p_rate)
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
	iter = (*stacks)->b;
	while ((*stacks)->b)
	{
		distance = find_next_target((*stacks)->b, indices, &curr_chunk, p_rate);
		if (distance == INT32_MAX)
			break ;
		if (distance == 0)
			instruct(ft_ctostr('a'), stacks, &solution);
		else if (distance > 0)
		{
			while (distance > 0)
			{
				instruct(ft_ctostr('g'), stacks, &solution);
				distance--;
			}
			instruct(ft_ctostr('a'), stacks, &solution);
		}
		else if (distance < 0)
		{
			while (distance < 0)
			{
				instruct(ft_ctostr('j'), stacks, &solution);
				distance++;
			}
			instruct(ft_ctostr('a'), stacks, &solution);
		}
		indices = update_indices(stacks, &indices);
	}
	return (solution);
}