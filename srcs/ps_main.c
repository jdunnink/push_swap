/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:18:43 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/11 18:12:20 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static 	void 	free_stacks(t_stacks **stacks)
{
	t_list *a;
	t_list *b;

	a = (*stacks)->a;
	b = (*stacks)->b;
	if (a)
		ft_lstdel(&a, &ft_del);
	if (b)
		ft_lstdel(&b, &ft_del);
	free(*stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*solution;
	size_t		len;

	int		k_after;
	int 	k_between_one;
	int 	k_between_two;
	size_t btw_len_one;
	size_t btw_len_two;
	int 	k_before;

	k_after = 0;
	k_between_one = 0;
	k_between_two = 0;
	btw_len_one = 0;
	btw_len_two = 0;
	k_before = 0;

	stacks = NULL;
	if (argc <= 1)
		error(1);
	else
	{
		init_stacks(&stacks);
		read_input(argc, argv, &stacks);
	}
	len = ft_listlen(stacks->a);
	k_before = get_k(stacks->a, 'a');
	if (len <= 5)
		solution = brute_force(&stacks);
	else if (len <= 50)
	{
		solution = position_sort(&stacks, 0.10);
		k_between_one = get_k(stacks->b, 'b');
		btw_len_one = ft_strlen(solution);
		solution = ft_strjoin_free(solution, chunk_sort(&stacks, len), 3);
		k_between_two = get_k(stacks->a, 'a');
		btw_len_two = ft_strlen(solution);
		k_after = get_k(stacks->a, 'a');
	}
	else if (len <= 100)
	{
		solution = position_sort(&stacks, 0.10);
		k_between_one = get_k(stacks->b, 'b');
		btw_len_one = ft_strlen(solution);
		solution = ft_strjoin_free(solution, chunk_sort(&stacks, len), 3);
		k_between_two = get_k(stacks->a, 'a');
		btw_len_two = ft_strlen(solution);
		k_after = get_k(stacks->a, 'a');
	}
	else
	{
		solution = position_sort(&stacks, 0.05);
		k_between_one = get_k(stacks->b, 'b');
		btw_len_one = ft_strlen(solution);
		solution = ft_strjoin_free(solution, chunk_sort(&stacks, len / 4), 3);
		k_between_two = get_k(stacks->a, 'a');
		btw_len_two = ft_strlen(solution);
		solution = ft_strjoin_free(solution, insertion_sort(&stacks), 3);
		k_after = get_k(stacks->a, 'a');
	}

	printf("ending solution  : %s\n\n\n", solution);
	printf("	instructions part_one: %lu\n", btw_len_one);
	printf("	instructions part two: %lu\n", btw_len_two - btw_len_one);
	printf("	instructions part three: %lu\n", (ft_strlen(solution) - btw_len_one) - (btw_len_two - btw_len_one));
	printf("						\ntotal instructions : %lu\n\n", ft_strlen(solution));
	printf("	k before processing: %i\n", k_before);
	printf("	k_between one: %i\n", k_between_one);
	printf("	k_between two: %i\n", k_between_two);
	printf("	k after processing: %i\n", k_after);
	printf("	part_one sorting efficiency: %.10f\n", (double)(k_before - k_between_one) / btw_len_one);
	printf("	part_two sorting efficiency: %.10f\n", (double)(k_between_one - k_between_two) / (btw_len_two - btw_len_one));
	printf("	part_three sorting efficiency: %.10f\n", (double)(k_between_two - k_after) / (ft_strlen(solution) - (btw_len_two - btw_len_one)));
	printf("						\ntotal sorting efficiency: %.10f\n\n", (double)(k_before - k_after) / ft_strlen(solution));
	print_state(stacks);

	free_stacks(&stacks);
	free(solution);
	return (0);
}