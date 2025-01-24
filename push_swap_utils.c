#include "push_swap.h"

t_list	*ft_lst_new(int value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_lst_add_back(t_stack *stack, int value)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = ft_lst_new(value);
	if (!new_node)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	if (!stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		last_node = ft_last_node(stack->head);
		last_node->next = new_node;
		new_node->prev = last_node;
		stack->tail = new_node;
	}
	stack->size++;
}

int	is_sorted(t_stack *stack)
{
	t_list	*header;

	header = stack->head;
	if (!header || !header->next)
		return (1);
	while (header->next)
	{
		if (header->value > header->next->value)
			return (0);
		header = header->next;
	}
	return (1);
}

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;

	return (stack);
}

t_list	*ft_last_node(t_list *header)
{
	if (!header)
		return (NULL);
	while (header->next)
		header = header->next;
	return (header);
}
