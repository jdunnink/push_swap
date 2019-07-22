/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 16:57:07 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/18 16:05:12 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *src)
{
	t_list	*dest;
	t_list	*iter;
	t_list	*next;

	iter = ft_lstcpy_elem(src);
	dest = iter;
	src = src->next;
	while (src)
	{
		next = ft_lstcpy_elem(src);
		iter->next = next;
		iter = next;
		src = src->next;
	}
	return (dest);
}
