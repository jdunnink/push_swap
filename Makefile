# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jdunnink <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/20 09:33:47 by jdunnink       #+#    #+#                 #
#    Updated: 2019/07/22 18:16:12 by jdunnink      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CHECKER_SRC =	ch_main.c				\
				ch_init_stacks.c		\
				ch_read_input.c			\
				ch_error.c				\
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

CHECKER_OBJ = $(CHECKER_SRC:.c=.o)


SRCDIR = srcs
CHECKER_OBJDIR = checker_objs

CHECKER_SRCS = $(addprefix $(SRCDIR)/, $(CHECKER_SRC))
CHECKER_OBJS = $(addprefix $(CHECKER_OBJDIR)/, $(CHECKER_OBJ))
CHECKER_NAME = checker





HEADER = -I includes/
CC = gcc
CFLAGS =
LIBS = -L libft/ -lft





all: $(CHECKER_NAME)

$(CHECKER_NAME): $(CHECKER_OBJS)
	$(CC) -o $(CHECKER_NAME) $(CFLAGS) $(CHECKER_OBJS) $(HEADER) $(LIBS)

$(CHECKER_OBJS): $(CHECKER_SRCS)
	/bin/mkdir -p $(CHECKER_OBJDIR) ;
	make -C libft/
	$(CC) -c $(CFLAGS) $(CHECKER_SRCS) $(HEADER)
	/bin/mv $(CHECKER_OBJ) $(CHECKER_OBJDIR)/

clean:
	/bin/rm -Rf $(CHECKER_OBJDIR)

fclean: clean
	/bin/rm -f $(CHECKER_NAME)

re: fclean all

relib:
	make re -C libft/

cleanse: fclean
	make fclean -C libft/
