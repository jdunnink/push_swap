/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_update_distances.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 16:15:43 by jdunnink       #+#    #+#                */
/*   Updated: 2019/08/14 17:03:55 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_distances(t_list **distances, t_list *src, t_list *dest, char c)
{
	get_distance_list(distances, src);
	get_dest_distances(distances, dest, c);
	set_paths(distances);
}
