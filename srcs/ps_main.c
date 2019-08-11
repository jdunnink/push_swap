/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:18:43 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/11 18:06:17 by jdunnink      ########   odam.nl         */
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
		solution = position_sort(&stacks, 0.10);			// for a 50 list --> at factor 0.20 position sort results: 91 instr / 11 to 4 k_diff / SE: 0.076
		k_between_one = get_k(stacks->b, 'b');
		btw_len_one = ft_strlen(solution);
		solution = ft_strjoin_free(solution, chunk_sort(&stacks, len), 3);
		k_between_two = get_k(stacks->a, 'a');
		btw_len_two = ft_strlen(solution);
		k_after = get_k(stacks->a, 'a');
	}
	else if (len <= 100)
	{
		solution = position_sort(&stacks, 0.10);			// for a 100 list --> at factor 0.40 position sort results: 135 instr / 33 to 14 k_diff / SE: 0.140
		k_between_one = get_k(stacks->b, 'b');
		btw_len_one = ft_strlen(solution);
		solution = ft_strjoin_free(solution, chunk_sort(&stacks, len), 3);
		k_between_two = get_k(stacks->a, 'a');
		btw_len_two = ft_strlen(solution);
		k_after = get_k(stacks->a, 'a');
	}
	else
	{
		solution = position_sort(&stacks, 0.05);			// for a 500 list --> at factor 0.25 position sort results: 831 instr / 142 to 54 k_diff / SE: 0.109
		k_between_one = get_k(stacks->b, 'b');
		btw_len_one = ft_strlen(solution);
		solution = ft_strjoin_free(solution, chunk_sort(&stacks, len / 4), 3);	// p_rate 10 --> SE: 0.015 / k: 10
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
	





















































/*

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*solution;
	char		*solution_two;
	char 		*solution_three;
	size_t		len;
	
	int 	count_one;
	int		count_two;
	int 	count_three;

	int 	k_start;
	int 	k_one;
	int 	k_two;
	int		k_three;

	count_one = 0;
	count_two = 0;
	count_three = 0;

	stacks = NULL;
	if (argc <= 1)
		error(1);
	else
	{
		init_stacks(&stacks);
		read_input(argc, argv, &stacks);
	}
	len = ft_listlen(stacks->a);
	//				if there are no more than 5 values, brute-force breadth-first instruction combos
	k_start = get_k(stacks->a, 'a');
	if (len <= 5)
		solution = brute_force(&stacks);
	/////////////////////////////////////////////////////////////////////////////////////////////
	else
	{
		//	STEP 1
		//	sort the list into a nearly sorted version using position sort
		print_state(stacks);
		printf("	calling position sort!\n");
		solution = position_sort(&stacks, 0.20);		// factor indicates the minimal level of precision
		count_one = ft_strlen(solution);
		k_one = get_k(stacks->b, 'b');
		///////////////////////////////////////////////////////////////////////////////////////////

		// STEP 2
		//	move list from stack b to stack b using smart selection
		print_state(stacks);
		printf("	positional sort done --> calling selection sort\n");
		solution_two = selection_sort(&stacks);
		count_two = ft_strlen(solution_two);
		solution = ft_strjoin_free(solution, solution_two, 3);
		k_two = get_k(stacks->a, 'a');
		//////////////////////////////////////////////////////////////////////////////////

		// STEP 3
		//			sort the nearly sorted stack using insertion sort --> k should be lowered AMAP beforehand
		print_state(stacks);
		printf("	selection sort done --> calling insertion sort\n");
		solution_three = insertion_sort(&stacks);
		count_three = ft_strlen(solution_three);
		solution = ft_strjoin_free(solution, solution_three, 3);
		k_three = get_k(stacks->a, 'a');
		/////////////////////////////////////////////////////////////////////////////////////////
	}
	printf("ending solution  : %s\n", solution);
	if (len > 5)
	{
		printf("	initial count: 0 // starting k: %i\n", k_start);
		printf("	position_sort: %i // k after application: %i // sorting efficiency: %.10f\n", count_one, k_one, (double)(k_start - k_one) / count_one);
		printf("	selection_sort: %i // k after application: %i // sorting efficiency: %.10f\n", count_two, k_two, (double)(k_one - k_two) / count_two);
		printf("	insertion_sort: %i // k after application: %i // sorting efficiency: %.10f\n", count_three, k_three, (double)(k_two - k_three) / count_three);
		printf("	total instructions: %lu // ending k: %i // total sorting efficiency: %.10f\n", ft_strlen(solution), k_three, (double)k_start / ft_strlen(solution));
		show_redundant(solution);
	}
//	printf("	starting k value: %i\n", k_start);
//	printf("	ending k value: %i\n", k_three);
	print_state(stacks);
	return (0);
}

*/