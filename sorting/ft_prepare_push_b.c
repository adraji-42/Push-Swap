/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_push_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 06:47:01 by adraji            #+#    #+#             */
/*   Updated: 2025/12/29 10:54:48 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort_utils.h"

static t_node	*ft_get_target_in_b(t_node *node_a, t_stack *b)
{
	t_node	*target;
	int		best_rank;
	t_node	*curr;

	target = NULL;
	best_rank = -1;
	curr = b->top;
	while (curr)
	{
		if (curr->rank < node_a->rank && curr->rank > best_rank)
		{
			best_rank = curr->rank;
			target = curr;
		}
		curr = curr->next;
	}
	if (!target)
		return (ft_find_max_rank(b));
	return (target);
}

static void	ft_calculate_shared(t_op *op, int dist_a, int dist_b)
{
	if (dist_a > 0 && dist_b > 0)
	{
		op->rr = dist_b;
		if (dist_a < dist_b)
			op->rr = dist_a;
		op->ra = dist_a - op->rr;
		op->rb = dist_b - op->rr;
	}
	else if (dist_a < 0 && dist_b < 0)
	{
		op->rrr = -dist_b;
		if (-dist_a < -dist_b)
			op->rrr = -dist_a;
		op->rra = (-dist_a) - op->rrr;
		op->rrb = (-dist_b) - op->rrr;
	}
}

static t_op	ft_get_operations(t_node *node_a, t_stack *b)
{
	t_op	op;
	t_node	*target;
	int		d_a;
	int		d_b;

	ft_memset(&op, 0, sizeof(t_op));
	target = ft_get_target_in_b(node_a, b);
	d_a = node_a->target_dist;
	d_b = target->target_dist;
	if ((d_a > 0 && d_b > 0) || (d_a < 0 && d_b < 0))
		ft_calculate_shared(&op, d_a, d_b);
	else
	{
		if (d_a > 0)
			op.ra = d_a;
		else
			op.rra = -d_a;
		if (d_b > 0)
			op.rb = d_b;
		else
			op.rrb = -d_b;
	}
	op.cost = op.ra + op.rb + op.rr + op.rra + op.rrb + op.rrr;
	return (op);
}

t_op	ft_prepare_push_b(t_stack *a, t_stack *b)
{
	t_op	op;
	t_op	best;
	t_node	*curr;

	best.cost = INT_MAX;
	curr = a->top;
	while (curr)
	{
		op = ft_get_operations(curr, b);
		if (op.cost < best.cost)
			best = op;
		curr = curr->next;
	}
	return (best);
}
