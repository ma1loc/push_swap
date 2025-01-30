#include "push_swap.h"

int	get_min_index(t_stack *stack)
{
	t_list	*node;
	int		min_index;

	node = stack->head;
	if (!node)
		return (0);
	min_index = node->index;
	while (node)
	{
		if (node->index < min_index)
			min_index = node->index;
		node = node->next;
	}
	return (min_index);
}

int	get_max_index(t_stack *stack)
{
	t_list	*node;
	int		max_index;

	node = stack->head;
	if (!node)
		return (0);
	max_index = node->index;
	while (node)
	{
		if (node->index > max_index)
			max_index = node->index;
		node = node->next;
	}
	return (max_index);
}
