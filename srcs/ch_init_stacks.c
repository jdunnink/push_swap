
#include "checker.h"

void	init_stacks(t_stacks **stacks)
{
	*stacks = NULL;
	*stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!(*stacks))
		error(2);
	(*stacks)->a = NULL;
	(*stacks)->b = NULL;
}