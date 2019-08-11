/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/11 18:38:41 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/11 18:54:30 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstrev(t_list *list)
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
	return (dest);
}