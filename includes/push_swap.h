/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/19 12:32:01 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/09 15:02:29 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "shared.h"

typedef struct s_index
{
	int nb;
	int index;
}				t_index;

char	*brute_force(t_stacks **stacks);
int		try_solution(char *str, t_stacks **stacks);

int		instruct(char *str, t_stacks **stacks, char **solution);

char	*selection_sort(t_stacks **stacks);
char 	*position_sort(t_stacks **stacks, double precision);
char	*insertion_sort(t_stacks **stacks);


void	show_redundant(char *solution);
int		get_k(t_list *list, char stack);

#endif