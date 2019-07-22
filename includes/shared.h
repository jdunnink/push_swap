
#ifndef SHARED_H
# define SHARED_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef	struct	s_stacks
{
	t_list		*a;
	t_list		*b;
}				t_stacks;

void			print_state(t_stacks *stacks);
void			swap_a(t_stacks **stacks);
void			swap_b(t_stacks **stacks);
void			swap_swap(t_stacks **stacks);
void			push_a(t_stacks	**stacks);
void			push_b(t_stacks **stacks);
void			rotate_a(t_stacks **stacks);
void			rotate_b(t_stacks **stacks);
void			rotate_rotate(t_stacks **stacks);
void			rev_rotate_a(t_stacks **stacks);
void			rev_rotate_b(t_stacks **stacks);
void			rev_rotate_rotate(t_stacks **stacks);

#endif