/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/19 12:32:01 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/14 15:02:59 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "shared.h"

typedef struct	s_index
{
	int			nb;
	int			index;
}				t_index;

typedef	struct	s_ints
{
	int			one;
	int			two;
	int			three;
	int			four;
	int			five;
	int			six;
}				t_ints;

char			*brute_force(t_stacks **stacks);
char			*dynamic_sort(t_stacks **stacks);

int				try_solution(char *str, t_stacks **stacks);
int				instruct(char *str, t_stacks **stacks, char **solution);

t_list			*get_sorted(t_list *list);
t_list			*get_rev_sorted(t_stacks **stacks);

void			print_solution(char *solution);

#endif
