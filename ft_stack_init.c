/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:06:10 by adraji            #+#    #+#             */
/*   Updated: 2025/12/26 12:18:19 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_node	*ft_create_node(int value)
{
	t_node	*new_node;

	new_node = ft_safe_malloc(sizeof(t_node));
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->value = value;
	new_node->target_dist = 1000;
	new_node->pos = -1;
	new_node->rank = -1;
	return (new_node);
}

void	ft_stack_push_node(t_stack *stack, t_node *new_node)
{
	if (!new_node)
		return ;
	if (!stack->top)
	{
		stack->top = new_node;
		return ;
	}
	new_node->next = stack->top;
	stack->top->prev = new_node;
	stack->top = new_node;
}

t_stack	*ft_init_stack_from_array(t_array *array)
{
	t_stack	*stack;
	int		idx;

	stack = ft_safe_malloc(sizeof(t_stack));
	stack->size = 0;
	stack->top = NULL;
	if (!array)
		return (stack);
	idx = array->size - 1;
	while (idx >= 0)
	{
		ft_stack_push_node(stack, ft_create_node(array->values[idx]));
		stack->size++;
		idx--;
	}
	ft_set_stack_indices(stack->top);
	ft_set_value_ranks(stack->top, array);
	ft_calculate_node_distances(stack);
	return (stack);
}
