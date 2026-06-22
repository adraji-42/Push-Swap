/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_push_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 06:49:21 by adraji            #+#    #+#             */
/*   Updated: 2025/12/29 10:54:48 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort_utils.h"

static t_node	*ft_get_target_in_a(t_node *node_b, t_stack *a)
{
	t_node	*target;
	int		best_rank;
	t_node	*curr_a;

	target = NULL;
	best_rank = INT_MAX;
	curr_a = a->top;
	while (curr_a)
	{
		if (curr_a->rank > node_b->rank && curr_a->rank < best_rank)
		{
			best_rank = curr_a->rank;
			target = curr_a;
		}
		curr_a = curr_a->next;
	}
	if (!target)
		target = ft_find_min_rank(a);
	return (target);
}

void	ft_prepare_push_a(t_stack *a, t_stack *b)
{
	t_node	*target;

	if (!b || !b->top)
		return ;
	target = ft_get_target_in_a(b->top, a);
	if (!target)
		return ;
	while (a->top != target)
	{
		if (target->target_dist > 0)
			ft_ra(a);
		else
			ft_rra(a);
	}
}
