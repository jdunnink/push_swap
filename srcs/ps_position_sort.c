
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
	//	FREE SORTED
	return (dest);
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

char 	*position_sort(t_stacks **stacks, double precision)
{
	t_list			*indices;
	char			*solution;
	int	curr_pos;
	int	curr_index;
	int range_limit;

	range_limit = ft_listlen((*stacks)->a) * precision;
	indices = add_indices(stacks);
	curr_pos = 0;
	solution = NULL;
	while ((*stacks)->a)
	{
		curr_index = lookup_index((*stacks)->a->content, indices);
		if (curr_index <= curr_pos + range_limit && curr_index >= curr_pos - range_limit)
		{
			instruct(ft_ctostr('b'), stacks, &solution);
			curr_pos++;
		}
		else if (curr_index < curr_pos)
		{
			instruct(ft_strdup("bg"), stacks, &solution);
		}
		else
			instruct(ft_ctostr('f'), stacks, &solution);
	}
	return (solution);
}
