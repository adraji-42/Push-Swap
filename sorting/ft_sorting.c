/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:23:12 by adraji            #+#    #+#             */
/*   Updated: 2025/12/30 12:01:56 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort_utils.h"

static void	ft_sort_three(t_stack *a)
{
	t_node	*max_node;

	max_node = ft_find_max_rank(a);
	if (a->top == max_node)
		ft_ra(a);
	else if (a->top->next == max_node)
		ft_rra(a);
	if (a->top->rank > a->top->next->rank)
		ft_sa(a);
}

static void	ft_final_alignment(t_stack *a)
{
	t_node	*min_node;

	min_node = ft_find_min_rank(a);
	while (a->top != min_node)
	{
		if (min_node->target_dist > 0)
			ft_ra(a);
		else
			ft_rra(a);
	}
}

static void	ft_push_min_to_b(t_stack *a, t_stack *b, t_node *min)
{
	if (min->target_dist < 0)
		while (min->pos)
			ft_rra(a);
	else
		while (min->pos)
			ft_ra(a);
	ft_pb(a, b);
}

static void	ft_sort_small(t_stack *a, t_stack *b)
{
	int initial_size;

	initial_size = a->size;
	while (a->size > 3)
		ft_push_min_to_b(a, b, ft_find_min_rank(a));
	ft_sort_three(a);
	while (a->size < initial_size)
		ft_pa(a, b);
}

void	ft_sorting(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		ft_sort_small(a, b);
	ft_pb(a, b);
	ft_pb(a, b);
	while (a->size > 5)
	{
		ft_apply_moves(a, b, ft_prepare_push_b(a, b));
		ft_pb(a, b);
	}
	ft_sort_small(a, b);
	while (b->size)
	{
		ft_prepare_push_a(a, b);
		ft_pa(a, b);
	}
	ft_final_alignment(a);
}
