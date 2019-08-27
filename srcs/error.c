/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 08:04:23 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/15 15:02:08 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error(int error_code)
{
	if (error_code == 1)
		ft_putendl("Error");
	else if (error_code == 2)
		ft_putendl("Error 2: could not allocated memory for new stacks");
	else if (error_code == 3)
		ft_putendl("Error");
	else if (error_code == 4)
		ft_putendl("Error");
	else if (error_code == 5)
		ft_putendl("Error");
	else if (error_code == 6)
		ft_putendl("Error");
	else if (error_code == 7)
		ft_putendl("Error 7: could not allocate memory for list node.");
	exit(0);
}
