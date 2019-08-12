/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_chunk_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/10 16:00:33 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 07:53:45 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	init_vars(t_ints *vars, t_list *s, t_list **iter, size_t *len)
{
	vars->three = INT32_MAX;
	vars->one = 0;
	*len = ft_listlen(s);
	vars->two = *len / 2;
	*iter = s;
	vars->four = 0;
}

static	void	check_vars(t_ints *vars, int *curr_chunk, size_t len)
{
	if (vars->six == *curr_chunk)
	{
		if (vars->one > vars->two)
		{
			vars->five = (int)len - vars->one;
			vars->four = vars->five;
		}
		else
			vars->five = vars->one;
		if (vars->five < vars->three)
			vars->three = vars->five;
	}
}

static	int		find_next(t_list *s, t_list *i, int *curr_chunk, int p_rate)
{
	size_t	len;
	t_list	*iter;
	t_ints	vars;

	init_vars(&vars, s, &iter, &len);
	while (iter)
	{
		vars.six = lookup_index((int *)iter->content, i);
		check_vars(&vars, curr_chunk, len);
		vars.one++;
		iter = iter->next;
		if (iter == NULL && vars.three == INT32_MAX)
		{
			(*curr_chunk)++;
			if (*curr_chunk > p_rate)
				return (INT32_MAX);
			iter = s;
			vars.one = 0;
		}
	}
	if (vars.four == vars.three)
		vars.three *= -1;
	return (vars.three);
}

static	int		check_distance(int *distance, t_stacks **s, char **solution)
{
	if (*distance == INT32_MAX)
		return (-1);
	if (*distance == 0)
		instruct(ft_ctostr('a'), s, solution);
	else if (*distance > 0)
	{
		while (*distance > 0)
		{
			instruct(ft_ctostr('g'), s, solution);
			(*distance)--;
		}
		instruct(ft_ctostr('a'), s, solution);
	}
	else if (*distance < 0)
	{
		while (*distance < 0)
		{
			instruct(ft_ctostr('j'), s, solution);
			(*distance)++;
		}
		instruct(ft_ctostr('a'), s, solution);
	}
	return (1);
}

char			*chunk_sort(t_stacks **stacks, int p_rate)
{
	t_list	*indices;
	t_list	*iter;
	char	*solution;
	int		curr_chunk;
	int		distance;

	solution = NULL;
	indices = set_indices(stacks);
	adjust_indices(indices, p_rate);
	curr_chunk = 0;
	iter = (*stacks)->b;
	while ((*stacks)->b)
	{
		distance = find_next((*stacks)->b, indices, &curr_chunk, p_rate);
		if (check_distance(&distance, stacks, &solution) == -1)
			break ;
		indices = update_indices(stacks, &indices);
	}
	return (solution);
}
