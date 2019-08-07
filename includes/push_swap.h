/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/19 12:32:01 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/07 15:04:05 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "shared.h"

char	*brute_force(t_stacks **stacks);
int		try_solution(char *str, t_stacks **stacks);

int		instruct(char *str, t_stacks **stacks, char **solution);

char	*quick_sort(t_stacks **stacks);
char	*insertion_sort(t_stacks **stacks);
char	*selection_sort(t_stacks **stacks);
char 	*position_sort(t_stacks **stacks);

#endif