/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:23:57 by adraji            #+#    #+#             */
/*   Updated: 2025/12/30 15:14:19 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort_utils.h"

void	ft_apply_moves(t_stack *a, t_stack *b, t_op op)
{
	while (op.rrr-- > 0)
		ft_rrr(a, b);
	while (op.rr-- > 0)
		ft_rr(a, b);
	while (op.rra-- > 0)
		ft_rra(a);
	while (op.rrb-- > 0)
		ft_rrb(b);
	while (op.ra-- > 0)
		ft_ra(a);
	while (op.rb-- > 0)
		ft_rb(b);
}

t_node	*ft_find_max_rank(t_stack *stack)
{
	t_node	*max_node;
	t_node	*current;

	if (!stack || !stack->top)
		return (NULL);
	max_node = stack->top;
	current = stack->top->next;
	while (current)
	{
		if (current->rank > max_node->rank)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_node	*ft_find_min_rank(t_stack *stack)
{
	t_node	*min_node;
	t_node	*current;

	if (!stack || !stack->top)
		return (NULL);
	min_node = stack->top;
	current = stack->top->next;
	while (current)
	{
		if (current->rank < min_node->rank)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}
