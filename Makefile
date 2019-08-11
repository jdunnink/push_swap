# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jdunnink <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/20 09:33:47 by jdunnink       #+#    #+#                 #
#    Updated: 2019/08/11 18:13:25 by jdunnink      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CHECKER_SRC =	ch_main.c				\
				error.c					\
				ch_get_instr.c			\
				print_state.c			\
				swap_a.c				\
				swap_b.c				\
				swap_swap.c				\
				push_a.c				\
				push_b.c				\
				rotate_a.c				\
				rotate_b.c				\
				rotate_rotate.c			\
				rev_rotate_a.c			\
				rev_rotate_b.c			\
				rev_rotate_rotate.c		\
				init_stacks.c			\
				read_input.c			\

PUSH_SWAP_SRC = ps_main.c				\
				ps_brute_force.c		\
				ps_try_solution.c		\
				ps_position_sort.c		\
				ps_insertion_sort.c		\
				ps_chunk_sort.c			\
				ps_instruct.c			\
				ps_get_k.c				\
				error.c					\
				print_state.c			\
				swap_a.c				\
				swap_b.c				\
				swap_swap.c				\
				push_a.c				\
				push_b.c				\
				rotate_a.c				\
				rotate_b.c				\
				rotate_rotate.c			\
				rev_rotate_a.c			\
				rev_rotate_b.c			\
				rev_rotate_rotate.c		\
				init_stacks.c			\
				read_input.c			\
				check_sort.c			\
				check_rev_sort.c		\
				check_solved.c			\
				copy_stacks.c			\
				reset_stacks.c			\

CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)

SRCDIR = srcs
CHECKER_OBJDIR = checker_objs
PUSH_SWAP_OBJDIR = push_swap_objs

CHECKER_SRCS = $(addprefix $(SRCDIR)/, $(CHECKER_SRC))
CHECKER_OBJS = $(addprefix $(CHECKER_OBJDIR)/, $(CHECKER_OBJ))
CHECKER_NAME = checker

PUSH_SWAP_SRCS = $(addprefix $(SRCDIR)/, $(PUSH_SWAP_SRC))
PUSH_SWAP_OBJS = $(addprefix $(PUSH_SWAP_OBJDIR)/, $(PUSH_SWAP_OBJ))
PUSH_SWAP_NAME = push_swap

HEADER = -I includes/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -L libft/ -lft

all: $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(CHECKER_OBJS)
	$(CC) -o $(CHECKER_NAME) $(CFLAGS) $(CHECKER_OBJS) $(HEADER) $(LIBS)

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJS)
	$(CC) -o $(PUSH_SWAP_NAME) $(CFLAGS) $(PUSH_SWAP_OBJS) $(HEADER) $(LIBS)

$(CHECKER_OBJS): $(CHECKER_SRCS)
	/bin/mkdir -p $(CHECKER_OBJDIR) ;
	make -C libft/
	$(CC) -c $(CFLAGS) $(CHECKER_SRCS) $(HEADER)
	/bin/mv $(CHECKER_OBJ) $(CHECKER_OBJDIR)/

$(PUSH_SWAP_OBJS): $(PUSH_SWAP_SRCS)
	/bin/mkdir -p $(PUSH_SWAP_OBJDIR) ;
	make -C libft/
	$(CC) -c $(CFLAGS) $(PUSH_SWAP_SRCS) $(HEADER)
	/bin/mv $(PUSH_SWAP_OBJ) $(PUSH_SWAP_OBJDIR)/

clean:
	/bin/rm -Rf $(CHECKER_OBJDIR)
	/bin/rm -Rf $(PUSH_SWAP_OBJDIR)

fclean: clean
	/bin/rm -f $(CHECKER_NAME)
	/bin/rm -f $(PUSH_SWAP_NAME)

re: fclean all

relib:
	make re -C libft/

cleanse: fclean
	make fclean -C libft/
