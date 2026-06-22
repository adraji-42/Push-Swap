/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:15:24 by adraji            #+#    #+#             */
/*   Updated: 2025/12/25 11:41:56 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	stack->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_set_stack_indices(stack->top);
	ft_calculate_node_distances(stack);
}

void	ft_ra(t_stack *a)
{
	ft_rotate(a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack *b)
{
	ft_rotate(b);
	ft_printf("rb\n");
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
