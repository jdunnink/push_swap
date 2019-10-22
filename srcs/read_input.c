/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 07:47:17 by jdunnink       #+#    #+#                */
/*   Updated: 2019/10/22 11:30:34 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**	check_nbr() checkes for errors in string
**	formatted numbers included in the argument list.
**	checks for empty strings.
**	checks for unexpected characters.
*/

static	int		check_nbr(char *nbr)
{
	unsigned i;

	if (ft_strlen(nbr) == 0)
		error(3);
	i = 0;
	while (nbr[i] != '\0')
	{
		if (ft_isdigit(nbr[i]) == 0 && ft_issign(nbr[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
**	push() converts a string formatted number to an
**	integer and pushes it onto stack a, within the
**	'stacks' struct. Before pushing, values are
**	checked against integer overflows.
*/

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

/*
**	check_dup() checks the filled stack A for duplicate
**	values, after the complete argument list has been
**	pushed. Each value is compared each other value within
**	the 'a_list' variable.
*/

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

/*
**	process_alt() is included to provided support for single
**	string formatting. In this case, an argument list is formatted
**	as a single string, where individual numbers are seperated by spaces.
**	The argument is split up using ft_split() and then processed. Afterwards,
**	the array created by ft_split() is freed.
*/

static	void	process_alt(char *str, t_stacks **stacks)
{
	char	**args;
	int		i;

	if (ft_strlen(str) == 0)
		error(3);
	else if (ft_str_only(str, ' ') == 1)
		error(3);
	i = 0;
	args = ft_split(str);
	while (args[i] != NULL)
	{
		if (check_nbr(args[i]) == 1)
			push(args[i], stacks);
		else
			error(3);
		i++;
	}
	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	if (args)
		free(args);
}

/*
**	read_input() reads and verifies the input list of numbers
**	passed as arguments. both number separated arguments and
**	single string formats are supported.
*/

void			read_input(int argc, char **argv, t_stacks **stacks)
{
	unsigned i;

	i = 1;
	while (i < (unsigned)argc)
	{
		if (check_nbr(argv[i]) == 1)
			push(argv[i], stacks);
		else if (argc == 2)
			process_alt(argv[i], stacks);
		else
			error(3);
		i++;
	}
	check_dup((*stacks)->a);
}
