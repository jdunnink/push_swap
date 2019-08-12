/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_mergesort.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/07 14:50:01 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 08:11:43 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_listlen(t_list *list)
{
	size_t i;
	t_list *iter;

	i = 0;
	iter = list;
	while (iter)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}

static	void	list_split(t_list **one, t_list **two, size_t len, t_list **v)
{
	unsigned int	i;
	t_list			*trail;

	i = 0;
	*one = *v;
	while (i < len / 2)
	{
		trail = *v;
		*v = (*v)->next;
		i++;
	}
	trail->next = NULL;
	*two = *v;
}

static t_list	*push(t_list *list, t_list **new, unsigned *i)
{
	t_list	*dest;
	t_list	*iter;

	(*i)++;
	if (list == NULL)
	{
		dest = *new;
		*new = (*new)->next;
		dest->next = NULL;
		return (dest);
	}
	iter = list;
	while (iter->next)
		iter = iter->next;
	iter->next = *new;
	*new = (*new)->next;
	iter = iter->next;
	iter->next = NULL;
	dest = list;
	return (dest);
}

static	t_list	*merge(t_list *one, t_list *two, int *cmp_one, int *cmp_two)
{
	t_list		*dest;
	size_t		dest_len;
	unsigned	i;

	i = 0;
	dest = NULL;
	dest_len = get_listlen(one) + get_listlen(two);
	while (i < dest_len)
	{
		if (!one)
			dest = push(dest, &two, &i);
		else if (!two)
			dest = push(dest, &one, &i);
		else
		{
			cmp_two = two->content;
			cmp_one = one->content;
			if (*cmp_one < *cmp_two)
				dest = push(dest, &one, &i);
			else
				dest = push(dest, &two, &i);
		}
	}
	return (dest);
}

t_list			*ft_lst_mergesort(t_list *list)
{
	size_t	list_len;
	t_list	*one;
	t_list	*two;
	int		*cmp1;
	int		*cmp2;

	one = NULL;
	two = NULL;
	cmp1 = NULL;
	cmp2 = NULL;
	list_len = get_listlen(list);
	if (list_len == 1 || list->next == 0)
		return (list);
	list_split(&one, &two, list_len, &list);
	return (merge(ft_lst_mergesort(one), ft_lst_mergesort(two), cmp1, cmp2));
}
