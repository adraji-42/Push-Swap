/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 08:09:03 by adraji            #+#    #+#             */
/*   Updated: 2025/12/25 11:41:56 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_push(t_stack *src, t_stack *dest)
{
	t_node	*node_to_push;

	if (!src || !src->top)
		return ;
	node_to_push = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	node_to_push->next = dest->top;
	if (dest->top)
		dest->top->prev = node_to_push;
	dest->top = node_to_push;
	dest->top->prev = NULL;
	src->size--;
	dest->size++;
	ft_set_stack_indices(src->top);
	ft_set_stack_indices(dest->top);
	ft_calculate_node_distances(src);
	ft_calculate_node_distances(dest);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	ft_push(b, a);
	ft_printf("pa\n");
}

void	ft_pb(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	ft_printf("pb\n");
}
