/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/19 12:32:01 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/28 11:42:19 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "shared.h"

typedef struct	s_pos
{
	int			value;
	int			r_dis;
	int			rr_dis;
	int			dest_r_dis;
	int			dest_rr_dis;
	int			path;
	int			type;
}				t_pos;

char			*brute_force(t_stacks **stacks);
char			*dynamic_sort(t_stacks **stacks);
char			*select_sort(t_stacks **stacks);

int				try_solution(char *str, t_stacks **stacks);
int				instruct(char *str, t_stacks **stacks, char **solution);

t_list			*get_sorted(t_list *list);
t_list			*get_rev_sorted(t_stacks **stacks);

void			print_solution(char *solution);

int				get_highest(t_list *stack, int *high_dis);
int				get_lowest(t_list *stack, int *low_dis);
void			set_paths(t_list **distances);
void			get_distance_list(t_list **distances, t_list *stack);
void			get_dest_distances(t_list **distances, t_list *stack, char c);
void			choose_act_a(t_stacks **stacks, char **solution, t_pos *target);
void			choose_act_b(t_stacks **stacks, char **solution, t_pos *target);
void			choose_target(t_list **d, t_stacks **stcks, char **sol, char c);
void			sort_a(t_stacks **stacks, char **solution);
void			move_to_lowest(t_stacks **stacks, char **solution);
void			update_distances(t_list **d, t_list *src, t_list *dst, char c);
void			print_distance_list(t_list *distances);
int				find_sh(t_pos *target);
void			choose_insert(t_stacks **stacks, char **solution);

#endif
