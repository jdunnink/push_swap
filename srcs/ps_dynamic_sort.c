/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_dynamic_sort.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 17:48:17 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/14 14:59:36 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//	type coding --> path codes need to be more specific --> allows for easier action selection
//
//	four options for decrementing
//	only two paths are active at any one time
//	combine two numbers --> 13 means path one and three are active
//							12 means path one and two are active
//							23 means path two and three are active
//							24 means path two and four are active


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

//	ft_putchar('\n');
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

static 	int 	get_lowest(t_list *stack, int *low_dis)
{
	int lowest;
	t_list *iter;
	int i;

	i = 0;
	lowest = *(int *)stack->content;
	iter = stack;
	while (iter)
	{
		if (*(int *)iter->content < lowest)
		{
			*low_dis = i;
			lowest = *(int *)iter->content;
		}
		iter = iter->next;
		i++;
	}
	return (lowest);
}

static	int 	find_place_rev(t_list *stack, int value)
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

static	int 	find_place(t_list *stack, int value)
{
	int	dis;
	int	highest;
	int	high_dis;
	int lowest;
	int low_dis;
	t_list *iter;

	dis = 1;
	highest = get_highest(stack, &high_dis);
	lowest = get_lowest(stack, &low_dis);
	if (value > highest)
	{
//		printf("	value %i is highest!\n", value);
		return (high_dis + 1);
	}
	iter = stack;
	while (iter->next)
	{
		if (*(int *)iter->content < value && *(int *)iter->next->content > value)
		{
//			printf("	value %i fits between %i and %i\n", value, *(int *)iter->content, *(int *)iter->next->content);
			return (dis);
		}
		else if (value < *(int *)iter->content && value < *(int *)iter->next->content && *(int *)iter->next->content == lowest)
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

static 	void	get_dest_distances(t_list **distances, t_list *stack, char c)
{
	t_list	*iter;
	t_pos	*curr;

	iter = *distances;
	while (iter)
	{
		curr = (t_pos *)iter->content;
		if (c == 'a')
			curr->dest_r_dis = find_place_rev(stack, curr->value);
		else
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
			curr->type = 24;
		else if (shortest_dest == curr->dest_r_dis && shortest_curr == curr->r_dis)
			curr->type = 13;
		else if (shortest_dest == curr->dest_r_dis && shortest_curr == curr->rr_dis) 
			curr->type = 23;
		else
			curr->type = 14;
		curr->path = shortest_curr + shortest_dest;
		if (curr->type == 13|| curr->type == 24)
			curr->path = check_overlap(shortest_curr, shortest_dest, curr->path);
		iter = iter->next;
	}
}

static	void	update_distances(t_list **distances, t_list *src, t_list *dest, char c)
{
	get_distance_list(distances, src);				// initiate a distance list with the remaining values in src stack;
	get_dest_distances(distances, dest, c);			// determine the distances to destination for each value in the dist list;
	set_paths(distances);									// determine the shortest path to dest for each value in the dist list
	print_distance_list(*distances);
}

static	int	check_push_b(t_list **distances, t_stacks **stacks, char **solution)
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

int 	find_sh(t_pos *target)
{
	int dest;
	int one;
	int two;

	if (target->type == 14)
	{
		one = target->r_dis;
		two = target->dest_rr_dis;
		if (one == 0)
			return (3);
		else if (two == 0)
			return (0);
		else if (one < two)
			return (0);
		else
			return (3);
	}
	one = target->rr_dis;
	two = target->dest_r_dis;
	if (one == 0)
		return (2);
	else if (two == 0)
		return (1);
	else if (one < two)
		return (1);
	else
		return (2);

}

static	void 	choose_action_a(t_stacks **stacks, char **solution, t_pos *target)
{
	char	*actions;
	int		place;

//	printf("	choosing action for the identified push target..\n");
	if (target->type == 14 || target->type == 23)
	{
//		printf("	this target path combines rotate/rev_rotate --> no double action possible --> reducing lowest non-zero value\n");
		place = find_sh(target);
		if (place == 0)
			instruct(ft_ctostr('f'), stacks, solution);
		else if (place == 1)
			instruct(ft_ctostr('i'), stacks, solution);
		else if (place == 2)
			instruct(ft_ctostr('g'), stacks, solution);
		else
			instruct(ft_ctostr('j'), stacks, solution);		
	}
	else if (target->type == 24)
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

static	void 	choose_action_b(t_stacks **stacks, char **solution, t_pos *target)
{
	char	*actions;
	int		place;

//	printf("	choosing action for the identified push target..\n");
	if (target->type == 14 || target->type == 23)
	{
//		printf("	this target path combines rotate/rev_rotate --> no double action possible --> reducing lowest non-zero value\n");
		place = find_sh(target);
		if (place == 0)
			instruct(ft_ctostr('g'), stacks, solution);
		else if (place == 1)
			instruct(ft_ctostr('j'), stacks, solution);
		else if (place == 2)
			instruct(ft_ctostr('f'), stacks, solution);
		else
			instruct(ft_ctostr('i'), stacks, solution);		
	}
	else if (target->type == 24)
	{
//		printf("	this target path uses rev_rotate\n");
		if (target->rr_dis > 0 && target->dest_rr_dis > 0)
			instruct(ft_ctostr('k'), stacks, solution);
		else
		{
//			printf("	no double rev_rotate possible --> reducing lowest non-zero rev_rotate\n");
			if (target->rr_dis == 0)
				instruct(ft_ctostr('i'), stacks, solution);
			else if (target->dest_rr_dis == 0)
				instruct(ft_ctostr('j'), stacks, solution);
			else if (target->rr_dis < target->dest_rr_dis)
				instruct(ft_ctostr('j'), stacks, solution);
			else
				instruct(ft_ctostr('i'), stacks, solution);
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
				instruct(ft_ctostr('f'), stacks, solution);
			else if (target->dest_r_dis == 0)
				instruct(ft_ctostr('g'), stacks, solution);
			else if (target->r_dis < target->dest_r_dis)
				instruct(ft_ctostr('g'), stacks, solution);
			else
				instruct(ft_ctostr('f'), stacks, solution);
		}		
	}
}

static 	void 	choose_target(t_list **distances, t_stacks **stacks, char **solution, char c)
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
//	printf("	targeting value %i with shortest path: %i\n", target->value, target->path);
	if (c == 'a')
		choose_action_a(stacks, solution, target);
	else
		choose_action_b(stacks, solution, target);
}

static	void	sort_a(t_stacks **stacks, char **solution)
{
	t_list *iter;
	int top;
	int next;
	int highest;
	int high_dis;

	highest = get_highest((*stacks)->a, &high_dis);
	while (check_sort((*stacks)->a) == 0)
	{
		top = *(int *)(*stacks)->a->content;
		next = *(int *)(*stacks)->a->next->content;
		if (next < top && top != highest)
			instruct(ft_ctostr('c'), stacks, solution);
		else
			instruct(ft_ctostr('f'), stacks, solution);
	}
	while(*(int *)(*stacks)->a->content != highest)
		instruct(ft_ctostr('f'), stacks, solution);
}

static	int	check_push_a(t_list **distances, t_stacks **stacks, char **solution)
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
				instruct(ft_ctostr('a'), stacks, solution);
				return (1);
			}
		iter = iter->next;
	}
	return (0);
}

