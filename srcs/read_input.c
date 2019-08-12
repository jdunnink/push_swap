/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 07:47:17 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/08/12 07:47:17 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	int		check_nbr(char *nbr)
{
	unsigned i;

	i = 0;
	while (nbr[i] != '\0')
	{
		if (ft_isdigit(nbr[i]) == 0 && ft_issign(nbr[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static	void	push(char *nbr, t_stacks **stacks)
{
	long long	check;
	int			val;

	check = ft_atoll(nbr);
	if (check > 2147483647 || check < -2147483648)
		error(4);
	val = check;
	ft_lstpushback(&(*stacks)->a, &val, sizeof(int));
}

static	void	check_dup(t_list *a_list)
{
	t_list		*iter;
	t_list		*runner;
	int			curr_val;
	unsigned	i;
	unsigned	j;

	iter = a_list;
	i = 0;
	while (iter)
	{
		curr_val = *(int *)(iter->content);
		runner = a_list;
		j = 0;
		while (runner)
		{
			if (*(int *)(runner->content) == curr_val && j != i)
				error(5);
			runner = runner->next;
			j++;
		}
		iter = iter->next;
		i++;
	}
}

void			read_input(int argc, char **argv, t_stacks **stacks)
{
	unsigned i;

	i = 1;
	while (i < (unsigned)argc)
	{
		if (check_nbr(argv[i]) == 1)
			push(argv[i], stacks);
		else
			error(3);
		i++;
	}
	check_dup((*stacks)->a);
}
