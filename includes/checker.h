/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/19 12:32:01 by jdunnink       #+#    #+#                */
/*   Updated: 2019/07/22 18:09:31 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "shared.h"


#include <stdio.h>			// REMOVE THIS INCLUDE

//	ADD REQUIRED C FLAGS TO MAKEFILE

void			error(int error_code);
void			init_stacks(t_stacks **stacks);
void			read_input(int argc, char **argv, t_stacks **stacks);
void			get_instr(t_stacks **stacks);


#endif