static	void 	move_to_lowest(t_stacks **stacks, char **solution)
{
	t_list *iter;
	int lowest;
	int low_dis;
	int	rev_dis;

//	printf("	move to lowest was called!\n");

	lowest = get_lowest((*stacks)->a, &low_dis);
//	printf("	lowest value %i was found at distance %i\n", lowest, low_dis);
	rev_dis = (int)ft_listlen((*stacks)->a) - low_dis;
	if (rev_dis < low_dis)
		while(*(int *)(*stacks)->a->content != lowest)
			instruct(ft_ctostr('i'), stacks, solution);
	else
		while(*(int *)(*stacks)->a->content != lowest)
			instruct(ft_ctostr('f'), stacks, solution);
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
//	print_state(*stacks);
	while (ft_listlen((*stacks)->a) > 3)
	{
		update_distances(&distances, (*stacks)->a, (*stacks)->b, 'a');
		if (check_push_b(&distances, stacks, &solution) == 0)
			choose_target(&distances, stacks, &solution, 'a');
//		print_state(*stacks);
		i++;
	}
	sort_a(stacks, &solution);
//	print_state(*stacks);
	while ((*stacks)->b)
	{
		update_distances(&distances, (*stacks)->b, (*stacks)->a, 'b');
		if (check_push_a(&distances, stacks, &solution) == 0)
			choose_target(&distances, stacks, &solution, 'b');
//		print_state(*stacks);
	}
	move_to_lowest(stacks, &solution);
//	print_state(*stacks);
//	ft_putendl(solution);
//	printf("	total instructions: %i\n", (int)ft_strlen(solution));
//	if (check_solved(*stacks) == 1)
//		printf("	 this is valid solution!\n");
//	exit (0);
	return (solution);
}