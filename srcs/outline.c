
/*
determine the current state:
-	currently pushing down into list b

	if (elements in list a >= 3)
	{
		- three elements within reach with one instruction.
		if (is_lowest == last)
		{
			-rev_rotate
			if (list->b->last > list->b->first)
				- rev_rotate-both
			else
				- rev_rotate-a
		}
		else if (is_lowest == current)
		{
			-push
		}
		else if (is_lowest == next)
		{
			-swap or rotate
			if (current < next-next)
			{
				- swap-a or swap-swap
				if (list->b->first < list->b->next)
					swap-swap
				else
					swap-a
			}
			else
			{
				- rotate-a or rotate_rotate
				if (list->b->first < list->b->last)
					-rotate-rotate
				else
					-rotate-a
			}
		}
	}
	if (elements in list a == 2)
	{
		- two elements within reach with one instruction.
		if (is_lowest == current)
			- push
		else
		{
			- swap / rotate or rev_rotate
			if (is_highest(list-b->last))
				rev_rotate-both
			else if (is_highest == list-b-current)
				swap-a
			else if (is_highest == list-b->next)
				swap-swap
		}
	}
	if (elements in list a == 1)
		- end push-down phase

-	currently pushing up into list a


4 1 7 2 3 5 17 8

next = lowest
{
	- swap
	1 4 7 2 3 5 17 8
	- rotate
	1 7 2 3 5 17 8 4

	swap = better because curr < next-next
}




*/