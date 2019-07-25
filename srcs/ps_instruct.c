/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_instruct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:51:21 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/25 20:49:18 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*read_instr(char *next_instr)
{
	if (next_instr == NULL)
		return (NULL);
	else if (ft_strcmp(next_instr, "af") == 0)
		return ("push_a --> rotate_a");
	else if (ft_strcmp(next_instr, "bg") == 0)
		return ("push_b --> rotate_b");
	else if (ft_strcmp(next_instr, "ac") == 0)
		return ("push_a --> swap_a");
	else if (ft_strcmp(next_instr, "bd") == 0)
		return ("push_b --> swap_b");
	else if (ft_strcmp(next_instr, "a") == 0)
		return ("push_a");
	else if (ft_strcmp(next_instr, "b") == 0)
		return ("push_b");
	else if (ft_strcmp(next_instr, "c") == 0)
		return ("swap_a");
	else if (ft_strcmp(next_instr, "d") == 0)
		return ("swap_b");
	else if (ft_strcmp(next_instr, "e") == 0)
		return ("swap_swap");
	else if (ft_strcmp(next_instr, "f") == 0)
		return ("rotate_a");
	else if (ft_strcmp(next_instr, "g") == 0)
		return ("rotate_b");
	else if (ft_strcmp(next_instr, "h") == 0)
		return ("rotate_rotate");
	else if (ft_strcmp(next_instr, "i") == 0)
		return ("rev_rotate_a");
	else if (ft_strcmp(next_instr, "j") == 0)
		return ("rev_rotate_b");
	else if (ft_strcmp(next_instr, "k") == 0)
		return ("rev_rotate_rotate");
	else
		return (NULL);
}

static	void	execute(char code, t_stacks **stacks)
{
	if (code == 'a')
		push_a(stacks);
	else if (code == 'b')
		push_b(stacks);
	else if (code == 'c')
		swap_a(stacks);
	else if (code == 'd')
		swap_b(stacks);
	else if (code == 'e')
		swap_swap(stacks);
	else if (code == 'f')
		rotate_a(stacks);
	else if (code == 'g')
		rotate_b(stacks);
	else if (code == 'h')
		rotate_rotate(stacks);
	else if (code == 'i')
		rev_rotate_a(stacks);
	else if (code == 'j')
		rev_rotate_b(stacks);
	else if (code == 'k')
		rev_rotate_rotate(stacks);
}

static 	void	check_swap(char **instruction, t_stacks **stacks, char stack)
{
	int		curr;
	int		next;
	int		last;
	t_list *iter;

	if (stack == 'a')
	{
		if (ft_listlen((*stacks)->a) < 1)
			return ;
		curr = *(int *)(*stacks)->b->content;
		next = *(int *)(*stacks)->a->content;
		iter = (*stacks)->a;
		while (iter->next)
			iter = iter->next;
		last = *(int *)iter->content;
		if (curr > last)
			*instruction = ft_stradd(*instruction, ft_ctostr('f'));
		else if (curr > next)
			*instruction = ft_stradd(*instruction, ft_ctostr('c'));
	}
	else if (stack == 'b')
	{
		if (ft_listlen((*stacks)->b) < 1)
			return ;
		curr = *(int *)(*stacks)->a->content;
		next = *(int *)(*stacks)->b->content;
		iter = (*stacks)->b;
		while (iter->next)
			iter = iter->next;
		last = *(int *)iter->content;
		if (curr < last)
			*instruction = ft_stradd(*instruction, ft_ctostr('g'));
		else if (curr < next)
			*instruction = ft_stradd(*instruction, ft_ctostr('d'));
	}
}

int		instruct(char *str, t_stacks **stacks, char **solution)
{
	unsigned i;

	if (ft_strcmp(str, "a") == 0)
		check_swap(&str, stacks, 'a');
	else if (ft_strcmp(str, "b") == 0)
		check_swap(&str, stacks, 'b');
	printf("	next instruction : %s\n", read_instr(str));
	i = 0;
	while (str[i] != '\0')
	{
		execute(str[i], stacks);
		i++;
	}
//	print_state(*stacks);
	*solution = ft_stradd(*solution, str);
	if (check_solved(*stacks) == 1)
		return (1);
	return (0);
}