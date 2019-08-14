/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_get_distance_list.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 15:41:34 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/14 17:13:17 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	init_tpos(t_pos **new, t_list *iter, int i, int len)
{
	*new = (t_pos *)malloc(sizeof(t_pos));
	if (!new)
		error(7);
	(*new)->value = *(int *)iter->content;
	(*new)->r_dis = i;
	(*new)->rr_dis = len;
	(*new)->dest_r_dis = 0;
	(*new)->dest_rr_dis = 0;
	(*new)->path = 0;
	(*new)->type = 3;
}

void			get_distance_list(t_list **distances, t_list *stack)
{
	t_pos	*new;
	t_list	*iter;
	int		i;
	int		len;

	if (*distances != NULL)
		ft_lstdel(distances, &ft_del);
	i = 0;
	iter = stack;
	len = (int)ft_listlen(iter);
	while (iter)
	{
		init_tpos(&new, iter, i, len);
		ft_lstpushback(distances, new, sizeof(t_pos));
		free(new);
		len--;
		i++;
		iter = iter->next;
	}
}
