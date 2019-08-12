/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_dynamic_sort.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 17:48:17 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 21:10:19 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_pos
{
	int value;					// value stored at this node
	int r_dis;					// absolute distance from the top of this stack --> number of rotations required
	int rr_dis;					// distance from the stack-top, taking into account rev_rotation --> number of rev_rotations required
	int dest_r_dis;				// absolute distance of dest position from the top of the other stack --> number of rotations.
	int dest_rr_dis;			// real distance of dest position from the top of the other stack --> number of rev_rotations.
}				t_pos;

#include "push_swap.h"

static 	void 	print_distance_list(t_list *distances)
{
	t_list	*iter;
	t_pos	*curr;

	ft_putchar('\n');
	iter = distances;
	while (iter)
	{
		curr = (t_pos *)iter->content;
		printf("stored value: %i // r_dis: %i // rr_dis %i // dest_r_dis: %i // dest_rr_dis: %i\n", curr->value, curr->r_dis, curr->rr_dis, curr->dest_r_dis, curr->dest_rr_dis);
		iter = iter->next;
	}
}

static	void 	set_up(t_stacks **stacks, char **solution)
{
	int	one;
	int two;

	instruct(ft_ctostr('b'), stacks, solution);
	two = *(int *)(*stacks)->a->content;
	one = *(int *)(*stacks)->b->content;
	instruct(ft_ctostr('b'), stacks, solution);
	if (two < one)
		instruct(ft_ctostr('d'), stacks, solution);
}

static 	void 	get_distance_list(t_list **distances, t_list *stack)
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
		new = (t_pos *)malloc(sizeof(t_pos));
		new->value = *(int *)iter->content;
		new->r_dis = i;
		new->rr_dis = len;
		new->dest_r_dis = 0;
		new->dest_rr_dis = 0;
		ft_lstpushback(distances, new, sizeof(t_pos));
		free(new);
		len--;
		i++;
		iter = iter->next;
	}
}

static 	int 	get_highest(t_list *stack, int *high_dis)
{
	int highest;
	t_list *iter;
	int i;

	i = 0;
	highest = *(int *)stack->content;
	iter = stack;
	while (iter)
	{
		if (*(int *)iter->content > highest)
		{
			*high_dis = i;
			highest = *(int *)iter->content;
		}
		iter = iter->next;
		i++;
	}
	return (highest);
}

static	int 	find_place(t_list *stack, int value)
{
	int	dis;
	int	highest;
	int	high_dis;
	t_list *iter;

	dis = 1;
	highest = get_highest(stack, &high_dis);
	if (value > highest)
	{
		printf("	value %i is highest!\n", value);
		return (high_dis);
	}
	iter = stack;
	while (iter->next)
	{
		if (*(int *)iter->content > value && *(int *)iter->next->content < value)
		{
			printf("	value %i fits between %i and %i\n", value, *(int *)iter->content, *(int *)iter->next->content);
			return (dis);
		}
		dis++;
		iter = iter->next;
	}
	printf("	value %i is lowest!\n", value);
	return (0);
}

static 	void	get_dest_distances(t_list **distances, t_list *stack)
{
	t_list	*iter;
	t_pos	*curr;

	iter = *distances;
	while (iter)
	{
		curr = (t_pos *)iter->content;
		curr->dest_r_dis = find_place(stack, curr->value);
		curr->dest_rr_dis = ft_listlen(stack) - curr->dest_r_dis;
		iter = iter->next;
	}
}

static	void	update_distances(t_list **distances, t_stacks **stacks)
{
	get_distance_list(distances, (*stacks)->a);				// initiate a distance list with the remaining values in stack A;
	get_dest_distances(distances, (*stacks)->b);				// determine the distances to destination for each value in the dist list;
	print_distance_list(*distances);
}

static	int	execute(t_list **distances, t_stacks **stacks, char **solution)
{
	t_list	*iter;
	t_pos	*pos;

	iter = *distances;
	while (iter)
	{
		pos = (t_pos *)iter->content;
		if (pos->r_dis == 0 || pos->rr_dis == 0)
			if (pos->dest_r_dis == 0 || pos->dest_rr_dis == 0)
			{
				instruct(ft_ctostr('b'), stacks, solution);
				return (1);
			}
		iter = iter->next;
	}
	printf("	no value in immediate push position --> more actions required.\n");
	return (0);
}

static 	void 	choose_action(t_list **distances, t_stacks **stacks, char **solution)
{
	t_list	*iter;
	t_pos	*curr;
	char 	action;

	action = 'x';
	iter = *distances;
	while (iter)
	{
		curr = (t_pos *)iter->content;
		if (curr->rr_dis == 1 && curr->dest_rr_dis == 1)
			action = 'k';
		if (curr->r_dis == 1 && curr->dest_r_dis == 1)
			action = 'h';
		if (curr->r_dis == 0 && curr->dest_r_dis == 1)
			action = 'g';
		if (curr->dest_r_dis == 0 && curr->r_dis == 1)
			action = 'f';
		iter = iter->next;
	}
	if (action == 'x')
		action = 'j';
	instruct(ft_ctostr(action), stacks, solution);
}

char	*dynamic_sort(t_stacks **stacks)
{
	char		*solution;
	t_list		*distances;
	unsigned i;

	i = 0;
	solution = NULL;
	distances = NULL;
	set_up(stacks, &solution);
	print_state(*stacks);
	while ((*stacks)->a)
	{
		update_distances(&distances, stacks);
		if (execute(&distances, stacks, &solution) == 0)
			choose_action(&distances, stacks, &solution);
		print_state(*stacks);
		i++;
	}
	printf("	total instructions: %lu\n", ft_strlen(solution));
	exit (0);
}