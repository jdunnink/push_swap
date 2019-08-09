/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_get_k.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/09 12:56:11 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/09 15:36:19 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	determine how sorted a list is and return an average k value. (average diff between curr pos and dest pos)

static 	t_list *ft_lstrev(t_list *list)
{
	t_list *iter;
	t_list *dest;
	int curr;

	iter = list;
	while (iter)
	{
		curr = *(int *)iter->content;
		ft_lstpushfront(&curr, &dest, sizeof(int));
		iter = iter->next;
	}
	return (dest);
}

static t_list *get_sorted(t_list *list)
{
	t_list *dest;

	dest = ft_lstcpy(list);
	dest = ft_lst_mergesort(dest);
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

static 	t_list	*add_indices(t_list *list)
{
	t_list		*iter;
	t_list		*sorted;
	t_index		new;
	t_list		*dest;
	unsigned	i;

	i = 0;
	dest = NULL;
	sorted = get_sorted(list);
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

int 	median_k(t_list *k_values)
{
	t_list	*sorted;
	t_list 	*iter;
	int		median;
	int 	median_k;
	int 	i;
	size_t	len;

	median = 0;
	sorted = get_sorted(k_values);
	len = ft_listlen(sorted);
	median = len / 2;
	i = 0;
	iter = sorted;
	while (iter)
	{
		if (i == median)
		{
			median_k = *(int *)(iter->content);
			printf("	median k: %i\n", median_k);
			return (median_k);
		}
		iter = iter->next;
		i++;
	}
	printf("ERROR\n");
	return (0);
}

int	get_k(t_list *list, char stack)
{
	t_list	*indices;
	t_list	*iter;
	t_list 	*k_values;
	int		i;
	int 	index;
	int 	*curr;
	int 	index_diff;

	printf("\n	get k is called!\n");

	if (stack == 'b')
		list = ft_lstrev(list);

	i = 0;
	index = 0;
	index_diff = 0;
	indices = add_indices(list);
	iter = list;
	k_values = NULL;
	while (iter)
	{
		curr = iter->content;
		index = lookup_index(curr, indices);
		index_diff = index - i;
		if (i > index)
			index_diff *= -1;
//		printf("	calculated index_diff: %i\n", index_diff);
		ft_lstpushfront(&index_diff, &k_values, sizeof(int));
		i++;
		iter = iter->next;
	}
	if (stack == 'b')
		ft_lstdel(&list, &ft_del);
	ft_putchar ('\n');
	return (median_k(k_values));
}