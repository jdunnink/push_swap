/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 08:04:23 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/12 08:06:02 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error(int error_code)
{
	if (error_code == 1)
		ft_putendl("Error 1: no argument provided");
	else if (error_code == 2)
		ft_putendl("Error 2: could not allocated memory for new stacks");
	else if (error_code == 3)
		ft_putendl("Error 3: invalid number found --> check your input.");
	else if (error_code == 4)
		ft_putendl("Error 4: input number exceeds integer bounds.");
	else if (error_code == 5)
		ft_putendl("Error 5: input list contains duplicates.");
	else if (error_code == 6)
		ft_putendl("Error 6: invalid instruction encountered.");
	exit(0);
}
