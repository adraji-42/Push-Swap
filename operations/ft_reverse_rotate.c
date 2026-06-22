/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 11:59:56 by adraji            #+#    #+#             */
/*   Updated: 2025/12/25 11:41:56 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_reverse_rotate(t_stack *stack)
{
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = stack->top;
	last->prev = NULL;
	stack->top->prev = last;
	stack->top = last;
	ft_set_stack_indices(stack->top);
	ft_calculate_node_distances(stack);
}

void	ft_rra(t_stack *a)
{
	ft_reverse_rotate(a);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack *b)
{
	ft_reverse_rotate(b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_printf("rrr\n");
}
