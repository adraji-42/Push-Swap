/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:06:10 by adraji            #+#    #+#             */
/*   Updated: 2025/12/28 13:34:53 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

t_cnode	*ft_create_cnode(int value)
{
	t_cnode	*new_cnode;

	new_cnode = ft_safe_malloc(sizeof(t_cnode));
	new_cnode->value = value;
	new_cnode->prev = NULL;
	new_cnode->next = NULL;
	return (new_cnode);
}

void	ft_stack_push_cnode(t_stack *stack, t_cnode *new_cnode)
{
	if (!new_cnode)
		return ;
	if (!stack->top)
	{
		stack->top = new_cnode;
		return ;
	}
	new_cnode->next = stack->top;
	stack->top->prev = new_cnode;
	stack->top = new_cnode;
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
		ft_stack_push_cnode(stack, ft_create_cnode(array->values[idx]));
		stack->size++;
		idx--;
	}
	return (stack);
}
