/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 12:18:43 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/09 15:54:03 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
//	printf("\ntotal instructions: %lu\n", ft_strlen(solution));
	printf("	initial count: 0 // starting k: %i\n", k_start);
	printf("	position_sort: %i // k after application: %i // sorting efficiency: %.10f\n", count_one, k_one, (double)(k_start - k_one) / count_one);
	printf("	selection_sort: %i // k after application: %i // sorting efficiency: %.10f\n", count_two, k_two, (double)(k_one - k_two) / count_two);
	printf("	insertion_sort: %i // k after application: %i // sorting efficiency: %.10f\n", count_three, k_three, (double)(k_two - k_three) / count_three);
	printf("	total instructions: %lu // ending k: %i // total sorting efficiency: %.10f\n", ft_strlen(solution), k_three, (double)k_start / ft_strlen(solution));
	show_redundant(solution);
//	printf("	starting k value: %i\n", k_start);
//	printf("	ending k value: %i\n", k_three);
	print_state(stacks);
	return (0);
}