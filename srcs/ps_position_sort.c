
/*

input list: 4 2 7 8 5 3 1 9 0 6

sort the input list and attach index numbers using the following struct:

typedef struct s_index
{
	int nb;
	int index;
}

current position == 0

while (stack->a)
{
	if (index of number > current position)
		rotate_a
	else if (index of number < current position)
		push_b
	current_position++;
}

while (stack->b)
{
	if (index of number < current position)
		rotate_b
	else if (index of number < current position)
		push_a
}

*/

typedef struct s_index
{
	int nb;
	int index;
}				t_index;

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

static 	void	print_list(t_list *list)
{
	t_list	*iter;
	int		*curr;

	printf("	print_list is called!\n");

	iter = list;
	while (iter)
	{
		curr = iter->content;
		printf("	current nbr: %i\n", *curr);
		iter = iter->next;
	}
}

static 	void	print_indices(t_list *indices)
{
	t_list *iter;
	t_index *curr;

	printf("	print_indices is called!\n");

	iter = indices;
	while (iter)
	{
		curr = iter->content;
		printf("	current nbr: %i // index: %i\n", curr->nb, curr->index);
		iter = iter->next;
	}
}

/*
**	LOOKUP INDEX
*/

char 	*position_sort(t_stacks **stacks)
{
	t_list *indices;
	indices = add_indices(stacks);
	unsigned int	curr_pos;
	unsigned int	curr_index;

	curr_pos = 0;
	while ((*stacks)->a)
	{
		curr_index = lookup_index((*stacks)->a->content, indices);
		if (curr_index < curr_pos)
			// push_b
		else
			// rotate_a
	}


	return (NULL);
}
