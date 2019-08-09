
#include "push_swap.h"

static	int		find_highest(t_list *stack_b)
{
	int highest;
	t_list *iter;
	int	cmp;

	highest = *(int *)stack_b->content;
	iter = stack_b->next;
	while (iter)
	{
		if (*(int *)iter->content > highest)
			highest = *(int *)iter->content;
		iter = iter->next;
	}
	return (highest);
}

char	*insertion_sort(t_stacks **stacks)
{
	char	*solution;
	int		curr;
	int		next;
	int		last;
	int		curr_b;
	int 	highest;

	highest = find_highest((*stacks)->a);
	solution = NULL;
	while (check_sort((*stacks)->a) == 0 || (*stacks)->b)
	{
		curr = *(int *)(*stacks)->a->content;
		next = *(int *)(*stacks)->a->next->content;
		if ((*stacks)->b)
		{
			curr_b = *(int *)(*stacks)->b->content;
			if (curr_b < curr && curr_b > last)
			{
				instruct(ft_ctostr('a'), stacks, &solution);
				continue ;
			}
		}
		if (curr > next && curr != highest)
		{
			curr_b = curr;
			instruct(ft_strdup("bi"), stacks, &solution);
		}
		else
		{
			last = curr;
			instruct(ft_ctostr('f'), stacks, &solution);
		}
	}
	return (solution);
}