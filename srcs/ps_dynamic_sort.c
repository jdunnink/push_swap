/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_dynamic_sort.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 17:48:17 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/13 18:11:35 by jdunnink      ########   odam.nl         */
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
	int path;					// the shortest distance to the values destination.
	int type;					// type of path --> 0 = rotate, 1 = rev_rotate, 2 is both, 3 is uninitialized
}				t_pos;

#include "push_swap.h"

//	if paths are matching --> how much can they be decremented without one of them touching zero?

int 	check_overlap(int curr, int dest, int path)
{
	int base;

	base = 0;
	if (curr == 0 || dest == 0)
		return (path);
	while (curr > 0 && dest > 0)
	{
		base++;
		curr--;
		dest--;
	}
	return (path - base);
}

static 	void 	print_distance_list(t_list *distances)
{
	t_list	*iter;
	t_pos	*curr;

	ft_putchar('\n');
	iter = distances;
	while (iter)
	{
		curr = (t_pos *)iter->content;
//		printf("stored value:	%i	r_dis:	%i	rr_dis	%i	dest_r_dis:	%i	dest_rr_dis:	%i	path:	%i	type:	%i\n", curr->value, curr->r_dis, curr->rr_dis, curr->dest_r_dis, curr->dest_rr_dis, curr->path, curr->type);
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
		new->path = 0;
		new->type = 3;
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
//		printf("	value %i is highest!\n", value);
		return (high_dis);
	}
	iter = stack;
	while (iter->next)
	{
		if (*(int *)iter->content > value && *(int *)iter->next->content < value)
		{
//			printf("	value %i fits between %i and %i\n", value, *(int *)iter->content, *(int *)iter->next->content);
			return (dis);
		}
		else if (*(int *)iter->content > value && *(int *)iter->next->content > value && *(int *)iter->next->content == highest)
		{
//			printf("	value %i fits between %i and %i\n", value, *(int *)iter->content, *(int *)iter->next->content);
			return (dis);
		}
		dis++;
		iter = iter->next;
	}
//	printf("	could not find placement for value %i--> assuming 0!\n", value);
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

static 	void 	set_paths(t_list **distances)
{
	t_list	*iter;
	t_pos	*curr;
	int 	shortest_curr;
	int		shortest_dest;

	iter = *distances;
	while (iter)
	{
		curr = (t_pos *)iter->content;
		if (curr->r_dis < curr->rr_dis)
			shortest_curr = curr->r_dis;
		else
			shortest_curr = curr->rr_dis;
		if (curr->dest_r_dis < curr->dest_rr_dis)
			shortest_dest = curr->dest_r_dis;
		else
			shortest_dest = curr->dest_rr_dis;
		if (shortest_dest == curr->dest_rr_dis && shortest_curr == curr->rr_dis)
			curr->type = 1;
		else if (shortest_dest == curr->dest_r_dis && shortest_curr == curr->r_dis)
			curr->type = 0;
		else
			curr->type = 2;
		curr->path = shortest_curr + shortest_dest;
		if (curr->type == 0|| curr->type == 1)
			curr->path = check_overlap(shortest_curr, shortest_dest, curr->path);
		iter = iter->next;
	}
}

static	void	update_distances(t_list **distances, t_stacks **stacks)
{
	get_distance_list(distances, (*stacks)->a);				// initiate a distance list with the remaining values in stack A;
	get_dest_distances(distances, (*stacks)->b);			// determine the distances to destination for each value in the dist list;
	set_paths(distances);									// determine the shortest path to dest for each value in the dist list
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
	return (0);
}

int 	find_sh(int one, int two, int three, int four)
{
	int dest;
	
	dest = INT32_MAX;
	if (one < dest && one != 0)
		dest = one;
	if (two < dest && two != 0)
		dest = two;
	if (three < dest && three != 0)
		dest = three;
	if (four < dest && three != 0)
		dest = four;
	if (dest == four)
		return (3);
	if (dest == three)
		return (2);
	if (dest == two)
		return (1);
	if (dest == one)
		return (0);
	return (-1);
}

static	void 	choose_action(t_stacks **stacks, char **solution, t_pos *target)
{
	char	*actions;
	int		place;

//	printf("	choosing action for the identified push target..\n");
	if (target->type == 2)
	{
//		printf("	this target path combines rotate/rev_rotate --> no double action possible --> reducing lowest non-zero value\n");
		place = find_sh(target->r_dis, target->rr_dis, target->dest_r_dis, target->dest_rr_dis);
		if (place == 0)
			instruct(ft_ctostr('f'), stacks, solution);
		else if (place == 1)
			instruct(ft_ctostr('i'), stacks, solution);
		else if (place == 2)
			instruct(ft_ctostr('g'), stacks, solution);
		else
			instruct(ft_ctostr('j'), stacks, solution);		
	}
	else if (target->type == 1)
	{
//		printf("	this target path uses rev_rotate\n");
		if (target->rr_dis > 0 && target->dest_rr_dis > 0)
			instruct(ft_ctostr('k'), stacks, solution);
		else
		{
//			printf("	no double rev_rotate possible --> reducing lowest non-zero rev_rotate\n");
			if (target->rr_dis == 0)
				instruct(ft_ctostr('j'), stacks, solution);
			else if (target->dest_rr_dis == 0)
				instruct(ft_ctostr('i'), stacks, solution);
			else if (target->rr_dis < target->dest_rr_dis)
				instruct(ft_ctostr('i'), stacks, solution);
			else
				instruct(ft_ctostr('j'), stacks, solution);
		}
	}
	else
	{
//		printf("	this target path uses rotate\n");
		if (target->r_dis > 0 && target->dest_r_dis > 0)
			instruct(ft_ctostr('h'), stacks, solution);
		else
		{
//			printf("	no double rotate possible --> reducing lowest non-zero rotate\n");
			if (target->r_dis == 0)
				instruct(ft_ctostr('g'), stacks, solution);
			else if (target->dest_r_dis == 0)
				instruct(ft_ctostr('f'), stacks, solution);
			else if (target->r_dis < target->dest_r_dis)
				instruct(ft_ctostr('f'), stacks, solution);
			else
				instruct(ft_ctostr('g'), stacks, solution);
		}		
	}
} 

static 	void 	choose_target(t_list **distances, t_stacks **stacks, char **solution)
{
	t_list	*iter;
	t_pos	*curr;
	int		shortest;
	t_pos	*target;

//	printf("	No push possible --> finding alternative target..\n");

	iter = *distances;
	curr = (t_pos *)iter->content;
	shortest = curr->path;
	target = curr;
	while (iter)
	{
		curr = (t_pos *)iter->content;
		if (curr->path < shortest)
		{
			target = curr;
			shortest = curr->path;
//			printf("	A new shortest path was found --> value %i with path: %i\n", curr->value, curr->path);
		}
		iter = iter->next;
	}
//	printf("	targeting value %i\n", target->value);
	choose_action(stacks, solution, target);
}

static	void	finalize(t_stacks **stacks, char **solution)
{
	int highest;
	int high_dis;
	int rev_dis;
	int median;

	median = (int)ft_listlen((*stacks)->b) / 2;
	highest = get_highest((*stacks)->b, &high_dis);
	rev_dis = (int)ft_listlen((*stacks)->b) - high_dis;
	if (high_dis < rev_dis)
		while (*(int *)(*stacks)->b->content != highest)
			instruct(ft_ctostr('g'), stacks, solution);
	else
		while (*(int *)(*stacks)->b->content != highest)
			instruct(ft_ctostr('j'), stacks, solution);
	while ((*stacks)->b)
		instruct(ft_ctostr('a'), stacks, solution);
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
		if (ft_listlen((*stacks)->a) == 2)
			break ;
		update_distances(&distances, stacks);
		if (execute(&distances, stacks, &solution) == 0)
			choose_target(&distances, stacks, &solution);
		print_state(*stacks);
		i++;
	}
//	finalize(stacks, &solution);
	print_state(*stacks);
	ft_putendl(solution);
	printf("	total instructions: %i\n", (int)ft_strlen(solution));
	exit (0);
	return (solution);
}